# Protobuf Socket RPC

Imported from http://protobuf-socket-rpc.googlecode.com/svn/trunk/

## Description

Google's protocol buffer library makes writing rpc services easy, but it does not contain a rpc implementation. The transport details are left up to the user to implement.

This is a simple tcp/ip socket based rpc implementation in c++, java and python for people who want a simple implementation of their protobuf rpc services.

See:
* http://code.google.com/p/protobuf/
* http://code.google.com/apis/protocolbuffers/docs/overview.html

## Download/Installation

### C++

You can find the sources in cpp. You will also need google protobuf sources. You can get it from https://github.com/google/protobuf/releases

### Java

You can find a jar compiled with with Java 1.6 at downloads/protobuf-socket-rpc-2.0.jar, alternatively, you can download the source and use it directly.

You will also need the google protobuf library (version 2.4.0) in your classpath. You can get it from http://code.google.com/p/protobuf/downloads/list

### Python

Python egg is at downloads/protobuf.socketrpc-1.3.2-py2.6.egg

Or checkout source from the python directory.

## Release

Please join the [discussion group](http://groups.google.com/group/protobuf-socket-rpc) to be notified of new releases.

## Mailing List 

Have questions or want to contribute to this project?

Please post a message on the discussion group, http://groups.google.com/group/protobuf-socket-rpc

## C++ Usage

### Server-side

```
ServerRpcConnectionFactory *rpcConnectionFactory = new SocketServerRpcConnectionFactory(PORT, true);
RpcServer *server = new RpcServer(rpcConnectionFactory, true);
MyService *service = new MyService(); // your service impl
server->registerService(service);
server->startServer();
```

### Client-side

```

MyResponse *response;
bool callbackFired = false;

// my callback to handle response
void myCallback() {
  // handle response
  callbackFired = true;
}

try {
        RpcConnectionFactory *connectionFactory = new SocketRpcConnectionFactory("127.0.0.1", PORT, true);
        RpcChannel *channel = new RpcChannelImpl(connectionFactory);
    
        RpcController *rpcController = new SocketRpcController();
        MyService_Stub *service = new MyService_Stub(channel); // your rpc interface
    
        MyRequest *request = new MyRequest(); // your request
        response = new MyResponse(); // your response prototype
        
        service->myMethod(rpcController, request, response, NewCallback(&myCallback));
        
        // wait for callback fired (blocking approach)
        while (!callbackFired);
        
        delete connectionFactory;
        delete channel;
        delete rpcController;
        delete request;
        delete response;
        delete service;
    } catch (ServiceException &e) {
        printf("Error: %s", e.what());
        return -1;
    }
    
    return 0;
```

## Java Usage 

The following example shows a server and a client using the `com.googlecode.protobuf.socketrpc` Java API.

Note that this example uses delimited rpc channel factories which is new in version 2.0 and is not compatible with 1.x versions. Use undelimited rpc channel factories if you need to communicate with 1.x versions.

### Server side

```
// Start server
ServerRpcConnectionFactory rpcConnectionFactory = SocketRpcConnectionFactories
    .createServerRpcConnectionFactory(port);
RpcServer server = new RpcServer(rpcConnectionFactory, 
    Executors.newFixedThreadPool(threadPoolSize), true);
server.registerService(new MyServiceImpl()); // For non-blocking impl
server.registerBlockingService(MyService
    .newReflectiveBlockingService(new MyBlockingInterfaceImpl())); // For blocking impl
server.run();
```

### Client Side (Blocking)

```
// Create channel
RpcConnectionFactory connectionFactory = SocketRpcConnectionFactories
    .createRpcConnectionFactory(host, port);
BlockingRpcChannel channel = RpcChannels.newBlockingRpcChannel(connectionFactory);

// Call service
BlockingInterface service = MyService.newBlockingStub(channel);
RpcController controller = new SocketRpcController();
MyResponse myResponse = service.myMethod(controller, myRequest);

// Check success
if (rpcController.failed()) {
  System.err.println(String.format("Rpc failed %s : %s", rpcController.errorReason(),
      rpcController.errorText()));
}
```

### Client Side (non-blocking)

```
// Create a thread pool
ExecutorService threadPool = Executor.newFixedThreadPool(1);

// Create channel
RpcConnectionFactory connectionFactory = SocketRpcConnectionFactories
    .createRpcConnectionFactory(host, port);
RpcChannel channel = RpcChannels.newRpcChannel(connectionFactory, threadPool);

// Call service
MyService myService = MyService.newStub(channel);
RpcController controller = new SocketRpcController();
myService.myMethod(rpcController, myRequest,
    new RpcCallback<MyResponse>() {
      public void run(MyResponse myResponse) {
        System.out.println("Received Response: " + myResponse);
      }
    });
    
// Check success
if (rpcController.failed()) {
  System.err.println(String.format("Rpc failed %s : %s", rpcController.errorReason(),
      rpcController.errorText()));
}
```

## Python Usage

The following example shows a server and a client using the `protobuf.socketrpc` Python API.

### Server side

```
// Start server
server = protobuf.socketrpc.server.SocketRpcServer(port)
server.registerService(MyServiceImpl())
server.run()
```

### Client Side

```
// Define callback
class Callback:
  def run(self,response):
    print "Received Response: %s" % response

// Create channel
channel = protobuf.socketrpc.channel.SocketRpcChannel(hostname,port)
controller = channel.newController()

// Call service
service  = MyService_Stub(channel)
service.myMethod(controller,request,Callback())

// Check success
if controller.failed():
  print "Rpc failed %s : %s" % (controller.error,controller.reason)
```

### Further examples

There are two more examples included in the source tarball. You might also want to have a look at the unit tests.
