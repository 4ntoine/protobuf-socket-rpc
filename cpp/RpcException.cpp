//
//  RpcException.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "RpcException.h"

protobuf::socketrpc::RpcException::RpcException(ErrorReason reason, std::string message)
{
    this->_reason = reason;
    this->_message = message;
}

const char* protobuf::socketrpc::RpcException::what() const throw()
{
    return _message.c_str();
}

protobuf::socketrpc::ErrorReason protobuf::socketrpc::RpcException::reason()
{
    return _reason;
}
