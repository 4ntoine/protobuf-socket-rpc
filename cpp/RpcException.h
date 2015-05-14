//
//  RpcException.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__RpcException__
#define __ProtobufSocketRpcCpp__RpcException__

#include <stdio.h>
#include <string>
#include <exception>
#include "rpc.pb.h"

namespace protobuf {
    namespace socketrpc {
        
        class RpcException : public std::exception {
        
        public:
            RpcException(ErrorReason reason, std::string message);
            
            virtual const char* what() const throw();
            ErrorReason reason();
            
        private:
            ErrorReason _reason;
            std::string _message;

        };
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__RpcException__) */
