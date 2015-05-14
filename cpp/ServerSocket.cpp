//
//  ServerSocket.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "ServerSocket.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "IOException.h"

protobuf::socketrpc::ServerSocket::ServerSocket(int port) {
    address = new sockaddr_in();
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0)
        throw  IOException("Failed to open server socket");
    
    bzero((char *)address, sizeof(*address));
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(port);
    if (bind(sd, (struct sockaddr *)address, sizeof(*address)) < 0)
        throw IOException("Failed to bind server socket");
    
    listen(sd, 5); // max 5 clients
}

protobuf::socketrpc::Socket* protobuf::socketrpc::ServerSocket::accept()
{
    struct sockaddr_in *cli_addr = new sockaddr_in();
    socklen_t clilen = sizeof(*cli_addr);
    int cli_sd = ::accept(sd, (struct sockaddr *)cli_addr, &clilen);
    
    if (cli_sd < 0)
        throw IOException("Failed to accept socket connection");
    
    return new Socket(cli_sd, cli_addr);
}
