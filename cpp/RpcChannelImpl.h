//
//  RpcChannelImpl.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 08.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__RpcChannelImpl__
#define __ProtobufSocketRpcCpp__RpcChannelImpl__

#include <stdio.h>
#include <google/protobuf/service.h>
#include "RpcConnectionFactory.h"
#include "SocketRpcController.h"

namespace protobuf {
    namespace socketrpc {
        
        class RpcChannelImpl : public google::protobuf::RpcChannel {
            
        public:
            RpcChannelImpl(RpcConnectionFactory *connectionFactory);
            
            
            virtual void CallMethod(const google::protobuf::MethodDescriptor* method,
                                    google::protobuf::RpcController* controller,
                                    const google::protobuf::Message* request,
                                    google::protobuf::Message* response,
                                    google::protobuf::Closure* done);
            
        private:
            RpcConnectionFactory *connectionFactory;
            
            Connection *createConnection(SocketRpcController *controller);
            void sendRpcRequest(const google::protobuf::MethodDescriptor* method,
                                SocketRpcController *socketController,
                                const google::protobuf::Message* request,
                                Connection *connection);
            
            protobuf::socketrpc::Response *receiveRpcResponse(
                                SocketRpcController *socketController, Connection* connection);
            
            google::protobuf::Message* handleRpcResponse(
                                                      google::protobuf::Message*responsePrototype,
                                                      Response *rpcResponse,
                                                      SocketRpcController *socketController);
            
            void handleError(SocketRpcController *controller, ErrorReason reason, std::string message);
        };
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__RpcChannelImpl__) */
