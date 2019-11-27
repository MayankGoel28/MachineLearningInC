void store(char string[]){
	//Stores each string in storage.txt after binary searching for the optimum place to put it, and shifting all other strigs in file afterwards
	while(l<r){
		int m=l+(r-l)/2;
		if(strcmp(string,stringToCheck)<=-1){l=m;}//in this line, store a cursor position called "cursor"
		else {r=m;}
	}
	//fprintf "string" after the line of cursor
}