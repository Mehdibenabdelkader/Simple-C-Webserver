#include <stdio.h>
#include "src/Server.h"

void start(struct Server *server) {
    printf("Server started on port %d\n", server->port);
    printf("================== Waiting for connection ==================\n");
    int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&server->address);

}

int main () {
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, 80, 10, INADDR_ANY);
    server.launch(&server);
    return 0;
}
