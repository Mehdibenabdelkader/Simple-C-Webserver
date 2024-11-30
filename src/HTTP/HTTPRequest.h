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

};

struct HTTPRequest HTTPRequest_constructor(char *requestString);
#endif // HTTPREQUEST_H
