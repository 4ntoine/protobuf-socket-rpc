//
//  SocketServerRpcConnectionFactory.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__SocketServerRpcConnectionFactory__
#define __ProtobufSocketRpcCpp__SocketServerRpcConnectionFactory__

#include <stdio.h>
#include "ServerSocket.h"
#include "ServerRpcConnectionFactory.h"

namespace protobuf {
    namespace socketrpc {
        
        class SocketServerRpcConnectionFactory : public ServerRpcConnectionFactory {
            
        public:
            SocketServerRpcConnectionFactory(int port, bool delimited);
            virtual Connection* createConnection();
            void close();
            
        private:
            int port;
            bool delimited;
            
            ServerSocket* initServerSocket();
            ServerSocket* serverSocket;
            
            
        };
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__SocketServerRpcConnectionFactory__) */
