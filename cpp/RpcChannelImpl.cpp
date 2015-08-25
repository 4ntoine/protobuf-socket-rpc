//
//  RpcChannelImpl.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 08.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "RpcChannelImpl.h"
#include "SocketConnection.h"

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

#include "IOException.h"
#include "ServiceException.h"

protobuf::socketrpc::RpcChannelImpl::RpcChannelImpl(RpcConnectionFactory *connectionFactory) {
    this->connectionFactory = connectionFactory;
}

void protobuf::socketrpc::RpcChannelImpl::handleError(protobuf::socketrpc::SocketRpcController *controller, ErrorReason reason, std::string message) {
    controller->SetFailed(message, reason);
    throw RpcServiceException(message, reason);
}

protobuf::socketrpc::Connection* protobuf::socketrpc::RpcChannelImpl::createConnection(protobuf::socketrpc::SocketRpcController *controller) {
    try {
        return connectionFactory->createConnection();
    } catch (IOException &e) {
        handleError(controller, ErrorReason::IO_ERROR, "Error creating connection");
        return NULL;
    }
}

void protobuf::socketrpc::RpcChannelImpl::sendRpcRequest(const google::protobuf::MethodDescriptor* method,
                    protobuf::socketrpc::SocketRpcController *socketController,
                    const google::protobuf::Message* request,
                    protobuf::socketrpc::Connection *connection) {
    
    if (!request->IsInitialized()) {
        socketController->SetFailed("Request is uninitialized", INVALID_REQUEST_PROTO);
        return;
    }
    
    protobuf::socketrpc::Request *rpcRequest = new protobuf::socketrpc::Request();
    rpcRequest->set_request_proto(request->SerializeAsString());
    rpcRequest->set_service_name(method->service()->full_name());
    rpcRequest->set_method_name(method->name());
    
    connection->sendProtoMessage(rpcRequest);
    
    delete rpcRequest;
}

protobuf::socketrpc::Response* protobuf::socketrpc::RpcChannelImpl::receiveRpcResponse(
                                                  protobuf::socketrpc::SocketRpcController *socketController,
                                                  protobuf::socketrpc::Connection* connection)
{
    protobuf::socketrpc::Response *response = new protobuf::socketrpc::Response();
    try {
        connection->receiveProtoMessage(response);
    } catch (IOException &e) {
        handleError(socketController, ErrorReason::IO_ERROR, "Error reading over connection");
    }
    
    if (!response->IsInitialized()) {
        handleError(socketController, ErrorReason::BAD_RESPONSE_PROTO, "Bad response from server");
    }
    
    return response;
}

google::protobuf::Message* protobuf::socketrpc::RpcChannelImpl::handleRpcResponse(
                                          google::protobuf::Message *response,
                                          protobuf::socketrpc::Response *rpcResponse,
                                          protobuf::socketrpc::SocketRpcController *socketController)
{    
    if (rpcResponse->has_error()) {
        handleError(socketController, rpcResponse->error_reason(), rpcResponse->error());
        return NULL;
    }
    
    if (!rpcResponse->has_response_proto()) {
        return NULL; // no response
    }
    
    try {
        google::protobuf::io::ArrayInputStream arrayInputStream(rpcResponse->response_proto().c_str(), (int)rpcResponse->response_proto().length());
        google::protobuf::io::CodedInputStream codedInputStream(&arrayInputStream);
        response->MergeFromCodedStream(&codedInputStream);
    } catch (...) {
        handleError(socketController, ErrorReason::BAD_RESPONSE_PROTO, "Response can't be parsed");
        return NULL;
    }
    
    if (!response->IsInitialized()) {
        handleError(socketController, ErrorReason::BAD_RESPONSE_PROTO, "Uninitialized RPC Response Proto");
        return NULL;
    }
    
    return response;
}

void protobuf::socketrpc::RpcChannelImpl::CallMethod(
                const google::protobuf::MethodDescriptor* method,
                google::protobuf::RpcController* controller,
                const google::protobuf::Message* request,
                google::protobuf::Message* response,
                google::protobuf::Closure* done)
{
    SocketRpcController *socketController = (SocketRpcController*)controller;
    Connection *connection = this->createConnection(socketController);
    
    // send request
    this->sendRpcRequest(method, socketController, request, connection);
    
    // receive response
    protobuf::socketrpc::Response *rpcResponse = this->receiveRpcResponse(socketController, connection);
    handleRpcResponse(response, rpcResponse, socketController);
    
    done->Run();
    delete rpcResponse;
    
    connection->close();
    delete connection;
}
