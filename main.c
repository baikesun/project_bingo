#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
//int�� �ƴ� ���� ����. ()�� ������������ ä��� 
void initiate_bingo();   //���� ���̺��� �ʱ⿡ ������� 
void print_bingo();   //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� 
void get_number_byMe();   //���� ���� ��ȣ �Է� ���� 
void get_number_byCom();   //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
void process_bingo();   //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä�� 
void count_bingo();   //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
void swap();   //���õ� ���ڸ� -1�� ����

 
int main()
{
	print_bingo(N, N);
	
	get_number_byMe(); 
}

void print_bingo(int i, int j)
{
	int bingo[i][j];
	int max = N*N;
	
	srand(time(NULL));
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			bingo[i][j] = 1 + (rand() % max);
			printf("%d ", bingo[i][j]);
		}
		
		printf("%d ", bingo[i][j]);
	}
}

void get_number_byMe(int num)   //num�� ����ڰ� ������ ���� 
{
	int selected_num = -1;   //�̹� ���õ� ����(-1�� ǥ��)
	 
	printf("���ڸ� �Է��Ͻÿ�. ");
	scanf("%d", &num);
	
	if(num = -1)
	{
		printf("�̹� ���õ� �����Դϴ�.");
	}
	else
	{
		swap(&num, &selected_num);
		printf("%d", selected_num);
	}
}

void swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
