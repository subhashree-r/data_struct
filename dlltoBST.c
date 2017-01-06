#include<stdio.h>
#include<stdlib.h>

/* A Doubly Linked List node that will also be used as a tree node */
struct node
{
struct node *next;
struct node *prev;
int data;

};

int count(struct node *head)
{
    int count=0;
    struct node *temp;
    temp=head;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
struct node* sortedListToBSTrecur(struct node **head,int n)
{
    struct node *left=sortedListToBSTrecur(head,n/2);
    struct node *root=*head;
    (*head)=(*head)->next;
    root->prev=left;
    root->next=sortedListToBSTrecur(head,(n-n/2)-1);
    return root;
}
struct node* sortedListToBST(struct node *head)
{
    int n=count(head);
    return sortedListToBSTrecur(&head,n);
}
void push(struct node **head,int a)
{
    printf("a");
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=*head;
    newnode->prev=NULL;
    if((*head)!=NULL)
    {
        (*head)->prev=newnode;
    }
    (*head)=newnode;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* A utility function to print preorder traversal of BST */
void preOrder(struct node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->prev);
	preOrder(node->next);
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;

	/* Let us create a sorted linked list to test the functions
	Created linked list will be 7->6->5->4->3->2->1 */
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("Given Linked List\n");
	printList(head);

	/* Convert List to BST */
	struct node *root = sortedListToBST(head);
	printf("\n PreOrder Traversal of constructed BST \n ");
	preOrder(root);

	return 0;
}
