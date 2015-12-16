package com.googlecode.protobuf.socketrpc;

import java.io.InputStream;

/**
 *
 */
public class SSLCredentials {
    private InputStream keystoreInputStream;
    private String keystorePassword;
    private String keyPassword;

    public String getKeyPassword() {
        return keyPassword;
    }

    public InputStream getKeystoreInputStream() {
        return keystoreInputStream;
    }

    public String getKeystorePassword() {
        return keystorePassword;
    }

    public SSLCredentials(InputStream keystoreInputStream, String keystorePassword, String keyPassword) {
        this.keystoreInputStream = keystoreInputStream;
        this.keystorePassword = keystorePassword;
        this.keyPassword = keyPassword;
    }
}
