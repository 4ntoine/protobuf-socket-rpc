//
//  RpcConnectionFactory.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef ProtobufSocketRpcCpp_RpcConnectionFactory_h
#define ProtobufSocketRpcCpp_RpcConnectionFactory_h

#include <google/protobuf/message.h>

namespace protobuf {
    namespace socketrpc {
     
        class Connection {
            
        public:
            virtual void sendProtoMessage(google::protobuf::Message *message) = 0;
            virtual void receiveProtoMessage(google::protobuf::Message *message) = 0;
            virtual void close() = 0;
            virtual bool isClosed() const = 0;
            
            virtual ~Connection() {};
        };
        
        class RpcConnectionFactory {
            
        public:
            virtual Connection* createConnection() = 0;
            
        };
        
    } // namespace
} // namespace

#endif
