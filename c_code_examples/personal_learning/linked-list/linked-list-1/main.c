#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
  int data;
  struct node *next; 
} node;

void CheckForEndOfLinkedList(node *pointer);

void PrintLinkedList(node *pointer)
{
  printf("Normal order print\n");

  while(pointer != NULL)
  {
    printf("Item: %d\n", pointer->data);
    pointer = pointer->next;
  }  
}

void PrintLinkedListReverse(node *pointer, uint8_t const size)
{
  printf("Reverse order print\n");
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
    printf("Item: %d\n", storageArray[index]);
  }
}

void PrintLinkedListReverseRecursively(node *pointer)
{
  printf("Recursive reverse order print\n"); 
  CheckForEndOfLinkedList(pointer);
}

void CheckForEndOfLinkedList(node *pointer)
{
  if(pointer == NULL)
  { 
    return;
  }
  CheckForEndOfLinkedList(pointer->next);
  printf("Item: %d\n", pointer->data);  
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

  PrintLinkedListReverse(head, 3U);

  PrintLinkedListReverseRecursively(head);
  
  return 0;
}