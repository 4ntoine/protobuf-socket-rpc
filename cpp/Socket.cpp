//
//  Socket.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "Socket.h"
#include "IOException.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

protobuf::socketrpc::Socket::Socket(std::string host, int port)
{
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(host.c_str());
    address.sin_port = htons(port);
    
    this->sd = socket(AF_INET, SOCK_STREAM, 0);
    if (::connect(sd, (struct sockaddr*)&address, sizeof(address)) != 0) {
        throw IOException("Connection refused");
    }
}

int protobuf::socketrpc::Socket::write(const void *buffer, int size) {
    int writeResult = (int)::write(sd, buffer, size);
    if (writeResult < 0) {
        // error, need to close the socket
        this->close();
        
        throw IOException("Failed to write to socket");
    }
    return writeResult;
}

int protobuf::socketrpc::Socket::read(void *buffer, int size) {
    int readResult = (int)::read(sd, buffer, size);
    if (readResult < 0) {
        // error, need to close the socket
        this->close();
        
        throw IOException("Failed to read from socket");
    }
        
    return readResult;
}

bool protobuf::socketrpc::Socket::isClosed() const {
    return sd > -1;
}

void protobuf::socketrpc::Socket::close() {
    ::close(sd);
    sd = -1;
}

int protobuf::socketrpc::Socket::getFileDescriptor() const {
    return sd;
}
