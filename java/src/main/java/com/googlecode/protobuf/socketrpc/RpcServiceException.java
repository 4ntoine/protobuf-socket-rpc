package com.googlecode.protobuf.socketrpc;

import com.google.protobuf.ServiceException;

/**
 *  Advanced ServiceException with ErrorReason property
 */
public class RpcServiceException extends ServiceException {

    private SocketRpcProtos.ErrorReason reason;

    public SocketRpcProtos.ErrorReason getReason() {
        return reason;
    }

    public RpcServiceException(Throwable cause, SocketRpcProtos.ErrorReason reason) {
        super(cause);
        this.reason = reason;
    }

    public RpcServiceException(String message, SocketRpcProtos.ErrorReason reason) {
        super(message);
        this.reason = reason;

    }

    public RpcServiceException(String message, Throwable cause, SocketRpcProtos.ErrorReason reason) {
        super(message, cause);
        this.reason = reason;
    }
}
