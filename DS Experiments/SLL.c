#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;

void instbegin();
void instlast();
void instbet();
void delfirst();
void dellast();
void delbet();
void display();
void main()
{
    int choice=0;
    while(choice!=8)
    {
        printf("\nMain menu\n\n");
        printf("choose a function\n\n");
        printf(" 1.Insert at beginning\n 2.Insert at end\n 3.Insert in between\n 4.Delete at beginning\n 5.Delete at last\n 6.Delete in between\n 7.Display the list\n 8.End \n");
        printf("\n Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            instbegin();
            break;
            case 2:
            instlast();
            break;
            case 3:
            instbet();
            break;
            case 4:
            delfirst();
            break;
            case 5:
            dellast();
            break;
            case 6:
            delbet();
            break;
            case 7:
            display();
            break;
            default:
            printf("Enter a valid choice: \n");
            break;
            case 8:
            exit(0);
            break;
        }
    }
}
void instbegin()
{
    struct node *newNode;
    int value;
    newNode = (struct node *) malloc(sizeof(struct node *));
    printf("\nEnter value to be inserted: \n");
    scanf("%d",&value);
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("\nNode inserted");
}
void instlast()
{
    struct node*newNode,*temp;
    int value;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value to be inserted: \n");
    scanf("%d",&value);
    newNode->data=value;
    if(head == NULL)
    {
        newNode->next=head;
        head=newNode;
        printf("\nNode inserted");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
        printf("\nNode inserted");
    }
}

void instbet()
{
    int loc,value;
    struct node*newNode,*temp;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value to be inserted: ");
    scanf("%d",&value);
    newNode->data=value;
    printf("\nEnter the value after which you wish to insert the new value: ");
    scanf("\n%d",&loc);
    temp=head;
    while(temp->data!=loc)
    {
        temp=temp->next;
    }
    if(head==NULL)
    {
        newNode->next=head;
        head=newNode;
        printf("\nNode inserted");
    }
    else if(temp->next=NULL)
    {
        temp->next=newNode;
        newNode->next=NULL;
        printf("\nNode inserted");
    }
    else
    {
        newNode->next=temp->next;
        temp->next=newNode;
        printf("\nNode inserted");
    }
}
void delfirst()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        temp=head;
        head=temp->next;
        free(temp);
        printf("\nNode deleted\n");
    }
}
void dellast()
{
    struct node*temp1,*temp2;
    if(head==NULL)
    {
        printf("\nUnderflow\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\nNode deleted\n");
    }

    else
    {
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
        printf("\nNode deleted\n");
    }
}
void delbet()
{
    struct node*temp1=head,*temp2;
    int val;
    printf("\n Enter the value to be deleted: \n");
    scanf("%d",&val);
    while(temp1->data!=val)
    {
     if(temp1->next==NULL)
     {
         printf("\nGiven node not found in the list!!!");
     }
     else
     {
         temp2=temp1;
         temp1=temp1->next;
     }
   }
   temp2->next=temp1->next;
   free(temp1);
}
void display()
{
    if(head==NULL)
    {
        printf("\nThe linked list is empty\n");
    }
    else
    {
        struct node*temp=head;
        printf("\nThe elements of the Linked list are :\n");
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
         printf("%d-->NULL\n",temp->data);

    }
}

