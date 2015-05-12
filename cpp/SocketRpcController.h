//
//  SocketRpcController.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__SocketRpcController__
#define __ProtobufSocketRpcCpp__SocketRpcController__

#include <google/protobuf/service.h>
#include <stdio.h>
#include <string>
#include "rpc.pb.h"

namespace protobuf {
    namespace socketrpc {

        class SocketRpcController: public google::protobuf::RpcController {
    
        public:
            
            SocketRpcController() {
                Reset();
            };
    
            virtual void Reset();
            virtual bool Failed() const;
            virtual std::string ErrorText() const;
            virtual void StartCancel();
            virtual void SetFailed(const std::string& reason);
            void SetFailed(const std::string &error, ErrorReason reason);
            virtual bool IsCanceled() const;
            virtual void NotifyOnCancel(google::protobuf::Closure* callback);
            
        private:
    
            bool failed;
            std::string error;
            protobuf::socketrpc::ErrorReason reason;
        };
    
    }
}

#endif /* defined(__ProtobufSocketRpcCpp__SocketRpcController__) */
