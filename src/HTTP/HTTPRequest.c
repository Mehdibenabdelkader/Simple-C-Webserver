#include "HTTPRequest.h"

struct HeaderField *head = NULL;
struct HeaderString *allFields = NULL;

void parseHeaders(char *headerFields) {
    // Clear any previously stored headers and header strings.
    emptyHeaderField();       
    emptyHeaderString(); 

    // Create a copy of the input header fields to avoid modifying the original string.
    char fields[strlen(headerFields) + 1]; // +1 for null terminator.
    strcpy(fields, headerFields);

    // Tokenize the copied string to extract each header line separated by newlines.
    char *field = strtok(fields, "\n");

    // Parse each header line until an empty line or only whitespace is encountered.
    while (field) {
        // Add the current header line to a list of header strings.
        request_add_headerstring(field);

        // Move to the next header line.
        if (strstr(field, "Content-Length") != NULL) {
            field = strtok(NULL, "?0");
        } else {
            field = strtok(NULL, "\n");
        }
    }

    // Step 5: Print the parsed header strings for debugging or logging purposes.
    print_headerstrings();

    // Step 6: Iterate through the stored header strings and extract key-value pairs.
    struct HeaderString *temp = allFields; // 'allFields' points to the list of header strings.
    while (temp != NULL) {
        // Extract the key part from the current header string.
        char *key = strtok(temp->string, ":");

        // If no key is found, break out of the loop.
        if (key == NULL) {
            break;
        }

        // Extract the value part from the remainder of the string.
        char *value = strtok(NULL, "\0");

        // If a valid key-value pair is found, store it in the headers list.
        if (value != NULL) {
            request_add_header(key, value);
        }

        // Move to the next header string in the list.
        temp = temp->next;
    }
}


struct HeaderField *HeaderFieldConstructor(char *name, char *value)
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


struct HTTPRequest HTTPRequestConstructor(char *requestString)
{
    for (int i = 0; i < strlen(requestString) - 1; i++)
    {
        if (requestString[i] == '\n' && requestString[i + 1] == '\n')
        {
            requestString[i + 1] = '|';
        }
    }
    char *dup = strdup(requestString);
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
