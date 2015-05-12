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

protobuf::socketrpc::SocketRpcConnectionFactory::SocketRpcConnectionFactory(std::string host, int port, bool delimited) {
    this->host = host;
    this->port = port;
    this->delimited = delimited;
}

protobuf::socketrpc::Connection* protobuf::socketrpc::SocketRpcConnectionFactory::createConnection() {
    Socket *socket = new Socket(host, port);
    return new SocketConnection(socket, this->delimited);
}
