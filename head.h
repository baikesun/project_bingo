#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define N 5 
#define M 2 

int initiate_bingo(int bingo[N][N]);   //���� ���̺��� �ʱ⿡ �������  
int print_bingo(int bingo[N][N]);   //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���  
int get_number_byMe();   //���� ���� ��ȣ �Է� ����  
int get_number_byCom();   //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����  
void process_bingo(int bingo[N][N], int selected_num);   //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��  
void count_bingo(int bingo[N][N], int* count);   //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
