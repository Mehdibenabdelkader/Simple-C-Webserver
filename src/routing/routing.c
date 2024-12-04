#include "routing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the head of the linked list that stores routes.
struct Route *routehead = NULL;

// Function to add a new route (key-value pair) to the linked list.
 
void addRoute(char *key, char *value) {
    // Allocate memory for a new route and initialize it.
    struct Route *temp = (struct Route *)malloc(sizeof(struct Route));
    temp->key = key;
    temp->value = value;
    temp->next = NULL;

    // If the list is empty, make the new route the head.
    if (routehead == NULL) {
        routehead = temp;
        return;
    }

    // Otherwise, traverse to the end of the list and add the new route.
    struct Route *temp2 = routehead;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

// Function to search for a route by its key.
struct Route *search(char *key) {
    struct Route *temp = routehead;

    // Traverse the list and compare each key with the target key.
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp; // Found the matching route.
        }
        temp = temp->next;
    }
    return NULL; // Route not found.
}

// this is just for testing 
void showRoute() {
    struct Route *temp = routehead;

    // Traverse the list and print each key-value pair.
    while (temp != NULL) {
        printf("Key: %s, Value: %s\n", temp->key, temp->value);
        temp = temp->next;
    }
}
