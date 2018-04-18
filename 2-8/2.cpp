#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>


using namespace std;

main()
{
   int i,k,j,n,m; float sh; //k-количество искомых товаров, sum- их общая стоимость.

   cout << "\n How many faculties there are?" << endl;
   cin >> n;
   char fac[n][15];
   cout << "\n What are the names of faculties?" << endl;
   for (i=0; i<n; i++){
    cin >> fac[i];
   }

   int sumc[n],sums[n];

   float sumpl[n],srpl[n];
   cout << "\n How many rooms there are?" << endl;
   cin >> m;
  struct com {int num; int pl; char facu[15]; int kol;} t;  //Объявление структуры t
  struct com cc[m];  //объявление массива структур mag[n]


  printf("\n Input info about rooms \n");
  for (i=0;i<m;i++)
  {   printf("\n  Room number, area, faculty, number of people:  ");
     scanf("%d%d%s%d",&t.num,&t.pl,&t.facu,&t.kol);//Заполнение информацией структуры t
      cc[i]=t; //Присвоение i-му элементу массива структуры t целиком
  }
   for(int i = 0; i < n; i++) // i - номер прохода
    {
        sumc[i]=0;
        sums[i]=0;
        sumpl[i]=0;
        for(int j = 0; j < m ; j++) // внутренний цикл прохода
        {
            if (strcmp(fac[i],cc[j].facu)==0)
            {
                sumc[i]+=1;
                sums[i]+=cc[j].kol;
                sumpl[i]+=cc[j].pl;
            }
        }
        srpl[i]=sumpl[i]/float(sums[i]);
    }
  for (i=0;i<n;i++){


  printf("\n In %s faculty's dormitory there are %d rooms with %d students, and with average area per student %.2f ",fac[i],sumc[i],sums[i],srpl[i]);
  }
  getch();
}
