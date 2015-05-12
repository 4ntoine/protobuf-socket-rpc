//
//  IOException.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 12.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "IOException.h"

protobuf::socketrpc::IOException::IOException() {
    
}

protobuf::socketrpc::IOException::IOException(std::string message) {
    this->_message = message;
}

const char* protobuf::socketrpc::IOException::what() const throw()
{
    return this->_message != "" ? _message.c_str() : std::exception::what();
}


