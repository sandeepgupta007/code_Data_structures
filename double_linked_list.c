#include<stdio.h>
#include<stdlib.h>

struct node  						//defining a node for double linked list
 {
   int data;
   struct node *right,*left;
 }*head; 						//head pointer

void create()
 {
   head = NULL;
   int opt = 1;
   struct node *loc,*new;
  
   while(opt == 1)
    {
     new = (struct node *)malloc(sizeof(struct node)); 
     printf("Enter the element :\t");
     scanf("%d",&new->data); 
     new->right = NULL;
      if(head == NULL) 
       {
         head = new;
         new->left = NULL;
         loc = new;
       }   
      else 
       {
         loc->right = new;
         new->left = loc;
         loc = new;  
       }

     printf("do you want to add more elements(Enter 1) :\t");
     scanf("%d",&opt);
    }
 
 }
 
void display()				// function to display the linked list 
 { 
   printf("\n The list is :\t");

   struct node *loc,*temp;
   loc = head;

   while(loc != NULL)
    { 
     printf("%d \t",loc->data);
     loc = loc->right;
    }

  printf("\n");
 }

void insert()  				// inserting the node at end
 {
    struct node *loc,*new;
    loc = head;

    printf("\n    Enter the data :\t");

    new = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&new->data);
   
    while(loc->right != NULL)
     {
       loc = loc->right; 
     }
 
   new->right = NULL;
   loc->right = new;
   new->left = loc;  
 }

void del()   				//function to delete a node
 { 
   int pos,j=1;
   struct node *loc,*new;
   loc = head;

   printf("\nEnter the position to be deleted :\t");
   scanf("%d",&pos);

   while((pos-1) != j && loc != NULL)
    {
     j++;
     loc = loc->right;  
    }
   
   if(loc->right->right ==NULL)
    {
      new = loc->right;
      loc->right = NULL;
    }
   else
    {
      new = loc->right;
      loc->right = new->right;
      new->right->left = new->left;
   }
    free(new);

 }

void ins_beg()       				//function to insert a node at begining
 {
   struct node *new,*loc;
   loc = head;
   
   printf("        Enter the Element :\t");
   scanf("%d",&new->data);
  
   head = new;
   new->right = loc;
   new->left = NULL;
   loc->left = new;
 }
 
void ins_any() 						//function for inserting node at any positon
 {

   int pos,j=1;
   struct node *new,*loc;
   loc = head;

  printf("\nEnter the positon :\t");
  scanf("%d",&pos);
  
   while((pos-1) != j && loc != NULL)
    {
      j++;
      loc = loc->right;
    }
   
   new = (struct node *)malloc(sizeof(struct node));
   printf("\nEnter the data :\t");
   scanf("%d",&new->data);
  
  new->left = loc;
  new->right = loc->right;
  loc->right = new;
  new->right->left = new;

 }

void main()
 {
   int choice,i,j;
   printf("\n*************** C program on double linked list **************\n\n");
   create();
   display();

   do
    {
   printf("\n Enter 1 for insert \n Enter 2 for deleting \n Enter 3 for Display \n Enter 4 for inserting node at the begining of list \n Enter 5 for inserting the node at any position \n Enter 6 for EXIT\n");
   printf("\n---->>>>> Enter your choice : \t");
   scanf("%d",&choice);
   
   switch(choice)
    {

      case 1:
           insert();
           display();
           break;
     case 2:
           del();
           display();
           break;
     case 3:
           display();
           break;
     case 4:
           ins_beg();
           display();
           break;
     case 5:
           ins_any();
           display();
           break;
    }

   } while(choice != 6);
 
  printf("************************************************END OF PROGRAMM**********************************************************\n");
 }
