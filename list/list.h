#ifndef list_h
#define list_h

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

Node *List_create(void *data);
int List_push(Node **head_ref, void *data);
int List_unshift(Node **head_ref, void *data);
int List_count(Node *head_ref);
int List_cleanup(Node **head_ref);

#endif