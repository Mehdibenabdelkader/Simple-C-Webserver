#include "HTTPRequest.h"

struct HeaderField *HeaderField_constructor(char *name, char *value)
{
    struct HeaderField *headerField = (struct HeaderField *)malloc(sizeof(struct HeaderField));
    headerField->key = name;
    headerField->value = value;
    headerField->next = NULL;
    return headerField;
    
    // I need some way to parse the lines of a request to get the header fields
    
    /* POST /submit-form HTTP/1.1
    Host: www.example.com
    Content-Type: application/x-www-form-urlencoded
    Content-Length: 27*/
};


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
