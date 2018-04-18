#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

using namespace std;





int random (int N) { return rand() % N; }

int main()
{
    srand(time(NULL));

int re, orl,p;
re=0; orl=0;
int po;
printf("Input number of tries: ");
cin >> po;
while (po>0)
{
p=random(100);
if (p>=50) re=re+1;
else orl=orl+1;
po=po-1;

}
cout << re << ' ' << orl;
return 0;
}
