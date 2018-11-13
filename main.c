#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 2

int initiate_bingo();   //���� ���̺��� �ʱ⿡ ������� 
int print_bingo();   //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� 
void get_number_byMe();   //���� ���� ��ȣ �Է� ���� 
void get_number_byCom();   //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
void process_bingo();   //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä�� 
void count_bingo();   //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
void swap();   //���õ� ���ڸ� -1�� ����

int main()
{
	printf("<<������� ������>>\n");
	
	initiate_bingo(N, N);
	
	get_number_byMe();
}

int initiate_bingo()
{
	srand(time(NULL));
	
	int bingo[N][N];
	int i, j, k, temp;
	int count = 1;
	
	int rand_x = rand() % N;   //���� x�� 
	int rand_y = rand() % N;   //���� y�� 
	
	
	//�迭�� 1���� N*N������ ���ڸ� ���� 
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			bingo[i][j] = count++;
		}
	 } 
	
	 //�迭�� ����� ���� �����ϰ� ����(N�� �ݺ�) 
	for(k=0; k<N; k++)
	{
		for(i=0; i<N; i++)
		{
	 		for(j=0; j<N; j++)
	 		{
	 			temp = bingo[i][j];
	 			bingo[i][j] = bingo[rand_x][rand_y];
	 			bingo[rand_x][rand_y] = temp;
			}
		}
	}
	
	//������ ��� 
	for(i=0; i<N; i++)
	{
	 	for(j=0; j<N; j++)
	 	{
	 		printf("%2d ", bingo[i][j]);
		}
		
		printf("\n\n");
	}
	
	return bingo[N][N];
}
/*
void print_bingo()
{
	
}
*/
void get_number_byMe(int num)   //num�� ����ڰ� ������ ���� 
{
	int selected_num = -1;   //�̹� ���õ� ����(-1�� ǥ��)
	
	printf("���ڸ� �����Ͻÿ�. ");
	scanf("%d", &num);
	
	if(num !=-1)
	{
		swap(&num, &selected_num);
		
		// print_bingo();		
	}
	else
	{
		printf("�̹� ���õ� �����Դϴ�.");
	}
}

void swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
