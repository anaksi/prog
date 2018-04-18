#include <stdlib.h>
#include <stdio.h>

int c; //comparisons counter

int simple(int el,int* arr,int len){
    int index = -1;
    int i = 0;
    while (index==-1 && i<len){
        if (arr[i]==el) index=i;
        i++;
    }
    c=i;
    return index;
}

int bin(int x,int* arr,int start,int len){
    if (len>=start){
        int mid = start+(len-start)/2;
        c++;
        if (arr[mid]==x) return mid;
        if (arr[mid]<x) return bin(x,arr,start,mid-1);
        return bin(x,arr,mid+1,len);
    }
    return -1;
}

void sorta(int *arr,int len){
    for(int i=0;i<len-1;i++){
        for(int j=len-1;j>i;j--){
            if (arr[j]>arr[j-1]){
                int tmp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tmp;
            }
        }
    }
}

int main(){
    //replace "clear" w/ "cls" if you want it to work on Windows
    system("cls");
    int *A,*B,N,x,tmp;
    //creating and sorting first array (N=100)
    N=100;
    A = new int[N];
    for(int i=0;i<N;i++){
        A[i] = i;
    }
    sorta(A,N);

    //searching for x in A
    printf("Input number ");
    scanf("%d",&x);
    c=0;
    tmp = simple(x,A,N);
    if (tmp>-1) printf("Simple search: %d found at %d place with %d comparisons\n",x,tmp,c); else printf("%d wasn't found in A\n",x);
    c=0;
    tmp = bin(x,A,0,N);
    if (tmp>-1) printf("Binary search: %d found at %d place with %d comparisons\n\n",x,tmp,c); else printf("%d wasn't found in A\n\n",x);

    //creating and sorting second array (N=1000)
    N=1000;
    B = new int[N];
    for(int i=0;i<N;i++){
        B[i] = i;
    }
    sorta(B,N);
    //searching for x in B
    printf("Input number ");
    scanf("%d",&x);
    c=0;
    tmp = simple(x,B,N);
    if (tmp>-1) printf("Simple search: %d found at %d place with %d comparisons\n",x,tmp,c); else printf("%d wasn't found in B\n",x);
    c=0;
    tmp = bin(x,B,0,N);
    if (tmp>-1) printf("Binary search: %d found at %d place with %d comparisons\n\n",x,tmp,c); else printf("%d wasn't found in B\n\n",x);

    delete A;
    delete B;
    A=NULL;
    B=NULL;
    //system("pause");
    return 0;
}




















