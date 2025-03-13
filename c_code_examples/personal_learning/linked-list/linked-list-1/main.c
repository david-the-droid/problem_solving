#include <stdio.h>
#include <stdlib.h>


int main() {

  struct node
  {
    int data;
    struct node *next; 
  };

  struct node *head = NULL;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  one->data = 2;
  two->data = 3;
  three->data = 4;

  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;

  // print contents of list

  while(head->next != NULL)
  {
    head = head->next;
    printf("Linked list item: %d", head->data);
  }  
   
   return 0;
}