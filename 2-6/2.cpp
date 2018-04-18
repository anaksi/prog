#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

long double fact(int n)
{
    if(n > 1)
        return n * fact(n - 1);
    else
        return 1;
}

void prob(int n, int m, int s,  float &pr, int &pro)
{
    float pd,pm;
    long double c;

    c=fact(n)/(fact(m)*fact(n-m));

    pd=c*pow(0.45,m)*pow(0.55,(n-m));
    pm=c*pow(0.55,m)*pow(0.45,(n-m));

    if (s==2) pr=pm; else pr=pd;
    if (s<0 || s>2 || m>n)
        pro = 0; else pro = 1;

}
main()
{ float pr;
  int pro,n,m,s;

  printf("\n  Imput number of children, number of girls/boys and type 1 for girls, 2 for boys ");
  scanf("%d%d%d",&n,&m,&s);
  prob(n,m,s,pr,pro);

  if (pro==1)
  printf("\n  Probability equals to %.4f ",pr);
  else printf("\n  Input is wrong");
  getch();
}
