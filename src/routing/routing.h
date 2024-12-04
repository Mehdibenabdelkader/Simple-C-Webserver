#ifndef ROUTING_H
#define ROUTING_H
#include <stdlib.h>
#include <string.h>

struct Route {
  char *key;
  char *value;
  struct Route *next;
};

void addRoute(char *key, char *value);
void showRoute();
struct Route *search(char *key);

#endif // ROUTING_H