//
//  RpcServer.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "RpcServer.h"
#include <unistd.h>
#include "ConnectionHandler.h"
#include "IOException.h"

protobuf::socketrpc::RpcServer::RpcServer(
                    ServerRpcConnectionFactory *rpcConnectionFactory, bool closeConnectionAfterInvokingService)
{
    rpcForwarder = new RpcForwarder();
    this->rpcConnectionFactory = rpcConnectionFactory;
    this->waitForCallback = !closeConnectionAfterInvokingService;
}

protobuf::socketrpc::RpcServer::~RpcServer()
{
    delete rpcForwarder;
}

void protobuf::socketrpc::RpcServer::registerService(google::protobuf::Service *service)
{
    rpcForwarder->registerService(service);
}

void protobuf::socketrpc::RpcServer::startServer() {
    shouldExit = false;
    serverThread = new std::thread(&RpcServer::run, this);
}

bool protobuf::socketrpc::RpcServer::isRunning()
{
    return running;
}

void protobuf::socketrpc::RpcServer::run()
{
    running = true;
    
    try {
        
      while (!shouldExit) {
         // blocks until client is connected
         Connection *connection = rpcConnectionFactory->createConnection();
         if (!shouldExit) {
            if (connection->isClosed()) {
                sleep(0.1);
            } else {
                // handle connection
                ConnectionHandler *handler = new ConnectionHandler(this, connection); // TODO : what to do with pointer?
            }
        }
      }
        
    } catch (IOException &e) {
        shutDown();
    }
}

void protobuf::socketrpc::RpcServer::shutDown() {
    if (running) {
        running = false;
        shouldExit = true; // signal thread to exit;
    
        try {
            rpcConnectionFactory->close();
        } catch (...) {
            // nothing
        }
    }
}
