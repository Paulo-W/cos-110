string RowsColumns::encode(string sentance)
{
	
}
string RowsColumns::decode(string sentance)
{
	//calculate the side of the array and get the strings length
	//and then buckle up your seatbelts because im going to tack you for a fu%^43en rollercoaster ide throught the rest of this code
	int length= s.length();
	int size = calculateSide(length);
	
	
	//the you recieve is as messed up and tangled as a 5 year vagas marrage so pay attenetion
	//there is no way or no way I could figure out to simply just cout the array in a way that makes it look like a normal sentance again 
	//so first I changed the SENTANCE not the array
	//first lets get rid of the pattern we created when we first sent in the array into the zigzag function
	//create a new 2d aray that will initially have a copy of what we expect the 2d dynamic array to look lik but first
	//lets reverse every second row 
	//this is the zig-zag patterns secret 
	char newSentance[size][size];
	int counter=0;
	string final;
	for (int i=0; i< size;i++ )
	{
		if (i%2==0)
		{
			for (int j=0; j< size; j++)
			{
				newSentance[i][j]=sentance[counter];
				counter++;
			}
		}
		if(i%2==1) //this is how we select every second row in the new array
		{
			
			for (int j=size-1;j>=0; j-- )//and this is how we reverse the array 
			{
				//select the last element in ie the second or fourth row in the new sentance and insert into it the current counter element 
				newSentance[i][j]= sentance[counter];
				counter++;
			}
		}			
	}
	counter=0;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j< size; j++)
		{
			sentance[counter]=newSentance[i][j];
			counter++;
		}
	}
	
	counter=0;
	char array ** = createMatrix(size); 
	array (fillMatrix(array, size, sentance));
	
	for (int i=0; i< size; i++)
	{
		for (int j=0; j < size; j++ )
		{
			sentance[counter]=*(*(array +j)+i);
		}
	}
	return sentance;
	
	
	
	deleteMatrix(array, side);
}