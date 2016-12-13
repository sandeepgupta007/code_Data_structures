#include<stdio.h>
#include<stdlib.h>

#define maxsize 10

int visited[maxsize];
int a[maxsize][maxsize];
int queue[maxsize];
int front = 0;
int rear = 0;
int v;
int pr[maxsize];

void que(int );
void bfs(int );
void dfs(int );
void bfsdisp();

	void main()
 	 {
   	   int choice,i,j,k,temp[maxsize],e = 1,count;
   	   	printf("\n ********************************************* C program on BFS & DFS ************************************************\n");	

   		printf("\n Enter the number of vertex : \t");
   		scanf("%d",&v);

   		printf("\n Enter the adjacent vertex to the given Vertex \n");
     		for(i=1;i<=v;i++)
     		  {
	            j = 0;
      		    printf("%d is adjacent to(-0 to terminate) : \t",i);
      	 	do
      	  	  {
           	     j++; 	 
      	   	     scanf("%d",&temp[j]);
      	   	 	if(temp[j] > v)
      	   	  	 {
      	           	   printf("\n ERROR : Enter Valid VERTEX \n");
      	        	   j--;
      	   	 	 }
                    a[i][temp[j]] = 1;
      		  }while(temp[j] != -0);

        		for(k=1;k<=v;k++)
         		  {
           	    	    if(a[i][k] != 1)
           	    	      a[i][k] = 0;
         	  	  }
      		 }

     		for(i=1;i<=v;i++)
      		  visited[i] = 0;

     	  printf(" -- >>> Enter the choice : \n"); 
     	  printf("\n Enter the Starting Vertex :\t ");
       	  scanf("%d",&e);
       	  printf("\n 1) BFS \n 2) DFS \n 3) EXIT \n **--**>> \t");
          scanf("%d",&choice);
        switch(choice)
         {
         	case 1:
         	     bfs(e);
                     printf("\n Breadth First Traversal : \t");
                     bfsdisp();

                     count = 0;
                     printf("\n The elemets of the graph which are not connected from %d are : \t",e);
         	       break;
              
                case 2:
                   printf("\n Depth First traversal is :\t");
                   dfs(e);
                   break;

         }
      
		    printf("\n The elemets of the graph which are not connected from %d are : \t",e);
                      for(i=1;i<=v;i++)
                       {
                         if(visited[i] == 0)
                          { 
                           printf(" %d ",i);
                           count++;
                          }
                       }
                        if(count == 0)
                          printf(" NULL \n");
                        printf("\n");

   		printf("\n ******************************************** END of C Program ********************************************* \n");
 	   }

	void bfs(int e)
 	  {
	     int i;
   	      queue[front] = e;
  	      visited[e] = 1;
    		label:
   	     for(i=1;i<=v;i++)
     	      {
    	        if(visited[i] == 0 && a[e][i] == 1)
        	  { 
      		    rear++;
          		queue[rear] = i;
         		visited[i] = 1;
        	  }
     	      }

	     if(front <= rear-1)
    		 {
       		   front++;
   	           e = queue[front];
       		   goto label;
     		 }
 	  }

	void bfsdisp()
 	  {
   	     int i;
  	     for(i=0;i<=rear;i++)
    	      printf(" %d ",queue[i]);
 	  }

	void dfs(int e)
 	  {
   	     int i;
  	      visited[e] = 1; 
  	      printf(" %d ",e);
    		for(i=1;i<=v;i++)
     		  {
     		     if(visited[i] == 0 && a[e][i] == 1)
       		       {
        		  visited[i] = 1;
          		  dfs(i);
        	       }
     		  }		  
 	}
