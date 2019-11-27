int count=0;
int player_input(int array[])						//	player can be user or CPU
{
	int parity,value_of_return;
	printf("\nEnter input index:\t");	//	array input is zero indexed
	scanf("%d",&input);
	if(valid(input,array) == 1)
	{
		printf("\nInvalid Input");
		player_input(array);
	}
	else
	{
		array[count] = input;
		parity = count%2;
		value_of_return = end(array,input,parity);
		count++;
		record(array);

		if(value_of_return == 1)
			player_input(array);
		if(value_of_return == 0)
			printf("Player %d has won the game\n",parity);
		if(value_of_return == 2)
			printf("Tie\n");
	}
}