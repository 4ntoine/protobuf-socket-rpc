package com.googlecode.protobuf.socketrpc;

import javax.net.ssl.*;
import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.security.*;
import java.security.cert.CertificateException;
import java.util.logging.Logger;

/**
 * SSL server socket factory
 */
public class SecureSocketServerRpcConnectionFactory implements ServerRpcConnectionFactory {

    private static final Logger LOG = Logger.getLogger(SecureSocketServerRpcConnectionFactory.class.getName());

    private final int port;
    private final int backlog;
    private final InetAddress bindAddr;
    private final boolean delimited;
    private SSLContext sslContext;

    private volatile ServerSocket serverSocket = null;

    public static final String DEFAULT_PROTOCOL = "TLSv1.2";
    public static final String DEFAULT_ANDROID_KEYSTORETYPE = KeyStore.getDefaultType(); // "BKS"
    public static final String DEFAULT_JDK_KEYSTORETYPE = "JKS";

    public static SSLContext buildSSLContext(String keyStoreType, SSLCredentials credentials, String protocol)
        throws
            KeyStoreException,
            CertificateException,
            NoSuchAlgorithmException,
            IOException,
            UnrecoverableKeyException,
            KeyManagementException
    {
        KeyStore keyStore = KeyStore.getInstance(keyStoreType);
        keyStore.load(credentials.getKeystoreInputStream(), credentials.getKeystorePassword().toCharArray());

        KeyManagerFactory kmf = KeyManagerFactory.getInstance(KeyManagerFactory .getDefaultAlgorithm());
        kmf.init(keyStore, credentials.getKeyPassword().toCharArray());
        TrustManagerFactory tmf = TrustManagerFactory.getInstance(TrustManagerFactory .getDefaultAlgorithm());
        tmf.init(keyStore);

        SSLContext sslContext = SSLContext.getInstance(protocol);
        sslContext.init(kmf.getKeyManagers(), tmf.getTrustManagers(), new java.security.SecureRandom());
        return sslContext;
    }

    // Visible for testing
    public SecureSocketServerRpcConnectionFactory(int port, int backlog, InetAddress bindAddr, boolean delimited, SSLContext sslContext) {
        this.port = port;
        this.backlog = backlog;
        this.bindAddr = bindAddr;
        this.delimited = delimited;
        this.sslContext = sslContext;
    }

    @Override
    public Connection createConnection() throws IOException {
        // Use Java 1.5+ double checked locking to lazy init
        ServerSocket local = serverSocket;
        if (local == null) {
            local = initServerSocket();
        }
        // Thread blocks here waiting for requests
        SSLSocket clientSslSocket = (SSLSocket)serverSocket.accept();

        LOG.info("Client connected: " + clientSslSocket.getInetAddress());

        clientSslSocket.setEnabledCipherSuites(sslContext.getServerSocketFactory().getSupportedCipherSuites());
        return new SocketConnection(clientSslSocket, delimited);
    }

    private synchronized ServerSocket initServerSocket() throws IOException {
        ServerSocket local = serverSocket;
        if (local == null) {
            LOG.info("Secure listening for requests on port: " + port);

            SSLServerSocketFactory sslServerSocketFactory = (SSLServerSocketFactory) SSLServerSocketFactory.getDefault();
            serverSocket = local = sslServerSocketFactory.createServerSocket(port, backlog, bindAddr);
        }
        return local;
    }

    @Override
    public void close() throws IOException {
        ServerSocket local = serverSocket;
        if (local != null && !local.isClosed()) {
            LOG.info("Close server socket");
            local.close();
        }
    }
}
