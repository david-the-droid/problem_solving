#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

void PrintLinkedListReverse(node *pointer, uint8_t const size)
{
  int *storageArray = malloc((size) * sizeof(int)); 
  uint8_t localSize = size-1; 

  while(pointer != NULL)
  {
    storageArray[localSize] = pointer->data;
    pointer = pointer->next; 
    localSize--;
  }
  for(int index = 0U; index < size; index++)
  {
    printf("Print linked list backwards: %d\n", storageArray[index]);
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

  // PrintLinkedList(head); 

  PrintLinkedListReverse(head, 3U);
   
  return 0;
}