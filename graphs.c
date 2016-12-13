#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define maxsize 10

struct node
 {
   int data;
   struct node *next;
 };//*adj_list[maxsize];

int un_graph();
int dir_graph();
int read(int data,struct node *adj_list[]);

 void main()
  {
     int opt;
     printf("\n ************************* C program for Adjacency List ************************************ \n");
     do
      {
       printf("\n Enter the Choice : \n 1) Undirected Graph \n 2) Directed Graph \n 3) EXIT \n");
       scanf("%d",&opt);
        switch(opt)
         {
           case 1:
             un_graph();
             break;
           case 2:
             dir_graph();
             break; 
         }
      }while(opt != 3);

    printf("\n *********************************** END of C program ***************************************** \n");
  }

int un_graph()
 {
   int v,i,deg=0;
   struct node *loc;
   printf("\n Enter the number of Vertices in the graph : \t");
   scanf("%d",&v);
   struct node *adj_list[10];
   read(v,adj_list);
   
    printf("\n  VERTEX  \t\t\t DEGREE \n"); 
    for(i=1 ; i<=v ; i++)
     {
       deg = 0; 
       loc = adj_list[i];
        while(loc != NULL)
         {
           deg++;
           loc = loc->next;
         }
      printf("\n   %d  \t\t\t  %d",i,deg); 
     }

  return 0; 
 }

int dir_graph()
 {
    int v,i,indeg,outdeg,j;
    struct node *p = NULL;
    printf("\n Enter the Number of Vertices in the graph : \t");
    scanf("%d",&v);
    struct node *adj_list[10];
    read(v,adj_list);
      
      printf("\n   VERTEX  \t\t  OUT-degree \t\t IN- degree \n");
       for(i=1;i<=v;i++)
        {
           p = adj_list[i];
           outdeg = 0;
            while(p != NULL)
             {
                outdeg++;
                p = p->next;
             } 

            indeg = 0;
            struct node *m = NULL; 
            for(j=1;j<=v;j++)
             {
                   m = adj_list[j];
                   while(m != NULL)
                    {
                    
                      if(m->data == i)
                        {
                          indeg++;
                          break;
                        }
                        m = m->next;
                    }
             }
           printf(" %d \t\t %d  \t\t  %d \n",i,outdeg,indeg);
        }
 return 0;
 }

int read(int v,struct node *adj_list[])
 {
    int i,j;
    struct node *c,*loc,*p;
    char choice;
    printf("\n Enter 'y' if Vertices are Adjacent \n");
     for(i=1;i<=v;i++)
      {
        adj_list[i] = NULL; 
        for(j=1;j<=v;j++)
         {
           if(i == j)
            continue;

           printf("%d and %d are Adjacent : \t",i,j);
           scanf(" %c",&choice);

            if(choice == 'y')
             {
                c = (struct node *)malloc(sizeof(struct node));
                c->data = j;
                c->next = NULL;
                 if(adj_list[i] == NULL)
                  {
                    adj_list[i] = c;
                    p = c;
                  }
                 else 
                   {
                       p->next = c;
                       p = c;
                      /* loc = adj_list[i];
                        while(loc->next != NULL)
                         loc = loc->next; 
                        loc->next = c;*/   
                   }            
             }
         }
       }
 }
