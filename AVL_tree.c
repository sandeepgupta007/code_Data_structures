// Program on AVL implementation
// Name : Sandeep Gupta
// completion time : 

#include<stdio.h>				// inlcuding header files
#include<stdlib.h>

struct node 					// defining structure
 {
   int data;
   struct node *left,*right; 
   int ht;
 }*avlroot = NULL;					// root node for the tree /structure

int height(struct node*);					// definning various function 
int bf(struct node*);
struct node* insert(struct node* ,struct node*);
struct node* ll(struct node*);
struct node* rr(struct node*);
void display(struct node*);
struct node* rl(struct node*);
struct node* lr(struct node*);
struct node* getnode(int );
void search(struct node* ,int);

void main()					// Beginning of main function 
 {
   int a[20],i=-1,j,opt;			// definning integer variable
   char choice;
   struct node *ptr;
   printf("\n *************************** C program no Avl Tree ****************************************** \n");
   printf("Enter the Elements(to be inserted in the AVL tree && Enter -0 to end the list ) : \n");
    do 						// asking the user to Enter the Data 
     {
       i++;
       scanf("%d",&a[i]);
     }while(a[i] != -0);
    
    for(j=0;j<i;j++)				// Sending the data to the insert function to be inserted in the tree
     {
       ptr = getnode(a[j]);
      avlroot =  insert(avlroot,ptr);
     }
     display(avlroot);
    
     printf("\n In -order traversal for AVL tree : \t");
     display(avlroot);				// in-order traversal function calling

    do
     {
       printf("\n Enter the Element to be Searched in the Tree : \t");		
       scanf("%d",&opt);			// asking to the user to enter the data to be searched in the tree
       search(avlroot,opt);
        printf("\n do you want do search more elements in the Tree ?? (Y/N) : \t");
        scanf(" %c",&choice);			// if more element to be searched
       
     }while(choice != 'n');

    printf("\n ****************************** END of C program ********************************************** \n");
 } 

int height(struct node *t)			// function to calculate height of the tree 
 {
   int lh,rh;
   if(t == NULL)				// if root node is NULL : returnning zero
    return 0;
   
    if(t->right == NULL)			// if right address is NULL then rh = 0
       rh = 0;
    else
       rh = 1 + t->right->ht;

   if(t->left == NULL)
       lh = 0;
   else
      lh = 1 + t->left->ht;    
  
   if(lh > rh)
     return lh;

     return rh;
 }

int bf(struct node *t)				// function to calculate the balance factor 
 {
   int lt,rt;
    lt = height(t->left);
    rt = height(t->right);
    return (lt-rt);
 }

struct node* insert(struct node *t,struct node* new)
 {
    if(t == NULL)
       t = new;

   else if(t->data > new->data)
    {
       t->left = insert(t->left,new);
       if(bf(t) == 2)
        {
          if(new->data < t->left->data)
           t = ll(t);
          else
           t = lr(t);
        }
    } 

   else if(t->data < new->data)
    {
      t->right = insert(t->right,new);
       if(bf(t) == -2)
        {
          if(new->data > t->right->data)
            t = rr(t);
          else
            t = rl(t);
        }
    }
   
   t->ht = height(t);
   return t;
 }

struct node* getnode(int a)
 {
   struct node *new;
   new = (struct node*)malloc(sizeof(struct node));
   new->data = a;
   new->left = NULL;
   new->right = NULL;
   
    return new;
 }

struct node* rr(struct node *t)	   					// ROTATING TREE TO THE LEFT 
 {
     struct node *y;
     y = t->right;
     t->right = y->left;
     t = y->right;
     t->ht = height(t);
     y->ht = height(t);
     return t;
 }

struct node* ll(struct node *t)
 {
    struct node *y;
     y = t->left;
     t->left = y->right;
     t = y->left;
     t->ht = height(t);
     y->ht = height(t);
     return t;
 }

struct node* rl(struct node *t)
 {
    t->right = ll(t->right);
    t = rr(t);
    return t;
 }

struct node* lr(struct node *t)
 {
    t->left = rr(t->left);
    t = ll(t);
    return t;
 }

void display(struct node *t)
 {
   if(t != NULL)
    {
       display(t->left);
       printf(" %d ",t->data);
       display(t->right); 
    }
 }

void search(struct node* t,int opt)						// function to search the data in tree
 { 
    if(t == NULL)
     printf("\n ERROR : Data not Found \n");
    else if(opt > t->data)
       search(t->right,opt);
    else if(opt < t->data)
       search(t->left,opt);
    else if(t->data == opt)
       printf("\n %d Data found in the AVL tree \n",opt);
 }
