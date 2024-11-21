#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 5000000

struct Server {
	int domain;
	int service;
	int protocol;
	int port;
	int backlog;
	unsigned long interface;
	struct sockaddr_in address; 

	int sock;

	void (*launch)(void);
};

struct Server server_constructor(int domain, int service, int protocol,
								 int port, int backlog, unsigned long interface,
                                 void (*launch)(struct Server *server));

#endif // !SERVER_H