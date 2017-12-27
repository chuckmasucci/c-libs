#include <stdio.h>
#include <stdlib.h>
#include <dbg.h>
#include "list.h"

void List_print(Node **headRef)
{
    if(headRef == NULL) {
        log_warn("List is empty");
    }

    Node *currentNode = *headRef;
    debug("List count: %d", List_count(*headRef));
    for(int i = 0; i < List_count(*headRef); i++) {
        debug("node id: %d", currentNode->id);
        currentNode = currentNode->next;
    }
}

void List_push(struct Node **headRef, void *newData)
{
    if(headRef == NULL) {
        log_warn("List is empty");
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    newNode->id = id++;
    *headRef = newNode;
}

Node *List_remove(struct Node **headRef, int id)
{
    check(headRef != NULL, "Node headRef is null");

    Node *current = *headRef;
    Node *nodeToDelete;
    Node *nodeToMove;
    Node *nodeNext;

    int listAmt = List_count(*headRef);
    for(int i = 0; i < listAmt; i++) {
        nodeNext = *headRef;
        // We are removing the head node
        if(current->id == id && i == 0) {
            nodeToDelete = current;
            if(current->next) {
                nodeToMove = current->next;
            }
            *headRef = nodeToMove;
            nodeNext = (listAmt == 1) ? NULL : *headRef;

            // Clean up
            free(nodeToDelete);

            break;
        /*// We are removing a non-head node*/
        } else if(current->next->id == id) {
            // This is the node we are going to delete
            nodeToDelete = current->next;
            current->next = NULL;

            // This is the node we are moving
            if(nodeToDelete->next) {
                nodeToMove = nodeToDelete->next;

                // Repoint the node to move
                current->next = nodeToMove;

                // Set the head
                nodeNext = nodeToMove;
            }

            // Clean up
            free(nodeToDelete);

            break;
        }
        current = current->next;
    }

    return nodeNext;

error:
    log_warn("List remove: An error occurred");
    return NULL;
}

int List_count(Node *headRef)
{
    if(headRef == NULL) {
        return 0;
    }

    return 1 + List_count(headRef->next);
}
