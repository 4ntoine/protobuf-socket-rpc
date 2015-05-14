//
//  SocketServerRpcConnectionFactory.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "SocketServerRpcConnectionFactory.h"
#include "SocketConnection.h"

protobuf::socketrpc::SocketServerRpcConnectionFactory::SocketServerRpcConnectionFactory(int port, bool delimited)
{
    this->port = port;
    this->delimited = delimited;
    this->serverSocket = NULL;
}

protobuf::socketrpc::ServerSocket* protobuf::socketrpc::SocketServerRpcConnectionFactory::initServerSocket()
{
    ServerSocket *local = serverSocket;
    if (local == NULL) {
        serverSocket = new ServerSocket(port);
        local = serverSocket;
    }
    return local;
}


protobuf::socketrpc::Connection* protobuf::socketrpc::SocketServerRpcConnectionFactory::createConnection()
{
    ServerSocket *local = serverSocket;
    if (local == NULL)
        local = initServerSocket();
    
    return new SocketConnection(serverSocket->accept(), delimited);
}

void protobuf::socketrpc::SocketServerRpcConnectionFactory::close() {
    ServerSocket *local = serverSocket;
    if (local != NULL) {
        if (!local->isClosed())
            local->close();
        
        delete local;
        local = NULL;
        serverSocket = NULL;
    }
}
