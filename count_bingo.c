#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "head.h"

#define N 5 
#define M 2 

void count_bingo(int bingo[N][N], int* count)
{
   (*count) = 0;
   int i, j;
   int sum;   //가로, 세로, 대각선의 숫자의 합이 -5가 되면 빙고  

    //세로 빙고 세기  
   for (i = 0; i<N; i++)
   {
      sum = 0;

      for (j = 0; j<N; j++)
      {
         sum += bingo[j][i];

         if (sum == (-1)*N)
         {
            (*count)++;
         }
      }
   }

   //가로 빙고 세기  
   for (i = 0; i<N; i++)
   {
      sum = 0;

      for (j = 0; j<N; j++)
      {
         sum += bingo[i][j];

         if (sum == (-1)*N)
         {
            (*count)++;
         }
      }
   }

	sum = 0;
	
   //대각선 빙고 세기  
   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         if (i == j)
         {
            sum += bingo[i][j];
         }
      }
   } 
   
   if (sum == (-1)*N)
   {
       (*count)++;
   }
    
    sum=0;
    
   //반대 대각선(안됨) 
   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         if (i + j == (N-1))
         {
            sum += bingo[i][j];
         }
      }
   } 
   
   if (sum == (-1)*N)
   {
    	(*count)++;
   }
}
