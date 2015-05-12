//
//  SocketConnection.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "SocketConnection.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

#include "IOException.h"

// 10 Kb
#define BUFFER_SIZE 10 * 1024

protobuf::socketrpc::SocketConnection::SocketConnection(Socket *socket, bool delimited) {
    this->socket = socket;
    this->delimited = delimited;
    
    buffer = new char[BUFFER_SIZE];
}

protobuf::socketrpc::SocketConnection::~SocketConnection() {
    if (!socket->isClosed())
        socket->close();
    
    delete socket;
    delete buffer;
}

void protobuf::socketrpc::SocketConnection::sendProtoMessage(google::protobuf::Message *message) {
    if (delimited) {
        google::protobuf::io::ArrayOutputStream arrayOutput(buffer, BUFFER_SIZE);
        google::protobuf::io::CodedOutputStream codedOutput(&arrayOutput);
        int messageSize = message->ByteSize();
        if (messageSize <= 0xff) {
            // 1 byte
            char byte = messageSize;
            codedOutput.WriteRaw(&byte, 1);
        } else {
            // 4 bytes
            codedOutput.WriteLittleEndian32(messageSize);
        }
        message->SerializeToCodedStream(&codedOutput);
        
        // get coded buffer
        void *coded_buffer;
        int unwritten_size;
        bool got_direct_buffer = codedOutput.GetDirectBufferPointer(&coded_buffer, &unwritten_size);
        int coded_size = BUFFER_SIZE - unwritten_size;
        socket->write(buffer, coded_size);
        return;
    } else {
        message->SerializeToFileDescriptor(socket->getFileDescriptor());
        /*
        std::string outputString;
        message->SerializeToString(&outputString);
        socket->write(outputString.c_str(), outputString.length());
         */
    }
}

void protobuf::socketrpc::SocketConnection::receiveProtoMessage(google::protobuf::Message *message) {
    if (delimited) {
        // read message size
        int messageSize;
        char bytes[4];
        socket->read(&bytes, 1);
        
        if ((bytes[0] & 0x80) == 0) {
            messageSize = bytes[0];
        } else {
            // read more (4 bytes)
            messageSize = bytes[0] & 0x7f;
            int offset = 7;
            int byte_index = 0;
            for (; offset < 32; offset += 7) {
                socket->read(&bytes[++byte_index], 1);
                char b = (bytes[byte_index] & 0x7f);
                messageSize |= (b << offset);
                if ((b & 0x80) == 0) {
                    break;
                }
            }
        }
    
        // read message
        socket->read(buffer, messageSize);
        
        try {
            google::protobuf::io::ArrayInputStream arrayInputStream(buffer, messageSize);
            google::protobuf::io::CodedInputStream codedInputStream(&arrayInputStream);
            message->MergeFromCodedStream(&codedInputStream);
        } catch (...) {
            throw IOException();
        }
    } else {
        // TODO : implement
    }
}

void protobuf::socketrpc::SocketConnection::close() {
    socket->close();
    
}

bool protobuf::socketrpc::SocketConnection::isClosed() const {
    return socket->isClosed();
}