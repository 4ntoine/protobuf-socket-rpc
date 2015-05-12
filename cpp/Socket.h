//
//  Socket.h
//  ProtobufSocketRpcCpp
//
//  Created by Anton Smirnov on 07.05.15.
//  Copyright (c) 2015 Anton Smirnov. All rights reserved.
//

#ifndef __ProtobufSocketRpcCpp__Socket__
#define __ProtobufSocketRpcCpp__Socket__

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>

namespace protobuf {
    namespace socketrpc {
        
        class Socket {
            
        public:
            Socket(std::string host, int port); // opens socket immediately
            
            int write(const void *buffer, int size);
            int read(void *buffer, int size);
            bool isClosed() const;
            void close();
            
            int getFileDescriptor() const;
            
        private:
            int sd;
            struct sockaddr_in address;
            
        };
        
    }
}

#endif /* defined(__ProtobufSocketRpcCpp__Socket__) */
