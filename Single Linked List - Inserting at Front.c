#include<stdio.h>
 #include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* cNode(int n_data)
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = n_data;
  new_node->next = NULL;
  return new_node;
}
struct Node* insert(struct Node* head, int n_data)
{
  struct Node* new_node = cNode(n_data);
  new_node->next = head;
  return new_node;
}
void printList(struct Node* head)
{
  struct Node* ptr = head;
  while (ptr!=NULL)
    {
      printf("%d",ptr->data);
      ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
  struct Node* head = cNode(2);
  head->next = cNode(3);
  head->next->next = cNode(4);
  head->next->next->next = cNode(5);
  printf("Linked List:");
  printList(head);
  printf("after inserting:");
  int data = 1;
  head = insert(head, data);
  printList(head);
  return 0;
}