//
//  SocketRpcConnectionFactory.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__SocketRpcConnectionFactory__
#define __ProtobufSocketRpcCpp__SocketRpcConnectionFactory__

#include <stdio.h>
#include <string>
#include "RpcConnectionFactory.h"

namespace protobuf {
    namespace socketrpc {
        
        class SocketRpcConnectionFactory : public RpcConnectionFactory {
            
        public:
            SocketRpcConnectionFactory(std::string host, int port, bool delimited);
            virtual Connection* createConnection();
            
        private:
            std::string host;
            int port;
            bool delimited;
        };
        
    }
}

#endif /* defined(__ProtobufSocketRpcCpp__SocketRpcConnectionFactory__) */
