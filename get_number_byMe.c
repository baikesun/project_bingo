int get_number_byMe()
{
	int selected_num;   //����ڰ� ������ ����  
	
	printf("���ڸ� �����Ͻÿ� : ");
	scanf("%d", &selected_num);
	
	//����ڰ� ������ ���ڰ� �־��� ���� ���� ��� �ٽ� �����ϵ��� ��. 
	if((selected_num > N*N) || (selected_num <1))
	{
		printf("\n<<1���� %d ������ ���ڸ� �����Ͻʽÿ�.>>", N*N);
		printf("\n");
		
		get_number_byMe(); 
	}
}
