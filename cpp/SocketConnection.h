//
//  SocketConnection.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__SocketConnection__
#define __ProtobufSocketRpcCpp__SocketConnection__

#include <stdio.h>
#include "Socket.h"
#include "RpcConnectionFactory.h"
#include <google/protobuf/message.h>

namespace protobuf {
    namespace socketrpc {
        
        class SocketConnection : public Connection {
            
        public:
            SocketConnection(Socket *socket, bool delimited);
            virtual ~SocketConnection();
            
            virtual void sendProtoMessage(google::protobuf::Message *message);
            virtual void receiveProtoMessage(google::protobuf::Message *message);
            virtual void close();
            virtual bool isClosed() const;
            
        private:
            Socket *socket;
            bool delimited;
            char *buffer;
        };
        
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__SocketConnection__) */
