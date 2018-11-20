void count_bingo(int bingo[N][N], int* count)
{
   (*count) = 0;
   int i, j;
   int sum;   //����, ����, �밢���� ������ ���� -5�� �Ǹ� ����  

    //���� ���� ����  
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

   //���� ���� ����  
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

   //�밢�� ���� ����  
   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         if (i == j)
         {
            sum += bingo[i][j];

            if (sum == (-1)*N)
            {
               (*count)++;
            }
         }
      }
   } 
   
   //�ݴ� �밢��(�ȵ�) 
   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         if (i + j == (N-1))
         {
            sum += bingo[i][j];

            if (sum == (-1)*N)
            {
               (*count)++;
            }
         }
      }
   } 
}
