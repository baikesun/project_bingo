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
