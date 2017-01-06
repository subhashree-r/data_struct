#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
};
void reverse(struct Node **head)
{
    struct Node *current=*head;
    struct Node *prev=NULL;
    struct Node *next;
   while(current!=NULL)
   {
// start with initializing next and then go on swapping
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
   }
   *head=prev;//finally point head to prev
}
void push(struct Node **head, int a)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node*));
    newnode->data=a;
    newnode->next=*head;
    *head=newnode;
}
void printList(struct Node *head)
{
struct Node *temp = head;
while(temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}
}
/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printf("Given linked list\n");
	printList(head);
	reverse(&head);
	printf("\nReversed Linked list \n");
	printList(head);
	getchar();
}
