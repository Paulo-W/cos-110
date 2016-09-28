string RowsColumns::encode(string s)
{
	
	//call the function from the class TransportationCipher to calculate the side length so that we can pass that variable to the function that craets the array
	//create the matrix by passing in side
	//fill the array passing in the side size, the array you created and finally the string
	int length= s.length();
	int side = calculateSide(length);
	char array ** = createMatrix(side); 
	array (fillMatrix(array, side, s));
	
	//so incredibly simple yet complicated
	//the purpose of this task is to read vertically instead of horizontally so what i did was swap the cols with the rows when you cout the 2d array
	//we already have the 2d array set up in TranspositionCipher so now I just simply alter the array
	//and by swithing the colums and rows around  the compiler will look over the characters vertically instead of horizontally but instead of creating a whole new 2d array i just cout how the compiler
	//would read out the array
	
	int counter=0; 
	for (int rows= 0; rows < side; rows++)
	{
		for (int cols=0; cols< side; cols++)
		{
			s[counter]=*(*(array +cols)+rows);
			counter++;
		}
	}
	return s;
}
string RowsColumns::decode(string s)
{
	int length= s.length();
	int side = calculateSide(length);
	char array ** = createMatrix(side); 
	array (fillMatrix(array, side, s));
	int square= side * side;
	
	int counter=0; 
	for (int rows= 0; rows < side; rows++)
	{
		for (int cols=0; cols< side; cols++)
		{
			s[counter]=*(*(array +rows)+cols);
		}
	}
	return string;
	//therefore doing the oppposite in the decode function cause the compilerto read the characters normally again 
	//so just swapp rows and colums again 
	
	
	try 
	{
		if (length < square)
		{
			throw ("Incompatible text length");
		}
	}
	catch (const char* msg)
	{
		cout<< msg << endl;
	}
	
	
	deleteMatrix(array, side)
	
}