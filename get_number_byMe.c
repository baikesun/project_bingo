#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "head.h"

#define N 5 
#define M 2

int get_number_byMe()   //�̹� ���õ� ���ڸ� ������ ���  
{
   int selected_num;   //����ڰ� ������ ����  
   
   while (1) 
   {
      printf("���ڸ� �����Ͻÿ� : ");
      scanf("%d", &selected_num);

      //����ڰ� ������ ���ڰ� �־��� ���� ���� ��� �ٽ� �����ϵ��� ��. 
      if ((selected_num > N*N) || (selected_num < 1))
      {
         printf("\n<<1���� %d ������ ���ڸ� �����Ͻʽÿ�.>>", N*N);
         printf("\n");
         
         continue;
      }
      
      break;
   }
   
   return selected_num;
}
