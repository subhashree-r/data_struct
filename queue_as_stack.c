/* Program to implement a queue using two stacks */
#include<stdio.h>
#include<stdlib.h>

/* structure of a stack node */
struct sNode
{
    struct sNode *next;
    int data;
};
//creating queue
struct queue
{
    struct sNode *stack1;
    struct sNode *stack2;
};
void push(struct sNode **head,int a);
int pop(struct sNode **head);
void enQueue(struct queue *q, int a)
{
    //pusing via stack stack1
    printf("enq%d",a);
    push(&q->stack1,a);
}
int deQueue(struct queue *q)
{
    if(q->stack1==NULL && q->stack2==NULL)
    {
        printf("empty");
        exit(0);
    }
    // poping is out of stack2
    if(q->stack2==NULL)
    {
        while(q->stack1!=NULL)
        {int r;
        //mistake-only while using push you should use &q
            r=pop(&q->stack1);
            push(&q->stack2,r);
        }
    }
return pop(&q->stack2);

}

void push(struct sNode **head,int a)
{
    struct sNode* newnode=(struct sNode*)malloc(sizeof(struct sNode));
    if(newnode==NULL)
    {
        printf("overflow");
        exit(0);

    }

    // mistake- if empty exit there
       newnode->data= a;
       newnode->next=*head;
       *head=newnode;


}
int pop(struct sNode **head)
{
    struct sNode *temp;
    int res;
    if(*head==NULL)
    {
        printf("empty");
        exit(0);
    }

    // you should not use *head->next and *head->data
        temp=*head;
        res=temp->data;
        *head=temp->next;
        free(temp);
        return res;


}
/* Driver function to test anove functions */
int main()
{
	/* Create a queue with items 1 2 3*/
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);

	/* Dequeue items */
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));

getchar();
}
