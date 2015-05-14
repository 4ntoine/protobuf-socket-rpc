//
//  ConnectionHandler.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "ConnectionHandler.h"
#include "service.pb.h"
#include "IOException.h"
#include "RpcException.h"
#include "RpcServer.h"

protobuf::socketrpc::ConnectionHandler::ConnectionHandler(RpcServer *server_, Connection *connection)
{
    this->server = server_; // friend
    this->connection = connection;
    
    request = new protobuf::socketrpc::Request();
    response = new protobuf::socketrpc::Response();
    
    t = new std::thread(&ConnectionHandler::run, this); // create and run new thread
}

protobuf::socketrpc::ConnectionHandler::~ConnectionHandler()
{
    delete request;
    delete response;
}

void protobuf::socketrpc::ConnectionHandler::run()
{
    connection->receiveProtoMessage(request);
    
    if (!request->IsInitialized()) {
        sendResponse(handleError("Invalid request from client", ErrorReason::BAD_REQUEST_DATA));
        return;
    }
    
    try {
        forwardRpc(request);
    } catch (IOException &e) {
        sendResponse(handleError("Bad request data from client", ErrorReason::BAD_REQUEST_DATA));
    }
}

void protobuf::socketrpc::ConnectionHandler::sendResponseCallback() {
    sendResponse(response);
    connection->close();
}

void protobuf::socketrpc::ConnectionHandler::forwardRpc(protobuf::socketrpc::Request *rpcRequest) {
    // callback
    google::protobuf::Closure *callback = google::protobuf::NewCallback(
                                this,  &protobuf::socketrpc::ConnectionHandler::sendResponseCallback);
    
    try {
        server->rpcForwarder->doRpc(rpcRequest, response, callback);
    } catch (protobuf::socketrpc::RpcException &e) {
        sendResponse(handleError(e.what(), e.reason()));
    }
}

void protobuf::socketrpc::ConnectionHandler::sendResponse(protobuf::socketrpc::Response *rpcResponse) {
    try {
        if (connection->isClosed()) {
            return;
        }
    
        connection->sendProtoMessage(rpcResponse);
        connection->close();
    } catch (IOException &e) {
        // failed
    }
}

protobuf::socketrpc::Response* protobuf::socketrpc::ConnectionHandler::handleError(
                                                            std::string msg, ErrorReason reason)
{
    Response *response = new Response();
    response->set_error(msg);
    response->set_error_reason(reason);
    return response;
}