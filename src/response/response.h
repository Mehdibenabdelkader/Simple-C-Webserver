#ifndef RESPONSE_H
#define RESPONSE_H
#include "../HTTP/HTTPRequest.h"


struct Response {
  char *status;
  char *body;
  size_t size;
};

struct Response responseConstructor(char *filename, struct HTTPRequest request,
                                     char *status);

#endif // RESPONSE_H