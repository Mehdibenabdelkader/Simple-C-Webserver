#include "HTTPRequest.h"


struct HTTPRequest HTTPRequest_constructor(char *requestString)
{
    for (int i = 0; i < strlen(requestString) - 1; i++)
    {
        if (requestString[i] == '\n' && requestString[i + 1] == '\n')
        {
            requestString[i + 1] = '|';
        }
    }
    char *requestLine = strtok(requestString, "\n");
    char *headerFields = strtok(NULL, "|");
    char *messageBody = strtok(NULL, "|");

    struct HTTPRequest request;

    char *method = strtok(requestLine, " ");
    request.method = strcmp(method, "GET") == 0 ? GET : POST; //to be fixed : supports only GET and POST

    char *URI = strtok(NULL, " ");
    request.URI = URI;

    char *version = strtok(NULL, " ");
    version = strtok(version, "/");
    version = strtok(NULL, "/");

    request.version = atof(version);

    

    return request;


};
