//
//  SocketRpcConnectionFactory.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "SocketRpcConnectionFactory.h"
#include "Socket.h"
#include "SocketConnection.h"
#include "IOException.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <Arpa/inet.h>

protobuf::socketrpc::SocketRpcConnectionFactory::SocketRpcConnectionFactory(std::string host, int port, bool delimited) {
    this->host = host;
    this->port = port;
    this->delimited = delimited;
}

protobuf::socketrpc::Connection* protobuf::socketrpc::SocketRpcConnectionFactory::createConnection() {
    struct sockaddr_in address;
    
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(host.c_str());
    address.sin_port = htons(port);
    
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (::connect(sd, (struct sockaddr*)&address, sizeof(address)) != 0) {
        throw IOException("Connection refused");
    }
    
    Socket *socket = new Socket(sd, &address);
    return new SocketConnection(socket, this->delimited);
}
