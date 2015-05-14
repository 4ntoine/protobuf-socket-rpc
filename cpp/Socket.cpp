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

protobuf::socketrpc::Socket::~Socket() {
    if (!isClosed())
        close();
    
    // TODO : fix
    
    /*
    if (address != NULL) {
        delete address;
        address = NULL;
    }
     */
}

protobuf::socketrpc::Socket::Socket() {
    // nothing
}

protobuf::socketrpc::Socket::Socket(int sd, struct sockaddr_in* address)
{
    this->sd = sd;
    this->address = address;
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
    return sd < 0;
}

void protobuf::socketrpc::Socket::close() {
    ::close(sd);
    sd = -1;
}

int protobuf::socketrpc::Socket::getFileDescriptor() const {
    return sd;
}
