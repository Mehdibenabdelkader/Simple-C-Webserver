#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol,
                                 int port, int backlog, u_long interface,
                                 void (*start)(struct Server *server)) {
    struct Server server;
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.port = port;
    server.backlog = backlog;
    server.interface = interface;
    server.start = start;

    server.address.sin_family = domain; // AF_INET for IPv4
    server.address.sin_port = htons(port); 
    server.address.sin_addr.s_addr = htonl(interface); 

    server.socket = socket(domain, service, protocol);

    // Check if the socket was created successfully
    if (server.sock == 0) 
    {
        perror("Failed to create Socket...\n");
        exit(1); 
    }

    if (bind(server.sock, (struct sockaddr *)&server.address,
            sizeof(server.address)) < 0)
    {
        perror("Failed to bind Socket...\n");
        exit(1);
    }

    if (listen(server.sock, server.backlog) < 0) 
    {
        perror("Failed to listen on Socket");
        exit(1);
    }

    server.start = start;

    return server;
}