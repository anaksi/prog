#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#define n 3

using namespace std;

main()
{
   int i,k,j; float sh; //k-���������� ������� �������, sum- �� ����� ���������.
  struct sk {int number; int kol; int vyz;} t;  //���������� ��������� t
  struct sk vip[n];  //���������� ������� �������� mag[n]
  struct sk tmp;

  printf("\n Input info about schools \n");
  for (i=0;i<n;i++)
  {   printf("\n  School number, how many graduated, how many went to uni:  ");
     scanf("%d%d%d",&t.number,&t.kol,&t.vyz);//���������� ����������� ��������� t
      vip[i]=t; //���������� i-�� �������� ������� ��������� t �������
  }
   for(int i = 0; i < n - 1; ++i) // i - ����� �������
    {
        for(int j = 0; j < n - 1; ++j) // ���������� ���� �������
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
