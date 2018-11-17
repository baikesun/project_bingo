#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
#define N 5 
#define M 2 
 
int initiate_bingo(int bingo[N][N]);   //���� ���̺��� �ʱ⿡ �������  
int print_bingo(int bingo[N][N]);   //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���  
int get_number_byMe();   //���� ���� ��ȣ �Է� ����  
int get_number_byCom();   //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����  
int process_bingo();   //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��  
int count_bingo(int bingo[N][N], int count);   //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
void swap(int *a, int *b);
 
//user�� computer�� ������ ����  
int user_bingo[N][N];
int comp_bingo[N][N];

//user�� computer�� ���� �� ����  
int user_count = 0;
int comp_count = 0;

int main()
{
	int trial=0;   //turn ���� ����  
	
	int selected_num;
	
	srand((unsigned int) time(NULL));
	
	initiate_bingo(user_bingo);
	initiate_bingo(comp_bingo);
	
	do
	{
		printf("---USER BINGO---\n\n");
		print_bingo(user_bingo);
		
		selected_num = get_number_byMe();
		
		process_bingo(user_bingo, selected_num);
		process_bingo(comp_bingo, selected_num);
	
		selected_num = get_number_byCom();
		
		printf("\ncomputer number : %d\n", selected_num);
		
		//������� ����  
		process_bingo(user_bingo, selected_num);
		process_bingo(comp_bingo, selected_num);
		
		print_bingo(user_bingo);
		printf("\n");
		print_bingo(comp_bingo);
		
		trial++;
		
		count_bingo(user_bingo[N][N], user_count);
		count_bingo(comp_bingo[N][N], comp_count);		
	}
	while((user_count != M) && (comp_count != M));
	
	//���� ���  
	if((user_count == M) && (comp_count != M))
	{
		printf("USER WIN");
	}
	else if((user_count != M) && (comp_count == M))
	{
		printf("COMPUTER WIN");
	}
	else if((user_count == M) && (comp_count == M))
	{
		printf("DRAW");
	}
	
	//turn Ƚ�� ���  
	printf("\ntrial : %d", trial);
	
	return 0;
}

int initiate_bingo(int bingo[N][N])
{
	int i, j;
	int temp;
	int integer = 1;   //�����ǿ� 1~N*N������ ���ڸ� ä���ֱ� ���� ��� 
	 
	//������ ���� 2��  
	int rand_x;
	int rand_y;
	
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
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf(" %2d ", bingo[i][j]);
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
}

int get_number_byCom()
{
	srand((unsigned int) time(NULL));
	
	int selected_num;
	
	selected_num = rand() % (N*N) + 1;
	
	//�̹� ���õ� ������ ��� �Լ� �ٽ� ����  
}

int process_bingo(int bingo[N][N], int selected_num)
{
	int i, j;
	int completed_num = -1;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(bingo[i][j] == selected_num)
			{
				swap(&selected_num, &completed_num);
			}
		}
	}
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
	int sum = 0;   //����, ����, �밢���� ������ ���� -5�� �Ǹ� ����  
	
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
