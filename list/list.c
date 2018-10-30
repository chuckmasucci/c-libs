#include "list.h"
#include <dbg.h>
#include <stdio.h>
#include <stdlib.h>

Node* List_create()
{
    Node* node = malloc(sizeof(Node));
    return node;
}

int List_push(Node** head_ref, void* data)
{
    if (head_ref == NULL) {
        return -1;
    }

    Node* new_node = List_create();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;

    rheturn List_count(*head_ref);
}

int List_unshift(Node** head_ref, void* data)
{
    if (head_ref == NULL) {
        return -1;
    }

    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;

    return List_count(*head_ref);
}

int List_count(Node* head_ref)
{
    if (head_ref == NULL) {
        return 0;
    }

    return 1 + List_count(head_ref->next);
}

int List_cleanup(Node** head_ref)
{
    if (head_ref == NULL) {
        return -1;
    }

    Node* index = *head_ref;
    Node* node_next;

    while (index->next != NULL) {
        node_next = index->next;
        free(index);
        index = node_next;
    }
    free(index);

    return 0;
}
