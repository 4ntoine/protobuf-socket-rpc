//
//  RpcForwarder.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 13.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "RpcForwarder.h"
#include "RpcException.h"
#include "SocketRpcController.h"

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/service.h>

void protobuf::socketrpc::RpcForwarder::registerService(google::protobuf::Service *service)
{
    serviceMap.insert(std::pair<std::string,google::protobuf::Service*>(
                                                                        service->GetDescriptor()->full_name(),
                                                                        service));
}

void protobuf::socketrpc::RpcForwarder::doRpc(Request *rpcRequest, Response *rpcResponse, google::protobuf::Closure *callback)
{
    google::protobuf::Service *service = serviceMap.at(rpcRequest->service_name());
    if (service == NULL)
        throw RpcException(ErrorReason::SERVICE_NOT_FOUND, "Can't find service " + rpcRequest->service_name());
    
    SocketRpcController *socketController = new SocketRpcController();
    google::protobuf::Message *response = forwardToService(rpcRequest, callback, service, socketController);
    rpcResponse->set_response_proto(response->SerializeAsString());
    
    callback->Run();
    
    delete response;
    delete socketController;
}

const google::protobuf::MethodDescriptor* protobuf::socketrpc::RpcForwarder::getMethod(
        Request *rpcRequest, const google::protobuf::ServiceDescriptor *serviceDescriptor)
{
    const google::protobuf::MethodDescriptor *descriptor = serviceDescriptor->FindMethodByName(rpcRequest->method_name());
    if (descriptor == NULL)
        throw RpcException(ErrorReason::METHOD_NOT_FOUND, "Could not find method in the service");
    
    return descriptor;
}

google::protobuf::Message* protobuf::socketrpc::RpcForwarder::getRequestProto(
                protobuf::socketrpc::Request *rpcRequest, const google::protobuf::Message &prototype)
{
    google::protobuf::io::ArrayInputStream arrayInputStream(rpcRequest->request_proto().c_str(), (int)rpcRequest->request_proto().length());
    google::protobuf::io::CodedInputStream codedInputStream(&arrayInputStream);
    
    google::protobuf::Message *message = prototype.New();
    message->MergeFromCodedStream(&codedInputStream);
    
    return message;
}

void protobuf::socketrpc::RpcForwarder::ignoredCallback() {
    // nothing
}

google::protobuf::Message* protobuf::socketrpc::RpcForwarder::forwardToService(
        Request *rpcRequest, google::protobuf::Closure *callback,
        google::protobuf::Service *service, SocketRpcController *controller) {

    const google::protobuf::MethodDescriptor *method = getMethod(rpcRequest, service->GetDescriptor());
    google::protobuf::Message *request = getRequestProto(rpcRequest, service->GetRequestPrototype(method));
    google::protobuf::Message *response = service->GetResponsePrototype(method).New();
    
    service->CallMethod(method, controller, request, response, google::protobuf::NewCallback(this, &protobuf::socketrpc::RpcForwarder::ignoredCallback));
    return response;
}
