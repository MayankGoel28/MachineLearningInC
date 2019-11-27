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