//
//  RpcServer.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__RpcServer__
#define __ProtobufSocketRpcCpp__RpcServer__

#include <stdio.h>
#include "RpcForwarder.h"
#include "ServerRpcConnectionFactory.h"
#include <google/protobuf/service.h>
#include <thread>

namespace protobuf {
    namespace socketrpc {
        
        class RpcServer {
            
        public:
            RpcServer(ServerRpcConnectionFactory *rpcConnectionFactory, bool closeConnectionAfterInvokingService);
            ~RpcServer();
            
            void registerService(google::protobuf::Service *service);
            void startServer();
            void shutDown();
            
            bool isRunning();
            
            // TODO : make private with friend access to ConnectionHandler
            bool waitForCallback;
            RpcForwarder *rpcForwarder;
            
        private:
            ServerRpcConnectionFactory *rpcConnectionFactory;
            
            std::thread *serverThread; // listener thread
            volatile bool running;
            volatile bool shouldExit;
            void run();
        };
    }
}

#endif /* defined(__ProtobufSocketRpcCpp__RpcServer__) */
