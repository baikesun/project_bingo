#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initiate_bingo();   //���� ���̺��� �ʱ⿡ ������� 
void print_bingo();   //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� 
void get_number_byMe();   //���� ���� ��ȣ �Է� ���� 
void get_number_byCom();   //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
void process_bingo();   //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä�� 
void count_bingo();   //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
void swap();   //���õ� ���ڸ� -1�� ����

int N;
int M;

int main()
{
	printf("N*N �������� �������� ����ϴ�. N��? ");
	scanf("%d", &N);
	
	printf("�� ���� ���� ����� �������? ");
	scanf("%d", &M);
	
	print_bingo(N, N);
	
	get_number_byMe(); 
}

void print_bingo()
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
	

	for(i=0; i<N; i++)
	{
	 	for(j=0; j<N; j++)
	 	{
	 		printf("%2d ", bingo[i][j]);
		}
		
		printf("\n");
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
