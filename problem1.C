#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert the new node after the given node P
void insertAfter(struct Node** head_ref, int P, int X) {
    struct Node* temp = *head_ref;
    
    // Traverse the linked list to find the node with data P
    while (temp != NULL && temp->data != P) {
        temp = temp->next;
    }

    // If P is not found
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    // Create the new node with data X
    struct Node* newNode = createNode(X);
    newNode->next = temp->next;  // Set the next of new node to the next of P
    temp->next = newNode;        // Set the next of P to the new node
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to append a node at the end
void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    // If the linked list is empty, make the new node as the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of the last node
    last->next = newNode;
}

int main() {
    int N, P, X, i, value;
    struct Node* head = NULL;

    // Reading input
    printf("Enter the number of nodes: ");
    scanf("%d", &N);

    printf("Enter the linked list values:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter the node P after which to insert: ");
    scanf("%d", &P);

    printf("Enter the node X to insert: ");
    scanf("%d", &X);

    // Insert X after P
    insertAfter(&head, P, X);

    // Print the final list
    printf("The linked list is:\n");
    printList(head);

    return 0;
}
