#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol,
                                 int port, int backlog, unsigned long interface,
                                 void (*start)(struct Server *server)) {
  struct Server server;
  server.domain = domain;
  server.service = service;
  server.protocol = protocol;
  server.port = port;
  server.backlog = backlog;
  server.interface = interface;
  server.start = start;

  server.address.sin_family = domain;
  // htons -> host to network short. converts port to network byte order
  server.address.sin_port = htons(port);
  // htonl -> host to network long. converts interface to network byte order
  server.address.sin_addr.s_addr = htonl(interface);

  server.sock = socket(domain, service, protocol);

  int b = bind(server.sock, (struct sockaddr *)&server.address,
               sizeof(server.address));

  if (b < 0) {
    perror("Failed to binder Socket");
    exit(1);
  }

  int l = listen(server.sock, server.backlog);

  if (l < 0) {
    perror("Failed to listen on Socket");
    exit(1);
  }

  return server;
}