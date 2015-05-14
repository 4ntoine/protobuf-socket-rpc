//
//  ServerRpcConnectionFactory.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__ServerRpcConnectionFactory__
#define __ProtobufSocketRpcCpp__ServerRpcConnectionFactory__

#include <stdio.h>
#include "RpcConnectionFactory.h"

namespace protobuf {
    namespace socketrpc {
        
        class ServerRpcConnectionFactory : public RpcConnectionFactory {
            
        public:
            virtual void close() = 0;
            
        };
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__ServerRpcConnectionFactory__) */
