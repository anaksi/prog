#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

void tri(float a, float b, float c, float* per, float* pl, int* s)
{
    float pp, p1=*per;

    *per=a+b+c;
    pp=*per/2;
    *pl=sqrt(pp*(pp-a)*(pp-b)*(pp-c));
    if ((a < b+c) && (b < a+c) && (c < a+b))
        *s=1; else *s=0;

}
main()
{ float a,b,c,per,pl;
  int s;

  printf("\n  Input a,b,c ");
  scanf("%f%f%f",&a,&b,&c);
  tri(a,b,c,&per,&pl,&s);

  if (s==1)
  printf("\n  Perimeter=%4.2f Area=%4.2f ",per,pl);
  else printf("\n  Such triangle doesn't exist");
  getch();
}

