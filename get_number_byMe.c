int get_number_byMe()
{
	int selected_num;   //사용자가 선택한 숫자  
	
	printf("숫자를 선택하시오 : ");
	scanf("%d", &selected_num);
	
	//사용자가 선택한 숫자가 주어진 범위 외일 경우 다시 선택하도록 함. 
	if((selected_num > N*N) || (selected_num <1))
	{
		printf("\n<<1부터 %d 사이의 숫자를 선택하십시오.>>", N*N);
		printf("\n");
		
		get_number_byMe(); 
	}
}
