#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *link;
};
struct Node *createNode(int data);
struct Node *insertAtPosition(struct Node *head, int data, int position) {
  struct Node *newNode = createNode(data);
  if (position == 1) {
    newNode->link = head;
    head = newNode;
    return head;
  }
  struct Node *current = head;
  for (int i = 1; i < position - 1 && current != NULL; i++) {
    current = current->link;
  }
  if (current == NULL) {
    printf("Invalid position\n");
    free(newNode);
    return head;
  }
  newNode->link = current->link;
  current->link = newNode;
  return head;
}
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ->", head->data);
    head = head->link;
  }
  printf("\n");
}
struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->link = NULL;
  return newNode;
}
int main() {
  struct Node *head = createNode(3);
  head->link = createNode(5);
  head->link->link = createNode(7);
  head->link->link->link = createNode(10);
  printf("before inserting");
  printList(head);
  int data = 6, position = 4;
  head = insertAtPosition(head, data, position);
  printList(head);
  return 0;
}