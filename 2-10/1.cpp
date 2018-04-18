#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define GLAS "eyuioa"
#define SOGLAS "qwrtpsdfghjklzxcvbnm"

using namespace std;

main()

{
    int N,i,j;
  cout << "How many lines will be there?" << endl;
  cin >> N;

  char ch, pr[N][50];
  gets(pr[0]);
  for (i=0;i<N;i++){
    printf("Input text of %d line \n",i+1);
    gets(pr[i]);
  }


  FILE *pt, *pg, *ps;
  pt=fopen("text.txt","w");

 for (i=0;i<N;i++){
        j=0;
 while (pr[i][j]!='\0'){
  fprintf(pt,"%c",pr[i][j]);
  j++;
     }
 fprintf(pt,"\n");
 }
  fclose(pt);
  pt=fopen("text.txt","r");
  ps=fopen("sogl.txt","w");
  pg=fopen("gl.txt","w");
  while (!feof(pt))
  { ch=getc(pt);


    if (strchr(GLAS,ch)!=NULL){
        while (ch != ' ' && ch != '\n'){
            putc(ch,pg);
            ch=getc(pt);
            }
            putc(' ',pg);
    }
     if (strchr(SOGLAS,ch)!=NULL){
        while (ch != ' ' && ch != '\n'){
         putc(ch,ps);
         ch=getc(pt);
         }
         putc(' ',ps);
     }
  }
  fclose(pt);                           // Закрытие файла pr

  fclose(ps);                          // Закрытие файлов
  fclose(pg);
  getch();
}
