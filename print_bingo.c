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
