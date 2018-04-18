#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#define n 3

using namespace std;

main()
{
   int i,k,j; float sh; //k-количество искомых товаров, sum- их общая стоимость.
  struct sk {int number; int kol; int vyz;} t;  //Объявление структуры t
  struct sk vip[n];  //объявление массива структур mag[n]
  struct sk tmp;

  printf("\n Input info about schools \n");
  for (i=0;i<n;i++)
  {   printf("\n  School number, how many graduated, how many went to uni:  ");
     scanf("%d%d%d",&t.number,&t.kol,&t.vyz);//Заполнение информацией структуры t
      vip[i]=t; //Присвоение i-му элементу массива структуры t целиком
  }
   for(int i = 0; i < n - 1; ++i) // i - номер прохода
    {
        for(int j = 0; j < n - 1; ++j) // внутренний цикл прохода
        {
            if (vip[j+1].vyz < vip[j].vyz)
            {
                tmp = vip[j + 1];
                vip[j + 1] = vip[j];
                vip[j] = tmp;
            }
        }
    }
  for (i=0;i<n;i++){
        sh=(float(vip[i].vyz))/(float(vip[i].kol));

  printf("\n %d graduated from school %d, share of those, who went to uni = %.2f % ",vip[i].kol,vip[i].number,sh);
  }
  getch();
}
