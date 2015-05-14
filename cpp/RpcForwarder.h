//
//  RpcForwarder.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__RpcForwarder__
#define __ProtobufSocketRpcCpp__RpcForwarder__

#include <stdio.h>
#include <map>
#include <google/protobuf/service.h>
#include "rpc.pb.h"
#include "SocketRpcController.h"

namespace protobuf {
    namespace socketrpc {
        
        class RpcForwarder {
            
        public:
            void registerService(google::protobuf::Service *service);
            void doRpc(Request *rpcRequest, Response *rpcResponse, google::protobuf::Closure *callback);
            
        private:
            std::map<std::string, google::protobuf::Service*> serviceMap;
            
            google::protobuf::Message* forwardToService(Request *rpcRequest, google::protobuf::Closure *callback,
                                  google::protobuf::Service *service, SocketRpcController *controller);
            
            const google::protobuf::MethodDescriptor* getMethod(
                                Request *rpcRequest, const google::protobuf::ServiceDescriptor *serviceDescriptor);
            
            google::protobuf::Message* getRequestProto(Request *rpcRequest, const google::protobuf::Message &prototype);
            void ignoredCallback();
        };
        
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__RpcForwarder__) */
