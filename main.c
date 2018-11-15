#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
#define N 5 
#define M 2 
 
int initiate_bingo();   //빙고 테이블을 초기에 만들어줌  
int print_bingo();   //빙고 테이블 현재 상황을 화면에 출력  
int get_number_byMe();   //내가 빙고 번호 입력 선택  
int get_number_byCom();   //컴퓨터가 임의로 빙고 번호 선택  
int process_bingo();   //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움  
int count_bingo(int bingo[N][N], int count);   //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
void swap();   //선택된 숫자를 -1로 변경 

//user와 computer의 빙고판  
int user_bingo[N][N];
int comp_bingo[N][N];

//user와 computer의 빙고 수 변수  
int user_count = 0;
int comp_count = 0;

int main()
{
	int trial=0;   //turn 세는 변수  
	
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
	
	//빙고판에 1~N*N까지의 숫자를 순서대로 채워넣음  
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			bingo[i][j] = integer++;
		}
	}
	
	//채워넣은 숫자를 랜덤하게 배치  
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
	int selected_num;   //사용자가 선택한 숫자  
	
	printf("숫자를 선택하시오 : ");
	scanf("%d", &selected_num);
	
	//사용자가 선택한 숫자가 주어진 범위 외일 경우 다시 선택하도록 함. 
	if((selected_num > N*N) || (selected_num <1))
	{
		printf("\n<<1부터 %d 사이의 숫자를 선택하십시오.>>", N*N);
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
	int completed_num = -1;   //이미 선택된 숫자  
	
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
	
	//가로 빙고 세기  
	for(i=0; i<N; i++)
	{
		sum += bingo[N][i];
		
		if(sum = -5)
		{
			count++;
		}
	}
	
	//세로 빙고 세기  
	for(i=0; i<N; i++)
	{
		sum += bingo[i][N];
		
		if(sum = -5)
		{
			count++;
		}
	}
	
	//대각선 빙고 세기  
	for(i=0; i<N; i++)
	{
		sum += bingo[i][i];
		
		if(sum = -5)
		{
			count++;
		}
	}
}
