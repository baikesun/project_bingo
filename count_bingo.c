int count_bingo(int *bingo[N][N], int count)
{
	int i, j;
	int sum;   //����, ����, �밢���� ������ ���� -5�� �Ǹ� ����  
	
	//���� ���� ����  
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
	
	//���� ���� ����  
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
	
	//�밢�� ���� ����  
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
