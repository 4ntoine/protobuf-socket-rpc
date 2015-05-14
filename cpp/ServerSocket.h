//
//  ServerSocket.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__ServerSocket__
#define __ProtobufSocketRpcCpp__ServerSocket__

#include <stdio.h>
#include "Socket.h"

namespace protobuf {
    namespace socketrpc {
        
        class ServerSocket : public Socket {
            
        public:
            ServerSocket(int port);
            
            Socket *accept();
        };
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__ServerSocket__) */
