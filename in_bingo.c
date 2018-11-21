#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "head.h"

#define N 5 
#define M 2 

int in_bingo(int bingo[N][N], int num)
{
    int i, j;
    
	for(i=0; i<N; i++)
	{
        for(j=0; j<N; j++) 
		{
            if(bingo[i][j] == num) 
			{
                return 1;
            }
        }
    }
    
    return 0;
}

