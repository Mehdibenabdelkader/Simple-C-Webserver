#include "response.h"
#include "../server/Server.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Constructs an HTTP response by serving the requested file.
struct Response responseConstructor(char *filename, struct HTTPRequest request, char *status) {
    char *header = (char *)malloc(BUFFER_SIZE * sizeof(char));
    struct Response res;
    size_t responseLen = 0;

    // Allocate response buffer.
    char *response = (char *)malloc(BUFFER_SIZE * sizeof(char));
    snprintf(header, BUFFER_SIZE, "%sContent-Type: text/html\r\n\r\n", status);

    // Open and read the file.
    int fileFd = open(filename, O_RDONLY);
    if (fileFd < 0) {
        perror("File open failed");
        snprintf(response, BUFFER_SIZE, "HTTP/1.1 404 NOT FOUND\r\n\r\n");
        res.body = response;
        res.size = strlen(response);
        res.status = "HTTP/1.1 404 NOT FOUND\r\n";
        free(header);
        return res;
    }

    // Get file size and read content.
    struct stat file_stat;
    fstat(fileFd, &file_stat);

    memcpy(response, header, strlen(header));
    responseLen += strlen(header);

    ssize_t bytesRead;
    while ((bytesRead = read(fileFd, response + responseLen, BUFFER_SIZE - responseLen)) > 0) {
        responseLen += bytesRead;
    }

    close(fileFd);

    res.body = response;
    res.size = responseLen;
    res.status = status;

    free(header);
    return res;
}
