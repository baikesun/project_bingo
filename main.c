#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define N 5 
#define M 2 

//user와 computer의 빙고판 변수  
int user_bingo[N][N];
int comp_bingo[N][N];

int initiate_bingo(int bingo[N][N]);   //빙고 테이블을 초기에 만들어줌  
int print_bingo(int bingo[N][N]);   //빙고 테이블 현재 상황을 화면에 출력  
int get_number_byMe();   //내가 빙고 번호 입력 선택  
int get_number_byCom();   //컴퓨터가 임의로 빙고 번호 선택  
void process_bingo(int bingo[N][N], int selected_num);   //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움  
void count_bingo(int bingo[N][N], int* count);   //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환

int main()
{
   //user와 computer의 빙고 수 변수  
   int user_count = 0;
   int comp_count = 0;

   int trial = 0;   //turn 세는 변수  

   int selected_num;

   srand((unsigned int)time(NULL));

   initiate_bingo(user_bingo);
   initiate_bingo(comp_bingo);
   
   //do-while을 꼭 안써도 된다면
   int user_turn = 1;   //user와 com의 턴 구분
   
   while(1)   //user_turn
   {   
      if (user_turn)
	  {
         printf("---USER BINGO---\n\n");
         
         print_bingo(user_bingo);
         
         selected_num = get_number_byMe();
         
         user_turn = 0;   //턴 넘기기
      }
      else
	  {
         selected_num = get_number_byCom();
         
         user_turn = 1;   //턴 넘기기  
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

   //승자 출력  
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

   //turn 횟수 출력  
   printf("\ntrial : %d", trial);

   return 0;
}

int initiate_bingo(int bingo[N][N])
{
   int i, j;
   int temp;
   int integer = 1;   //빙고판에 1~N*N까지의 숫자를 채워넣기 위해 사용 

   //랜덤한 숫자 2개                 
   int rand_x;
   int rand_y;

   //빙고판에 1~N*N까지의 숫자를 순서대로 채워넣음  
   for (i = 0; i<N; i++)
   {
      for (j = 0; j<N; j++)
      {
         bingo[i][j] = integer++;
      }
   }

   //채워넣은 숫자를 랜덤하게 배치  
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

int get_number_byMe()   //이미 선택된 숫자를 선택한 경우  
{
   int selected_num;   //사용자가 선택한 숫자  
   
   while (1)   //user_turn = 1
   {
      printf("숫자를 선택하시오 : ");
      scanf("%d", &selected_num);

      //사용자가 선택한 숫자가 주어진 범위 외일 경우 다시 선택하도록 함. 
      if ((selected_num > N*N) || (selected_num < 1))
      {
         printf("\n<<1부터 %d 사이의 숫자를 선택하십시오.>>", N*N);
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

   //대각선 빙고 세기  
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
