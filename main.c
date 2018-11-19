#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define N 5 
#define M 2 

//user�� computer�� ������ ����  
int user_bingo[N][N];
int comp_bingo[N][N];

int initiate_bingo(int bingo[N][N]);   //���� ���̺��� �ʱ⿡ �������  
int print_bingo(int bingo[N][N]);   //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���  
int get_number_byMe();   //���� ���� ��ȣ �Է� ����  
int get_number_byCom();   //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����  
void process_bingo(int bingo[N][N], int selected_num);   //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��  
void count_bingo(int bingo[N][N], int* count);   //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ

int main()
{
   //user�� computer�� ���� �� ����  
   int user_count = 0;
   int comp_count = 0;

   int trial = 0;   //turn ���� ����  

   int selected_num;

   srand((unsigned int)time(NULL));

   initiate_bingo(user_bingo);
   initiate_bingo(comp_bingo);
   
   //do-while�� �� �Ƚᵵ �ȴٸ�
   int user_turn = 1;   //user�� com�� �� ����
   
   while(1)   //user_turn
   {   
      if (user_turn)
	  {
         printf("---USER BINGO---\n\n");
         
         print_bingo(user_bingo);
         
         selected_num = get_number_byMe();
         
         user_turn = 0;   //�� �ѱ��
      }
      else
	  {
         selected_num = get_number_byCom();
         
         user_turn = 1;   //�� �ѱ��  
      }
      
      process_bingo(user_bingo, selected_num);
      process_bingo(comp_bingo, selected_num);

      count_bingo(user_bingo, &user_count);
      count_bingo(comp_bingo, &comp_count);
      
      trial++;

      printf("\n");
      
      if (user_count == M || comp_count == M)
         break;
   } 

   //���� ���  
   if ((user_count == M) && (comp_count != M))
   {
      printf("<<USER WIN>>");
   }
   else if ((user_count != M) && (comp_count == M))
   {
      printf("<<COMPUTER WIN>>");
   }
   else if ((user_count == M) && (comp_count == M))
   {
      printf("<<DRAW>>");
   }

   //turn Ƚ�� ���  
   printf("\ntrial : %d", trial);

   return 0;
}

int initiate_bingo(int bingo[N][N])
{
   int i, j;
   int temp;
   int integer = 1;   //�����ǿ� 1~N*N������ ���ڸ� ä���ֱ� ���� ��� 

   //������ ���� 2��                 
   int rand_x;
   int rand_y;

   //�����ǿ� 1~N*N������ ���ڸ� ������� ä������  
   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         bingo[i][j] = integer++;
      }
   }

   //ä������ ���ڸ� �����ϰ� ��ġ  
   for (i = 0; i<N; i++)
   {
      for (j = 0; j<(N - 2); j++)
      {
         rand_x = rand() % N;
         rand_y = rand() % N;

         temp = bingo[i][j];
         bingo[i][j] = bingo[rand_x][rand_y];
         bingo[rand_x][rand_y] = temp;
      }
   }
}

int print_bingo(int bingo[N][N])
{
   int i, j;

   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         printf(" %2d ", bingo[i][j]);
      }

      printf("\n\n");
   }
}

int get_number_byMe()   //�̹� ���õ� ���ڸ� ������ ���  
{
   int selected_num;   //����ڰ� ������ ����  
   
   while (1)   //user_turn = 1
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

int get_number_byCom()
{
   srand((unsigned int)time(NULL));

   int selected_num;
   int i, j;

   selected_num = rand() % (N*N) + 1;
   /*
   for(i=0; i<N; i++)
   {
   		for(j=0; j<N; j++)
   		{
   			if(selected_num != bingo[i][j])
   			{
   				get_number_byCom();
			}
		}
	} 
   */
   return selected_num;
     
}

void process_bingo(int bingo[N][N], int selected_num)
{
   int i, j;

   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         if (bingo[i][j] == selected_num)
         {
            bingo[i][j] = -1;
         }
      }
   }
}

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
}
