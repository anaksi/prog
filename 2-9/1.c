#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int N=4;

typedef struct st {
    char surname[12];
    int grades[N];
    struct st *next;
} slist;

int more(char* s1, char* s2){
    int x=0;
    while(s1[x]==s2[x] && x<strlen(s1) && x<strlen(s2)){
        x++;
    }
    if (x==strlen(s1)) return 0;
    if (x==strlen(s2)) return 1;
    if (s1[x]>s2[x]) return 1;
    return 0;
}

slist* killretards(slist *head){
    int headset=0;
    slist *cur,*prev;
    while(!headset && head!=NULL){
        headset=1;
        for(int i=0;i<N;i++){
            if (head->grades[i]<3){
                head=head->next;
                headset=0;
                break;
            }
        }
    }
    printf("\nHEADSET\n");
    prev=head;
    cur=prev->next;
    while(cur!=NULL){
        for(int i=0;i<N;i++){
            if (cur->grades[i]<3){
                printf("\n\n***%s killed***\n\n",cur->surname);
                prev->next=cur->next;
                break;
            }
        }
        prev=prev->next;;
        if (cur->next!=NULL) cur=prev->next; else break;
    }
    return head;
}

void sortlist(slist *head){
    int all=0,t;
    slist *cur;
    char tmp[12];

    cur=head;
    while (cur!=NULL) cur=cur->next,all++;
    slist *arr[all];
    cur=head;
    for (int i=0;i<all;i++){
        arr[i]=cur;
        cur=cur->next;
    }
    for(int i=0;i<all-1;i++)
        for(int j=all-2;j>=i;j--){
            if (more(arr[j]->surname,arr[j+1]->surname)){
                strcpy(tmp,arr[j]->surname);
                strcpy(arr[j]->surname,arr[j+1]->surname);
                strcpy(arr[j+1]->surname,tmp);
                for(int k=0;k<N;k++){
                    t=arr[j]->grades[k];
                    arr[j]->grades[k]=arr[j+1]->grades[k];
                    arr[j+1]->grades[k]=t;
                }
            }
        }
}

slist* create(){
    int i=1,tot;
    slist *cur,*prev,*first;//cur - current
    first=prev=new slist;
    printf("Total amount of students: ");
    scanf("%d",&tot);
    printf("Surname 1: ");
    scanf("%s",prev->surname);
    for(int j=0;j<N;j++) prev->grades[j]=rand()%10+1;
    while(i<tot){
        cur=new slist;
        printf("Surname %d: ",i+1);
        scanf("%s",cur->surname);
        for(int j=0;j<N;j++) cur->grades[j]=rand()%10+1;
        prev->next=cur;
        prev=cur;
        i++;
    }
    cur->next=NULL;
    return first;
}

void printlist(slist *head){
    printf("\nList:\n");
    slist *cur;
    cur=head;
    while (cur!=NULL){
        printf("%s: ",cur->surname);
        for (int i=0;i<N;i++) printf("%d, ",cur->grades[i]);
        printf("\n");
        cur=cur->next;
    }
}

void deletelist(slist *head){
    slist *p,*q;
    q=p=head;
    while (p!=NULL){
        p=q->next;
        delete q;
        q=p;
    }
    head=NULL;
}

int main(){
    //srand(time(NULL));
    system("clear");//system("cls");
    slist *head;
    head=create();
    sortlist(head);
    printlist(head);
    head=killretards(head);
    printlist(head);
    deletelist(head);
    return 0;
}
