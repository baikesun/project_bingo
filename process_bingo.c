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
