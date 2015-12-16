package com.googlecode.protobuf.socketrpc;

import junit.framework.TestCase;

import javax.net.ssl.SSLContext;
import java.io.IOException;
import java.io.InputStream;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

/**
 *
 */
public class SecureTest extends TestCase {

    private SecureSocketServerRpcConnectionFactory factory;
    private RpcConnectionFactory.Connection serverConnection;
    private RpcConnectionFactory.Connection clientConnection;

    private static final int PORT = 3000;

    private CountDownLatch createConnectionLatch = new CountDownLatch(1);

    protected void startServer() throws Exception {
        InputStream is = getClass().getClassLoader().getResourceAsStream("test_keystore.jks");
        SSLCredentials credentials = new SSLCredentials(is, "123456", "123456");

        try {
            SSLContext sslContext = SecureSocketServerRpcConnectionFactory.buildSSLContext(
                SecureSocketServerRpcConnectionFactory.DEFAULT_JDK_KEYSTORETYPE,
                credentials,
                SecureSocketServerRpcConnectionFactory.DEFAULT_PROTOCOL);
            factory = new SecureSocketServerRpcConnectionFactory(PORT, 0, null, true, sslContext);

            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        serverConnection = (SocketConnection) factory.createConnection();
                        createConnectionLatch.countDown();
                    } catch (IOException e) {
                    }
                }
            }).start();

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            is.close();
        }
    }

    public void testServer() throws  Exception {
        startServer();
        connectClient();

        boolean connected = createConnectionLatch.await(3, TimeUnit.SECONDS); // wait for client to be connected
        assertTrue(connected);
        assertTrue(!clientConnection.isClosed());
        assertTrue(!serverConnection.isClosed());
    }

    private void connectClient() throws IOException {
        SecureSocketRpcConnectionFactory clientFactory = new SecureSocketRpcConnectionFactory("localhost", PORT, true);
        clientConnection = clientFactory.createConnection();
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();

        if (clientConnection != null) {
            if (!clientConnection.isClosed())
                clientConnection.close();

            clientConnection = null;
        }

        if (serverConnection != null) {
            if (!serverConnection.isClosed())
                serverConnection.close();

            serverConnection = null;
        }

        factory.close();
    }

    public void testClient() {

    }

}
