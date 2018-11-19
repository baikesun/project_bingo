#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define N 5 
#define M 2 
 
//user와 computer의 빙고판 변수  
int user_bingo[N][N];
int comp_bingo[N][N];

//user와 computer의 빙고 수 변수  
int user_count = 0;
int comp_count = 0;

int main()
{
	int trial=0;   //turn 세는 변수  
	
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
		 
		process_bingo(user_bingo, selected_num);
		process_bingo(comp_bingo, selected_num);
		
		count_bingo(&user_bingo[N][N], user_count);
		count_bingo(&comp_bingo[N][N], comp_count);	
		
		trial++;
		
		printf("\n");
	}
	while((user_count != M) && (comp_count != M));
	
	//승자 출력  
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
	
	//turn 횟수 출력  
	printf("\ntrial : %d", trial);
	
	return 0;
}

int initiate_bingo(int bingo[N][N])
{
	int i, j;
	int temp;
	int integer = 1;   //빙고판에 1~N*N까지의 숫자를 채워넣기 위해 사용 
	 
	//랜덤한 숫자 2개  
	int rand_x;
	int rand_y;
	
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
}

int get_number_byCom()
{
	srand((unsigned int) time(NULL));
	
	int selected_num;
	
	selected_num = rand() % (N*N) + 1;
	
	//이미 선택된 숫자일 경우 함수 다시 실행  
}

int process_bingo(int bingo[N][N], int selected_num)
{
	int i, j;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(bingo[i][j] == selected_num)
			{
				bingo[i][j] = -1;
			}
		}
	}
}

int count_bingo(int *bingo[N][N], int count)
{
	int i, j;
	int sum;   //가로, 세로, 대각선의 숫자의 합이 -5가 되면 빙고  
	
	//가로 빙고 세기  
	for(i=0; i<N; i++)
	{
		sum = 0;
		
		for(j=0; j<N; j++)
		{
			sum += &bingo[j][i];
			
			if(sum == (-1)*N)
			{
				count++;
			}
		}
	}
	
	//세로 빙고 세기  
	for(i=0; i<N; i++)
	{
		sum = 0;
		
		for(j=0; j<N; j++)
		{
			sum += &bingo[i][j];
			
			if(sum == (-1)*N)
			{
				count++;
			}
		}
	}
	
	//대각선 빙고 세기  
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i == j)
			{
				sum += &bingo[i][j];
				
				if(sum == (-1)*N)
				{
					count++;
				}
			}
		}
	}
	
	printf("%d ", count);
}
