#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
#define N 5 
#define M 2 
 
int initiate_bingo();   //���� ���̺��� �ʱ⿡ �������  
int print_bingo();   //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���  
int get_number_byMe();   //���� ���� ��ȣ �Է� ����  
int get_number_byCom();   //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����  
int process_bingo();   //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��  
int count_bingo(int bingo[N][N], int count);   //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
void swap();   //���õ� ���ڸ� -1�� ���� 

//user�� computer�� ������  
int user_bingo[N][N];
int comp_bingo[N][N];

//user�� computer�� ���� �� ����  
int user_count = 0;
int comp_count = 0;

int main()
{
	int trial=0;   //turn ���� ����  
	
	srand((unsigned int) time(NULL));
	
	initiate_bingo(user_bingo);
	initiate_bingo(comp_bingo);
	
	do
	{
		print_bingo(user_bingo);
		print_bingo(comp_bingo);
	
		get_number_byMe();
		
		process_bingo(user_bingo);
		process_bingo(comp_bingo);
		
		get_number_byCom();
		
		process_bingo(user_bingo);
		process_bingo(comp_bingo);
		
		trial++;
		
		count_bingo(user_bingo[N][N], user_count);
		count_bingo(comp_bingo[N][N], comp_count);		
	}
	while((user_count=M) || (comp_count=M));
	
	if(user_count = M)
	{
		printf("USER WIN");
	}
	else if(comp_count = M)
	{
		printf("COMPUTER WIN");
	}
	
	printf("trial : %d", trial);
	
	return 0;
}

int initiate_bingo(int bingo[N][N])
{
	int i, j;
	int temp;
	int integer = 1;
	
	srand((unsigned int) time(NULL));
	 
	int rand_x = rand() % N + 1;
	int rand_y = rand() % N + 1;
	
	//�����ǿ� 1~N*N������ ���ڸ� ������� ä������  
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			bingo[i][j] = integer++;
		}
	}
	
	//ä������ ���ڸ� �����ϰ� ��ġ  
	for(i=0; i<N; i++)
	{
		for(j=0; j<(N-2); j++)
		{
			temp = bingo[i][j];
			bingo[i][j] = bingo[rand_x][rand_y];
			bingo[rand_x][rand_y] = temp;
		}
	}
}

int print_bingo(int bingo[N][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%2d ", bingo[i][j]);
		}
		
		printf("\n\n");
	}
}

int get_number_byMe()
{
	int selected_num;   //����ڰ� ������ ����  
	
	printf("���ڸ� �����Ͻÿ� : ");
	scanf("%d", &selected_num);
	
	//����ڰ� ������ ���ڰ� �־��� ���� ���� ��� �ٽ� �����ϵ��� ��. 
	if((selected_num > N*N) || (selected_num <1))
	{
		printf("\n<<1���� %d ������ ���ڸ� �����Ͻʽÿ�.>>", N*N);
		printf("\n");
		
		get_number_byMe(); 
	}
	
	process_bingo(selected_num);
}

int get_number_byCom()
{
	srand((unsigned int) time(NULL));
	
	int selected_num;
	
	selected_num = rand() % N*N + 1;
	
	process_bingo(selected_num);
}

int process_bingo(int selected_num)
{
	int completed_num = -1;   //�̹� ���õ� ����  
	
	swap(&selected_num, &completed_num);
	
	print_bingo(bingo[N][N]); 
}

void swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int count_bingo(int bingo[N][N], int count)
{
	int i, j;
	int sum = 0;
	
	//���� ���� ����  
	for(i=0; i<N; i++)
	{
		sum += bingo[N][i];
		
		if(sum = -5)
		{
			count++;
		}
	}
	
	//���� ���� ����  
	for(i=0; i<N; i++)
	{
		sum += bingo[i][N];
		
		if(sum = -5)
		{
			count++;
		}
	}
	
	//�밢�� ���� ����  
	for(i=0; i<N; i++)
	{
		sum += bingo[i][i];
		
		if(sum = -5)
		{
			count++;
		}
	}
}
