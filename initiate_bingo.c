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
