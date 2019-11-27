#include<stdlib.h>
#include<time.h>
using namespace std
void generateset(long long int n)     //function to generate the set of possibilities
{
	long long int x,i,j,flag=1,redcheck=0,endcheck=0,validcheck=0;
	int tic[9];                     //using linear array as it would be easier.array stores the moves done sequentially
	for(i=0;i<n;i++)
	{
reset:
		for(j=0;j<9;j++)                  //loop to reset the values of the array to 0
		{
			tic[j]=0;
		}
		for(j=0;j<9;j++)
		{
notvalid:
			x=rand()%9;
			if(flag==1)                  //flag checks whose move it is and assigns the respective value to it
			{                            //flag==1 means it is player 1's move 
				validcheck=valid(tic,x);
				if(validcheck==1)
				{
					goto notvalid;
				}
				tic[j]=x;
				flag=2;                  //setting flag to other player
			}
			else
			{
				validcheck=valid(tic,x);
				if(validcheck==1)
				{
					goto notvalid;
				}
				tic[j]=x;                //player 2's move
				flag=1;
			}
			redcheck=check(tic);              //check for redundancies in the current state of the game
			if(redcheck==1)
			{
				i++;
				goto reset;                   //if redundancy is detected reset to start again i++ is to not let redundancies to let it go in infinite loop
			}
			endcheck=end(tic);                //check if the game has ended
			if(endcheck==1)
			{
				i++;
				store(tic);                   //if game has ended then store it and break out of the loop
				break;
			}
		}
	}
}
int main()
{
	long long int n;
	srand(time(0));
	cout<<"how many times do u want to generate it?";
	cin>>n;
	generateset(n);
	cout<<"\ngenerated the file for "<<n<<"times.";
	return 0;
}
