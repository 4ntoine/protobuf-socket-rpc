//
//  ServerException.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 12.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__ServerException__
#define __ProtobufSocketRpcCpp__ServerException__

#include <stdio.h>
#include <exception>
#include <string>
#include "rpc.pb.h"

namespace protobuf {
    namespace socketrpc {
        
        //
        class ServiceException : public std::exception {
            
        public:
            ServiceException(std::string message);
            
            virtual const char* what() const throw();
            
        private:
            std::string _message;
        };
        
        // advanced 'ServiceException' with 'reason'
        class RpcServiceException : public ServiceException {
            
        public:
            RpcServiceException(std::string message, ErrorReason reason);
            ErrorReason reason();
            
        private:
            ErrorReason _reason;
        };
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__ServerException__) */
