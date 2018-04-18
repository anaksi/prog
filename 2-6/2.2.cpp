#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

long double fact(int n){
    if(n > 1) return n * fact(n - 1);
        else return 1;
}

void prob(int n,int m,int s,float &pr,int &pro){
    float pd,pm;
    long double c;

    c=fact(n)/(fact(m)*fact(n-m));

    pd=c*pow(0.45,m)*pow(0.55,(n-m));
    pm=c*pow(0.55,m)*pow(0.45,(n-m));

    if (s==2) pr=pm; else pr=pd;
    if (s<0 || s>2 || m>n) pro = 0; else pro = 1;
}

int main(){
    float pr;
    int n,m,gen,pro;
    char* gender;

    printf("Input total amount of children: ");
    scanf("%d",&n);
    printf("You prefer boys or girls?\n");
    gets(gender);

    if (!strcmp("boys\0",gender)) gen=2;
    if (!strcmp("girls\0",gender)) gen=1;
    if (gen==0) {
        printf("I don't know a gender like %s!\n",gender);
        return 1;
    }
    printf("How much?\n");
    scanf("%d",&m);
    prob(n,m,gen,pr,pro);
    if (pro){
        pr*=100;
        printf("Probability of %d %s equals %.2f\%\n",m,gender,pr);
    } else {
        printf("Wrong input!");
        return 2;
    }
    return 0;
}
