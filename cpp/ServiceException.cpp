//
//  ServerException.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 12.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "ServiceException.h"

protobuf::socketrpc::ServiceException::ServiceException(std::string message) {
    this->_message = message;
}

const char* protobuf::socketrpc::ServiceException::what() const throw()
{
    return _message.c_str();
}

protobuf::socketrpc::RpcServiceException::RpcServiceException(std::string message, ErrorReason reason) : ServiceException(message) {
    this->_reason = reason;
}

protobuf::socketrpc::ErrorReason protobuf::socketrpc::RpcServiceException::reason() {
    return _reason;
}


