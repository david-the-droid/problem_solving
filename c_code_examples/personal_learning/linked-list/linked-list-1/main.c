#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next; 
} node;

void PrintLinkedList(node *pointer)
{
  while(pointer != NULL)
  {
    printf("Linked list item: %d\n", pointer->data);
    pointer = pointer->next;
  }  
}

int main() {

  static node *head = NULL;
  static node *one = NULL;
  static node *two = NULL;
  static node *three = NULL;

  one = malloc(sizeof(node));
  two = malloc(sizeof(node));
  three = malloc(sizeof(node));

  one->data = 2;
  two->data = 3;
  three->data = 4;

  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;

  PrintLinkedList(head); 
   
   return 0;
}