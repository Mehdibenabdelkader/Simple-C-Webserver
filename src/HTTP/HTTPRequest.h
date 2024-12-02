#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <stdlib.h>
#include <string.h>

enum HTTPMethod{
    GET,
    POST
};

struct HTTPRequest{
    int method;
    char *URI;
    float version;
    // can i include the header fields and message body here?
    char *body;
    struct HeaderField *headerFields;
};

struct HeaderField{
    char *name;
    char *value;
    struct HeaderField *next;
};



struct HTTPRequest HTTPRequest_constructor(char *requestString);
struct HeaderField HeaderField_constructor(char *name, char *value);
void printHTTPRequest(struct HTTPRequest request);
#endif // HTTPREQUEST_H
