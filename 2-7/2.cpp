#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void Sum(int** A,int N){
    for (int i=0;i<N;i++){
        int sum = 0;
        for (int j=1;j<=A[i][0];j++) sum+=A[i][j];
        A[i][A[i][0]+1]=sum;
    }
}

int main(){
    system("cls");
    srand(time(0));
    int **A,N;
    N=10;
    A = new int* [N];
    if (A==NULL){
        printf("Error in ram");
        return 1;
    }
    for (int i=0;i<N;i++){
        int tmp = rand()%10;
        A[i] = new int[tmp+2];
        if (A[i]==NULL){
            printf("Error in ram");
            return 2;
        }
        A[i][0] = tmp;
        for (int j=1;j<=tmp;j++){
            A[i][j] = rand()%10;
        }
    }

    Sum(A,N);

    for (int i=0;i<N;i++){
        for (int j=0;j<=A[i][0]+1;j++) printf("%d ",A[i][j]);
        printf("\n");
    }

    for (int i=0;i<N;i++){
        delete A[i];
    }
    delete A;
    A=NULL;
    return 0;
}
