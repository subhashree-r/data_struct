// C program to find n'th node from end using slow and
// fast pointers
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
int data;
struct node* next;
};

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct node *head,int n)
{
    int count=0;
    struct node *main_ptr=head;
    struct node *ref=head;
    if(head!=NULL)
    {
        while(count<n)
        {
            if(ref==NULL)
            {
                printf("the given number is greater than the number of nodes");
                return;
            }
            ref=ref->next;
            count++;
        }
        while(ref!=NULL)
        {
            main_ptr=main_ptr->next;
            ref=ref->next;
        }
        printf("nth node from last %d is %d",n,main_ptr->data);
    }
}
void push(struct node** head_ref, int new_data)
{
/* allocate node */
struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

/* put in the data */
new_node->data = new_data;

/* link the old list off the new node */
new_node->next = (*head_ref);

/* move the head to point to the new node */
(*head_ref) = new_node;
}

/* Drier program to test above function*/
int main()
{
/* Start with the empty list */
struct node* head = NULL;
push(&head, 20);
push(&head, 4);
push(&head, 15);
push(&head, 35);

printNthFromLast(head, 4);
}
