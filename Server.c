#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol,
    int port, int backlog, u_long interface, void (*launch)(void)) 
{
    struct Server server;
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.port = port;
    server.backlog = backlog;
    server.interface = interface;
    server.launch = launch;
    
    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = interface;
    
    return server;
}  