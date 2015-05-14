//
//  ConnectionHandler.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__ConnectionHandler__
#define __ProtobufSocketRpcCpp__ConnectionHandler__

#include <stdio.h>
#include "RpcConnectionFactory.h"
#include <thread>
#include <google/protobuf/message.h>
#include <string>

#include "rpc.pb.h"
#include "service.pb.h"
#include "RpcServer.h"

namespace protobuf {
    namespace socketrpc {
        
        class ConnectionHandler {
            
        public:
            ConnectionHandler(RpcServer *server, Connection* connection);
            ~ConnectionHandler();
            
            void sendResponseCallback();
            
        private:
            
            RpcServer *server;
            void run();
            std::thread *t;
            Connection *connection;
            
            protobuf::socketrpc::Request *request;
            protobuf::socketrpc::Response *response;
            
            void sendResponse(protobuf::socketrpc::Response *rpcResponse);
            void forwardRpc(Request *request);
            protobuf::socketrpc::Response *handleError(std::string msg, ErrorReason reason);
        };
        
    }
}

#endif /* defined(__ProtobufSocketRpcCpp__ConnectionHandler__) */
