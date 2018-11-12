#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
//int형 아닐 수도 있음. ()안 변수선언으로 채우기 
void initiate_bingo();   //빙고 테이블을 초기에 만들어줌 
void print_bingo();   //빙고 테이블 현재 상황을 화면에 출력 
void get_number_byMe();   //내가 빙고 번호 입력 선택 
void get_number_byCom();   //컴퓨터가 임의로 빙고 번호 선택 
void process_bingo();   //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
void count_bingo();   //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
void swap();   //선택된 숫자를 -1로 변경

 
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
