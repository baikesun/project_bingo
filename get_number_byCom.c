#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "head.h"

#define N 5 
#define M 2

int get_number_byCom(int bingo[N][N])
{
    int selected_num, flag;
    srand(time(NULL));

    selected_num = rand() % (N * N) + 1;
    
    flag = in_bingo(bingo, selected_num);
    
    while (!flag)
    {
        selected_num = rand() % (N * N) + 1;
        
        flag = in_bingo(bingo, selected_num);
    }

    printf("��ǻ�Ͱ� ������ ���� : %d\n", selected_num);

    return selected_num;
}
