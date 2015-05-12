//
//  SocketRpcController.cpp
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#include "SocketRpcController.h"
#include <exception>

namespace protobuf {
    namespace socketrpc {

        void SocketRpcController::Reset() {
            failed = false;
            error = "";        }

        bool SocketRpcController::Failed() const {
            return failed;
        }

        std::string SocketRpcController::ErrorText() const {
            return error;
        }

        void SocketRpcController::StartCancel() {
            throw "Not supported";
        }

        void SocketRpcController::SetFailed(const std::string& reason) {
            this->failed = true;
            this->error = reason;
        }
        
        void SocketRpcController::SetFailed(const std::string &error, ErrorReason reason) {
            this->failed = true;
            this->error = error;
            this->reason = reason;
        }

        bool SocketRpcController::IsCanceled() const {
            throw "Not supported";
        }

        void SocketRpcController::NotifyOnCancel(google::protobuf::Closure* callback) {
            throw "Not supported";
        }
        
    } // namespace
} // namespace

