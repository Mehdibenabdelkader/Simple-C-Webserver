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
    struct HeaderField *headerFieldsHead;
};

struct HeaderField{
    char *key;
    char *value;
    struct HeaderField *next;
};

struct HeaderString {
  char *string;
  struct HeaderString *next;
};



struct HTTPRequest HTTPRequestConstructor(char *requestString);
struct HeaderField *HeaderFieldConstructor(char *name, char *value);
void printHTTPRequest(struct HTTPRequest request);
#endif // HTTPREQUEST_H
