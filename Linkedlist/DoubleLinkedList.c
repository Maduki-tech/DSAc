#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insertNode(Node **head, int data) {
    Node *node = createNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void deleteNode(Node **head, int data) {
    Node *temp = *head;
    while (temp != NULL) {
        if (temp->data == data) {
            // If the node to be deleted is the head node
            if (temp->prev == NULL) {
                *head = temp->next;
                temp->next->prev = NULL;
            } else if (temp->next == NULL) {
                temp->prev->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}


int main(int argc, char *argv[]) {

    Node *head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    printList(head);

    printf("\n");
    deleteNode(&head, 2);
    insertNode(&head, 4);
    printList(head);

    return EXIT_SUCCESS;
}
