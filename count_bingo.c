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
			
			if(sum == -5)
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
			
			if(sum == -5)
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
				
				if(sum == -5)
				{
					count++;
				}
			}
		}
	}
}
