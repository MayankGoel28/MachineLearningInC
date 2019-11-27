#include <stdio.h>

int valid(int m,int array[]);
int end(int array[],int input,int parity);

int n,count = 0;

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

		if(value_of_return == 1)
			player_input(array);
		if(value_of_return == 0)
			printf("Player %d has won the game\n",parity);
		if(value_of_return == 2)
			printf("Tie\n");
	}
}

int valid(int m,int array[])
{
	int i;
	for(i=0;i<n*n;i++)
	{
		if(array[i]==m)
			return 1;
	}
	return 0;
}

int end(int array[],int input,int parity)
{
	int i,j,k;
	int x,y;
	int toggle;
	int matrix[100][100];
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			matrix[i][j]=-1;
	
	x = input/n;
	y = input%n;
	j = 0;
	
	for(i=parity;i<n;i+=2)
	{
		if(array[i]/n == x)
			j++;
	}
	if(j == n)
		return 0;
	
	j=0;
	for(i=parity;i<n;i+=2)
	{
		if(array[i]%n == y)
			j++;
	}
	if(j==n)
		return 0;
	
	j=0;
	for(i=0;i<n*n;i++)
	{
		x=array[i]/n;
		y=array[i]%n;
		matrix[x][y]=i%2;
		if(array[i]==-1)
			j=1;
	}

	toggle = 0;
	for(k=0;k<n;k++)
	{
		if(matrix[k][k] != parity)
			toggle=1;
	}
	
	if(toggle==0)
		return 0;
	
	toggle=0;
	for(k=0;k<n;k++)
	{
		if(matrix[k][n-k] != parity)
			toggle=1;
	}
	if(toggle==0)
		return 0;

	if(j==1)
		return 2;

	return 1;
}