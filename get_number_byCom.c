#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "head.h"

#define N 5 
#define M 2 

int get_number_byCom()
{
   srand((unsigned int)time(NULL));

   int selected_num;
   int i, j;

   selected_num = rand() % (N*N) + 1;
   
   printf("��ǻ�Ͱ� ������ ���� : %d\n", selected_num);
   
   return selected_num;
}

