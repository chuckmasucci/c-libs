#ifndef list_h
#define list_h

#include <stdlib.h>

typedef struct Node {
    void *data;
    int id;
    struct Node *next;
} Node;

extern int id;

void List_push(struct Node **headRef, void *newData);
int List_count(Node *headRef);
Node *List_remove(struct Node **headRef, int id);
void List_destroy(struct Node **headRef);
#endif
