#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
  int j,s=2,i,n,m,k;
  int **b, tmp;


  n = m / k;
  if (m%k>0) n+=1;

  b = new int* [10];
  b[0]=new int [10];
  for (int i = 1; i<10; i++)
    b[i]=new int [1+i];

 if ( b == NULL )
 {
     printf(" Error in ram ");
    return 1;
 }

  for (i=0; i<1; i++)
 {
     for (j=0; j<10; j++){
         b[i][j]=j;

     }
 }
 for (j=0; j<1; j++)
 {
     for (i=0; i<10; i++){
         b[i][j]=i;

     }
 }
  for (i=1; i<10; i++)
 {
     for (j=1; j<s; j++){
         b[i][j]=j*i;

     }
     s++;
 }
puts("\n");
s=2;
   for (i=0; i<1; i++)
 {
     for (j=0; j<10; j++)
        printf("%4d",b[i][j]);
     puts("\n");
 }

 for (i=1; i<10; i++)
 {
     for (j=0; j<s; j++)
        printf("%4d",b[i][j]);
     puts("\n"); s++;
 }





 for (int i = 0; i < n; i++)
        delete [] b[i];

 b=NULL;
 getch();
 return 0;
}
