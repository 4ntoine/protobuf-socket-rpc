package com.googlecode.protobuf.socketrpc;

import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import java.io.IOException;
import java.util.logging.Logger;

/**
 *
 */
public class SecureSocketRpcConnectionFactory implements RpcConnectionFactory {

    private static final Logger LOG =
        Logger.getLogger(SocketServerRpcConnectionFactory.class.getName());

    private final String host;
    private final int port;
    private final boolean delimited;

    /**
     * Constructor to create sockets the given host/port.
     */
    public SecureSocketRpcConnectionFactory(String host, int port, boolean delimited) {
        this.host = host;
        this.port = port;
        this.delimited = delimited;
    }

    @Override
    public Connection createConnection() throws IOException {
        SSLSocketFactory sslSocketFactory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        SSLSocket sslSocket = (SSLSocket) sslSocketFactory.createSocket(host, port);

        LOG.info("Client connected to " + host + ":" + port);

        sslSocket.setEnabledCipherSuites(sslSocketFactory.getSupportedCipherSuites());

        return new SocketConnection(sslSocket, delimited);
    }
}
