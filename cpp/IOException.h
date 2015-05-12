//
//  IOException.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 12.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__IOException__
#define __ProtobufSocketRpcCpp__IOException__

#include <stdio.h>
#include <exception>
#include <string>

namespace protobuf {
    namespace socketrpc {
        
        class IOException : public std::exception {
            
        public:
            IOException();
            IOException(std::string message);
            
            virtual const char* what() const throw();
            
        private:
            std::string _message;
        };
        
    } // namespace
} // namespace

#endif /* defined(__ProtobufSocketRpcCpp__IOException__) */
