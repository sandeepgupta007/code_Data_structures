#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 struct bst
  {
    int data;
    struct bst *lchild,*rchild;
  }*root,*t;

void insert();
void search();
void s_insert();
void s_delete();
void display();
void delete();
void pre();
void post();
void in();
void level();
int max();

// Beginning of main Function

 int main()
  {
    int choice,opt,m;
    printf("\n ***************** C program for Binary search Tree ************************* \n");
     do
      {
       printf("\n Enter the choice : \n- 1) insert \n- 2) search \n- 3) Display \n- 4) s_delete \n- 5) delete \n- 6) Various Traversals \n- 8) Exit \n");
      scanf("%d",&choice);    
         switch(choice)
          {
             case 1:
                   insert();
                   printf("\n The tree is : \t");
                   t = root;
                   display(root);
                   break;
             case 2:
		   search();
	 	   break;
	     case 3:
		   printf("\n The tree is : \t");
                   t = root;
       		   display(root);
                   break;
            /* case 4:
                   s_delete();
                   printf("\n The tree is : \t");
                   display(root);
                  break;*/
             case 5:
                  delete();
                  printf("\n The tree is : \t");
                  display(root);
                  break; 
             case 6:
                  printf("\n Enter the choice for which order you want \n 1) Pre-Order \n 2) Post-Order \n 3) In-Order \n -->>");
                  scanf("%d",&opt);
                  switch(opt)
                   {
                     case 1:
                           t = root;
                           printf("\n Pre-Order traversal is \t :");
                           pre(root);
                           break;
                    case 2:
                           t = root;
                           printf("\n Post order Traversal is \t :");
                           post(root);
                           break;
                    case 3:
                           t = root;
                           printf("\n In-order Traversal is \t :");
                           display(root);
                           break;
		    case 4:
			  t =root;
			   printf("Level Order traversal is : \t");
			   level(root);
			   break;
                   }
                 break;
            }
      }while(choice != 8);
    
    printf("\n ************************************* END of Program ************************************** \n");
    return 0;
  }

void insert()
 {
   int temp;
   printf("\n************** == INSERT \n");
   printf("\n Enter the element : \t");
   scanf("%d",&temp);

   struct bst *new,*top;
   new = (struct bst*)malloc(sizeof(struct bst));
   new->data = temp;
   new->rchild = NULL;
   new->lchild = NULL;

    if(root == NULL)
     {
       root = new;
     }
    else
     {
        top = root;
        s_insert(new,top);
     }
 }

void s_insert(struct bst *new,struct bst *top)
  {
    if(top->data > new->data)
     {
       if(top->lchild == NULL )
         top->lchild = new;
       else
         s_insert(new,top->lchild);
     }
    else
     {
       if(top->rchild == NULL)
        top->rchild = new;
       else
        s_insert(new,top->rchild);
     }
  }

void search()
  {
    int temp;
    printf("\n Enter the Data tp be Searched : \t");
    scanf("%d",&temp);
    
     struct bst *top,*loc;
     top = root;

     while(top != NULL)
      {

        if(top->data == temp)
         {
           if(top == root)
            printf("\n It is a root element \n");
           else 
            printf("\n Its Parents are : %d \n",loc->data);
           break;   
         }

        else if(temp > top->data)
          { 
            loc = top;
            top = top->rchild;
          }
         else if(temp < top->data)
          {
            loc = top;
            top = top->lchild;
          }
      }

   if(top->data != temp) 
     printf("\n ERROR : Data not found \n");
  
  }

void display(struct bst *t)
  {
    if(t != NULL)
     {
       display(t->lchild);
       printf(" %d ",t->data);
       display(t->rchild);
     }
  }

void pre(struct bst *t)
   {
     if(t != NULL)
      {
         printf(" %d ",t->data);
         pre(t->lchild);
         pre(t->rchild); 
      }
   }

void post(struct bst *t)
   {
     if(t != NULL)
      {
        post(t->lchild);
        post(t->rchild);
        printf(" %d ",t->data);
      }
   }

void level(struct bst *t)
   {
	int k;
       struct bst *qu[20],*loc;

        qu[0] = t;
	int i = 0;
	int j = 0;
	while(j<=i)
 	 {
	    loc = qu[j];
	    if(loc->lchild != NULL)
	     {
		i++;
	       qu[i] = loc->lchild;
	     }
	     if(loc->rchild != NULL)
  	     {
	 	i++;
		qu[i] = loc->rchild;
	     }
	j++;
	 }
	
	for(k =0 ;k<=i;k++)
   	 printf(" %d ",qu[k]->data);

   }

void delete(struct bst *t)
  {
    int temp,m;
    printf("\n Enter the data to deleted : \t ");
    scanf("%d",&temp);
	 struct bst *top,*loc;
     top = root;
     while(top != NULL)
      {

        if(top->data == temp)
         {
           if(top->rchild == NULL && top->lchild == NULL)
	     {
		if(loc->rchild == top)
		 {
		   loc->rchild = NULL;	
		   free(top);
  		 }
		else 
		 {
		    loc->lchild = NULL;
		    free(top);	
		 }
	     }

	  else if(top->rchild != NULL && top->lchild == NULL)
	    {
	       if(loc->rchild == top)
		{
			loc->rchild = top->rchild;
			free(top);
		}
		else
		{
			loc->lchild = top->rchild;
			free(top);
		}
	   }

	else if(top->lchild != NULL && top->rchild == NULL)
	   {
		if(loc->rchild == top)
                {
                        loc->rchild = top->lchild;
                        free(top);
                }
                else
                {
                        loc->lchild = top->lchild;
                        free(top);
                }

	   }
	
	else if(top->lchild != NULL && top->lchild != NULL)
	  {
		m = max(top->rchild);
		top->data = m;		
	  }
           break;
         }

        else if(temp > top->data)
          {
            loc = top;
            top = top->rchild;
          }
         else if(temp < top->data)
          {
            loc = top;
            top = top->lchild;
          }
      }
  }

int max(struct bst *p)
  {
	int m;
	m = p->data;
     while(p!= NULL)
      {
         if(m < p->data)	
	   m = p->data;
       	   p = p->rchild;
      }

   return m;
  }
