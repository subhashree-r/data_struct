#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
struct Node *next;
int data;
} Node;
typedef struct queue{
    struct Node *head;
    struct Node *tail;
}queue;

queue* enqueue(struct queue *q,int element)
{
//This operation inserts a new node into queue
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=element;
    temp->next=NULL;
    if(q->tail==NULL)
    {
        q->tail=q->head=temp;
        return q;
    }
    q->tail->next=temp;
    q->tail=temp;
    return q;
}
queue* addbottom(struct queue *q)
{
    // performs step 2 by dequeuing the head of the hand queue and enqueuing at the end
    if(q -> head == q -> tail) {
      return q;
    }
    Node * current_head;
    current_head = q->head;
    q -> head = current_head -> next;
    current_head -> next = NULL;

    q -> tail -> next = current_head;
    q -> tail = current_head;
    return q;
}

queue* pushelem(queue* table, Node* hand) {
    // perfroms step 1. Making the head of hand deck queue point to the queue on table.
  if(table -> head == NULL) {
    table -> head = table -> tail = hand;
    hand -> next = NULL;
    return table;
  }
  hand->next = table -> head;
  table->head = hand;
  return table;
}

void print(Node* n) {
  printf("------\n");
  while(n != NULL) {
    printf("%dqqqq\n", n->data);
    n = n->next;
  }
    printf("------\n");

}

queue* shuffle(struct queue *q)
{

    // Performs one round
  struct queue *table=(struct queue*)malloc(sizeof(struct queue));
  table -> head = table -> tail = NULL;
 // table->head=table->tail=NULL;
  Node* temp;
  while(q->head != NULL)
  {
      temp = q -> head -> next;
      // performs step 1
      table = pushelem(table, q->head);
      q -> head = temp;
      q->head = temp;
      if(q->head != NULL) {
        //performs step 2
        q = addbottom(q);
      }
      else {
        break;
      }

  }

   return table;
}

int comp(struct Node *q)
{

    // performs the rounds until the deck after shuffling is same as the original deck.
    int ind=0;
    while(q!=NULL)
    {
        if(ind!=q->data)
        {
            return 0;
        }
        q = q->next;
        ind++;
    }
    return 1;
}
void compute_rounds(struct queue *q)
{
    int no_rounds=0;

     do
     {
        no_rounds++;
        q = shuffle(q);
     }while(!comp(q->head));
    printf("no. of rounds %d\n",no_rounds);
}
int main()
{
    int n;
    int i;
    //struct Node* head = NULL;
    printf("enter number of cards: ");
    scanf("%d",&n);
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->head=q->tail=NULL;
    for( i=0;i<n;i++)
    {
        q = enqueue(q, i);
    }

    compute_rounds(q);
    return 1;
}
