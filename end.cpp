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