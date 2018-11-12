#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initiate_bingo();   //빙고 테이블을 초기에 만들어줌 
void print_bingo();   //빙고 테이블 현재 상황을 화면에 출력 
void get_number_byMe();   //내가 빙고 번호 입력 선택 
void get_number_byCom();   //컴퓨터가 임의로 빙고 번호 선택 
void process_bingo();   //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
void count_bingo();   //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
void swap();   //선택된 숫자를 -1로 변경

int N;
int M;

int main()
{
	printf("N*N 사이즈의 빙고판을 만듭니다. N은? ");
	scanf("%d", &N);
	
	printf("몇 줄의 빙고를 만들면 끝낼까요? ");
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
	
	int rand_x = rand() % N;   //랜덤 x값 
	int rand_y = rand() % N;   //랜덤 y값 
	
	
	//배열에 1부터 N*N까지의 숫자를 넣음 
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			bingo[i][j] = count++;
		}
	 } 
	
	 //배열에 저장된 수를 랜덤하게 섞음(N번 반복) 
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

void get_number_byMe(int num)   //num은 사용자가 선택한 숫자 
{
	int selected_num = -1;   //이미 선택된 숫자(-1로 표시)
	 
	printf("숫자를 입력하시오. ");
	scanf("%d", &num);
	
	if(num = -1)
	{
		printf("이미 선택된 숫자입니다.");
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
