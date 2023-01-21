#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*front=NULL,*rear=NULL,*head=NULL;
void enqueue(int);
void dequeue();
void display();
void main()
{
    int choice, value;
    printf("\n::Queue implementation in Circular Linked List::\n");
    while(1)
    {
        printf("\nQueue Operations\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice: ");
        }
    }
}
void enqueue(int value)
{
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        front=rear=head=newNode;
        printf("\nFront element %d",front->data);
        printf("\nRear element %d",rear->data);
    }
    else
    {
       rear->next=newNode;
       rear=newNode;
       printf("\nFront element %d",front->data);
       printf("\nRear element %d",rear->data);
    }

}
void dequeue()
{
    if(head==NULL)
    {
        printf("\nQueue is empty\n");
    }
    else if(front==rear)
    {
        struct node*temp=front;
        free(temp);
        front=rear=head=NULL;
    }
    else
    {
        front=front->next;
        head=front;
        printf("\nFront element %d",front->data);
        printf("\nRear element %d",rear->data);
    }
    printf("\nDeleted element successfully\n");
}
void display()
{
    if(head==NULL)
    {
        printf("\nThe Queue is empty\n");
    }
     else
    {
        struct node*temp=front;
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->",rear->data);
        printf("%d",head->data);
    }
}
