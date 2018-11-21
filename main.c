#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "head.h" 

#define N 5 
#define M 2 

//user�� computer�� ������ ����  
int user_bingo[N][N];
int comp_bingo[N][N];

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
      
      

      printf("\n");
      
      if (user_count == M || comp_count == M)
         break;
	
	  trial++;
   } 
   
   printf("---USER BINGO---\n");
   print_bingo(user_bingo);
   
   printf("---COMPUTER BINGO---\n");
   print_bingo(comp_bingo);

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
   printf("\ntrial : %d", trial/2);

   return 0;
}
