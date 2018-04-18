#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
  int j,s=0,i,n,m,k, c = -5, d = 10;
  int *a, **b, tmp;
  printf (" Array size -> ");
  scanf ("%d", &m);
   printf (" Second Array size -> ");
  scanf ("%d", &k);
  a = new int [m];
  n = m / k;
  if (m%k>0) n+=1;

  b = new int* [n];
  for (int i = 0; i<n; i++)
    b[i]=new int [k];
  if ( a == NULL )
 {
     printf(" Error in ram ");
    return 1;
 }
 if ( b == NULL )
 {
     printf(" Error in ram ");
    return 1;
 }
 for (i = 0; i < m; i ++ )
 {
   a[i] =rand()%50;
   printf("%4d",a[i]);
 }

  for (i=0; i<n; i++)
 {
     for (j=0; j<k; j++){
         b[i][j]=a[s]; s++;
         if (s>=m+1) b[i][j]=0;
     }
 }
puts("\n");
   for (i=0; i<n; i++)
 {
     for (j=0; j<k; j++)
        printf("%4d",b[i][j]);
     puts("\n");
 }






 delete a;
 for (int i = 0; i < n; i++)
        delete [] b[i];
 a=NULL;
 b=NULL;
 getch();
 return 0;
}
