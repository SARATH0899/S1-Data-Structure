#include<stdio.h>
#include<conio.h>

void instBegin(int);
void instEnd(int);
void instBtw(int,int);
void delBegin();
void delEnd();
void delSpec(int);
void display();

struct Node
{
   int data;
   struct Node*prev,*next;
}*head=NULL;

void main()
{
   int choice1, choice2, value, location;
   while(1)
   {
      printf("\Doubly Linked List\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
      scanf("%d",&choice1);
      switch(choice1)
      {
         case 1: printf("Enter the value to be inserted: ");
         		 scanf("%d",&value);
                 while(1)
                 {
                 	printf("\nSelect from the following Inserting options\n");
                 	printf("1. At Beginning\n2. At End\n3. After a Node\n4. Cancel\nEnter your choice: ");
                    scanf("%d",&choice2);
                    switch(choice2)
                    {
                       case 1: 	instBegin(value);
                       		break;
                       case 2: 	instEnd(value);
                       		break;
                       case 3: 	printf("Enter the location after which you want to insert: ");
                       		scanf("%d",&location);
                       		insertAfter(value,location);
                       		break;
                       case 4: 	goto EndSwitch;
                       default: printf("\nPlease select correct Inserting option!!!\n");
                    }
                 }
         case 2: while(1)
                 {
                 	printf("\nSelect from the following Deleting options\n");
                 	printf("1. At Beginning\n2. At End\n3. Specific Node\n4. Cancel\nEnter your choice: ");
                    scanf("%d",&choice2);
                    switch(choice2)
                    {
                       case 1: 	delBegin();
                       		break;
                       case 2: 	delEnd();
                       		break;
                       case 3: 	printf("Enter the Node value to be deleted: ");
                       		scanf("%d",&location);
                       		delSpec(location);
                       		break;
                       case 4:	goto EndSwitch;
                       default: printf("\nPlease select correct Deleting option!!!\n");
                    }
                 }
                 EndSwitch: break;
         case 3: display();
         	 break;
         case 4: exit(0);
         default: printf("\nPlease select correct option!!!");
      }
   }
}

void instBegin(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> prev = NULL;
    if(head == NULL)
    {
       newNode -> next = NULL;
       head = newNode;
    }
    else
    {
       newNode -> next = head;
       head = newNode;
    }
    printf("\nInsertion success!!!");
}
void instEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   newNode -> next = NULL;
   if(head == NULL)
   {
      newNode -> prev = NULL;
      head = newNode;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> next != NULL)
         temp = temp -> next;
      temp -> next = newNode;
      newNode -> prev = temp;
   }
   printf("\nInsertion success!!!");
}
void insertAfter(int value, int location)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(head == NULL)
   {
      newNode -> prev = newNode -> next = NULL;
      head = newNode;
   }
   else
   {
      struct Node *temp1 = head,*temp2;
      while(temp1 -> data != location)
      {
         if(temp1 -> next == NULL)
         {
            printf("Given node is not found in the list!!!");
         }
         else
         {
            temp1 = temp1 -> next;
         }
      }
      temp2 = temp1 -> next;
      temp1 -> next = newNode;
      newNode -> prev = temp1;
      newNode -> next = temp2;
      temp2 -> prev = newNode;
      printf("\nInsertion success!!!");
   }
}
void delBegin()
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct Node *temp = head;
      if(temp -> prev == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         head = temp -> next;
         head -> prev = NULL;
         free(temp);
      }
      printf("\nDeletion success!!!");
   }
}
void delEnd()
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct Node *temp = head;
      if(temp -> prev == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         while(temp -> next != NULL)
            temp = temp -> next;
         temp -> prev -> next = NULL;
         free(temp);
      }
      printf("\nDeletion success!!!");
   }
}
void delSpec(int delValue)
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct Node *temp = head;
      while(temp -> data != delValue)
      {
         if(temp -> next == NULL)
         {
            printf("\nGiven node is not found in the list!!!");
         }
         else
         {
            temp = temp -> next;
         }
      }
      if(temp == head)
      {
         head = NULL;
         free(temp);
      }
      else
      {
         temp -> prev -> next = temp -> next;
         free(temp);
      }
      printf("\nDeletion success!!!");
   }
}
void display()
{
    struct Node*ptr;
    printf("\n printing values...\n");
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
