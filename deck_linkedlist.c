#include<stdio.h>
#include<stdlib.h>
//
//You are given a deck containing N cards. While holding the deck:

/*1. Take the top card off the deck and set it on the table
2. Take the next card off the top and put it on the bottom of the deck in your hand.
3. Continue steps 1 and 2 until all cards are on the table. This is a round.
4. Pick up the deck from the table and repeat steps 1-3 until the deck is in the original order.

Part A
Write a program to determine how many rounds it will take to put a deck back into the original order. This will involve creating a data structure to represent the order of the cards. This program should be written in C only. It should take a number of cards in the deck as a command line argument and write the result to stdout.  Please ensure the program compiles and runs correctly (no pseudo-code). 

Part B
Please describe (in English, not code), how you would modify the code if you were writing this for a low powered device (e.g. MCU).*/
//
typedef struct Node
{
struct Node *next;
int data;
} Node;

Node* pushtop(struct Node *head, int element)
{
    //creating new node
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    //inserting element to start of linked list
    temp->data = element;
    temp->next = head;
    return temp;
}

Node* pushelem(Node* table, Node* hand) {
// This performs step 1 of placing the first card of the deck on hand onto table. The head of hand linked list becomes the head of table linked list.
  hand -> next = table;
  return hand;
}

Node* addbottom(struct Node *head)
{

    // This performs step 2 by appending the first element of the linked list to last of the hand linked list.
    Node* current = head -> next;
    Node* next_head = current;
    head -> next = NULL;
    if(current != NULL) {
      while(current->next!=NULL)
      {
          current=current->next;
      }
      current->next = head;
      return next_head;
    }
    else {
      return head;
    }

}

struct Node* shuffle(struct Node *head)
{
  struct Node *table=NULL;
  Node* temp;
  while(head != NULL)
  {
      temp = head -> next;
      //performs step 1
      table = pushelem(table, head);
      head = temp;
      if(head != NULL) {
        temp = head -> next;
      // performs step 2
        head = addbottom(head);
      }
      else {
        break;
      }
  }
  //Node* table2 = table;
  //while(table2 != NULL) {
    //printf("%daaa\n", table2->data);
    //table2 = table2->next;
  //}
  return table;
}

int comp(struct Node *head)
{

    // This function checks if the current deck after shuffling is equal to original deck
    int ind=0;
    while(head->next!=NULL)
    {
        if(ind!=head->data)
        {
            return 0;
        }
        head=head->next;
        ind++;
    }
    return 1;
}
void compute_rounds(struct Node *head)
{
    int no_rounds=0;
// Performs shuffling till the deck is equal to original deck
     do
     {
        no_rounds++;
        head = shuffle(head);
     }while(!comp(head));
    printf("no. of rounds %d\n",no_rounds);
}
int main()
{
    int n;
    int i;
    struct Node* head = NULL;
    printf("enter number of cards: ");
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        head = pushtop(head, n-1-i);
    }
    printf("%d\n", head->data);
    compute_rounds(head);
    return 1;
}
