#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node
{
  int data;
  struct node *next; 
} node;

#define CARRY_ONE (10U)

void CheckForEndOfLinkedList(node *pointer);
void PrintLinkedListReverseRecursively(node *pointer);
void PrintLinkedList(node *pointer);


node* addTwoNumbers(node* l1, node* l2) {

  bool carryOver = false; 
  uint8_t sum = 0U;
  node* storeListStart = l1;

  while(l1 != NULL)
  {
    sum = (l1->data + l2->data);

    if(carryOver)
    {
      sum += 1U;
    }

    if(sum >= CARRY_ONE)
    {
      carryOver = true;
      sum -= 10U;
    }

    l1->data = sum;

    l1 = l1->next;
    l2 = l2->next;
  }
  
  return storeListStart;
}

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

  // static node *head = NULL;
  // static node *one = NULL;
  // static node *two = NULL;
  // static node *three = NULL;

  // one = malloc(sizeof(node));
  // two = malloc(sizeof(node));
  // three = malloc(sizeof(node));

  // one->data = 2;
  // two->data = 3;
  // three->data = 4;

  // one->next = two;
  // two->next = three;
  // three->next = NULL;

  // head = one;

  // PrintLinkedList(head); 

  // PrintLinkedListReverse(head, 3U);

  // PrintLinkedListReverseRecursively(head);

  static node *head1 = NULL;
  static node *sample_1_1 = NULL;
  static node *sample_1_2 = NULL;
  static node *sample_1_3 = NULL;

  static node *head2 = NULL;
  static node *sample_2_1 = NULL;
  static node *sample_2_2 = NULL;
  static node *sample_2_3 = NULL;

  sample_1_1 = malloc(sizeof(node));
  sample_1_2 = malloc(sizeof(node));
  sample_1_3 = malloc(sizeof(node));

  sample_2_1 = malloc(sizeof(node));
  sample_2_2 = malloc(sizeof(node));
  sample_2_3 = malloc(sizeof(node));

  sample_1_1->next = sample_1_2;
  sample_1_2->next = sample_1_3;
  sample_1_3->next = NULL;
  head1 = sample_1_1;

  sample_2_1->next = sample_2_2;
  sample_2_2->next = sample_2_3;
  sample_2_3->next = NULL;
  head2 = sample_2_1;

  sample_1_1->data = 2;
  sample_1_2->data = 4;
  sample_1_3->data = 3;

  sample_2_1->data = 5;
  sample_2_2->data = 6;
  sample_2_3->data = 4;


  node *result = addTwoNumbers(head1, head2);

  PrintLinkedList(result);

  return 0;
}