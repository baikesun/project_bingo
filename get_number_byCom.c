int get_number_byCom()
{
   srand((unsigned int)time(NULL));

   int selected_num;
   int i, j;

   selected_num = rand() % (N*N) + 1;
   
   if(selected_num)
   
   printf("��ǻ�Ͱ� ������ ���� : %d\n", selected_num);
   
   return selected_num;
}

