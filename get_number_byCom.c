int get_number_byCom()
{
   srand((unsigned int)time(NULL));

   int selected_num;
   int i, j;

   selected_num = rand() % (N*N) + 1;
   
   if(selected_num)
   
   printf("컴퓨터가 선택한 숫자 : %d\n", selected_num);
   
   return selected_num;
}

