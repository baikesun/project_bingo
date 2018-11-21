#define N 5 
#define M 2 

int initiate_bingo(int bingo[N][N]);   //빙고 테이블을 초기에 만들어줌  
int print_bingo(int bingo[N][N]);   //빙고 테이블 현재 상황을 화면에 출력  
int get_number_byMe();   //내가 빙고 번호 입력 선택  
int get_number_byCom();   //컴퓨터가 임의로 빙고 번호 선택
int in_bingo(int bingo[N][N], int num);   //selected_num이 빙고판에 이미 있는지 확인  
void process_bingo(int bingo[N][N], int selected_num);   //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움  
void count_bingo(int bingo[N][N], int* count);   //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
