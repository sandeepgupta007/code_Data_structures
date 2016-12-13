#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<math.h>
#define maxsize 10

int a[maxsize];
int b[maxsize];

// MERGE SORT BEGIN

 void merge(int l,int mid,int h)
  {
    int k = l, i = 0;
    int m = mid+1;

    while(k <= mid && m <= h )
     {
       if(a[k] <= a[m])
         {
           b[i] = a[k];
           k++;
         }
       else
         {
           b[i] = a[m];
            m++;
         }
       i++;
     }  

    if(k < mid)
     {
      while(k <= mid)
        { 
          b[i] = a[k];
           i++;
           k++;
        }
     }
    else if(m < h)
     {
       while( m <= h)
        {
         b[i] = a[m];
          i++;
          m++;   
        }   
     }   
 }
  
void mergesort(int l,int h)
 {
   int mid;
   if(l < h)
    {
      mid = (h+l)/2;
      mergesort(l,mid);
      mergesort(mid+1,h);
      merge(l,mid,h);
    }
 }

// END OF MERGE SORT .....

// BEGINNING OF SELECTION SORT 

void s_sort(int size)
 {
   int i,smallest,k,temp,j;
   for(i=0;i<size;i++)
    { 
      smallest = a[i];
       k=i;
       for(j=i+1;j<=size;j++)
         if(a[j] <= smallest)
          {
            smallest = a[j];
            k=j;
          }
       temp = a[i];
       a[i]=smallest;
       a[k]= temp;
    }
  
  printf("\n Array After Selection Sort : ");
  for(i=0;i<size;i++)
   {
      printf(" %d ",a[i]);
    
   }
 }

// END OF SELCTION SORT 
 
void display(int i)
 {
   int j;
  for(j=0;j<i;j++)
   printf(" %d  ",b[j]);
 }

// BEGINNING OF INSERTION SORT 

void i_sort(int size)
 {
   int i,j,key;
   for(i=1; i <=size ;i++)
    {
      key = a[i];  
      j = i-1;
        while(a[j] > key && j >= 0)
         {
           a[j+1] = a[j];
            j--;
         }
        a[j+1] = key;
     }
  printf("\n After selection sort array is : \t");
   for(i=0; i <= size ;i++)
      printf(" %d ",a[i]);  
}

// END OF INSERTION SORT 

void q_sort(int i,int m)
 {
   int q;
    if(i < m)
    {
       q = partition(i,m);
       q_sort(i,q-1);
       q_sort(q+1,m); 
    }
 }

int partition(int i,int m)
 {
   int pivot,j,temp;

   pivot = a[m];

   for(j=i+1;j <= m;j++)
    {
      if(a[j] <= pivot)
        {
             temp = a[j];
             a[j] = a[i];
             a[i] = temp;             
	     i++;
        }
    }
   return i-1;
 }

// Beginning of Bubble Sort
void b_sort(int size)
 {
    int i,j,temp;
    for(i=0;i <= size;i++)
     {
       for(j=0;j <= size-i-1;j++)
         {
           if(a[j+1] < a[j]) 
            {
              temp = a[j+1];
              a[j+1] = a[j];
              a[j] = temp;
            } 
         }
     }

   printf("\nAfter Bubble Sort : \t");
    for(i=0;i<=size;i++)
     printf(" %d ",a[i]);
 }

// End of Bubble Sort

// Beginning of Binary Search

int search(int key,int min,int max)
 {
  int mid;
	
     if(max < min)
		 return -1;
	
     mid = (min+max)/2;
	
    if(key == a[mid])
     {
      return(mid);
     }
    else if(a[mid] > key)
       search(key,min,mid-1);
    else
       search(key,mid+1,max);
 }

 void main()
  {
   int i=-1,l=0,j,choice,pos,ans;

    printf("\n Enter the array to be sorted(Enter -0 for ending the array ) : \n");
     do
       {
         i++;
         scanf("%d",&a[i]); 
       }while(a[i] != -0);
    do
    {
      printf("\n Various Sorting Algorithm \n");
      printf("\n Enter 1 for merge sort \n Enter 2 for Selection Sort \n Enter 3 for Insertion Sort \n Enter 4 for Quick Sort \n Enter 5 for Bubble Sort \n Enter 6 for Binary Search \n Enter 7 for EXIT \n");
      scanf("%d",&choice);
      switch(choice)
       {
         case 1:
               mergesort(l,(i-1));
               display(i);
               break;
         case 2:
               s_sort(i-1);
               break;
        case 3:
               i_sort(i-1);
               break;
        case 4:
               q_sort(0,i-1);
               printf("\n After Quick sort :\t ");
                for(j=0;j<i;j++)
                 printf(" %d ",a[j]);
               break;
       case 5:
              b_sort(i-1);
              break;
       case 6: 
              printf("\n Enter the data to be Searched in the Sorted array \t :");
              scanf("%d",&pos);
              b_sort(i-1);
              ans = search(pos,0,i-1);
              if(ans == -1)
                printf(" \n ERROR : Data not Found \n");
              else
              printf("\n In the Sorted list.... %d.... is the position of the searched item ",ans);
       }
    }while(choice != 7);
    
  }
