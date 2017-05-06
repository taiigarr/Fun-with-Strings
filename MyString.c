#include  "MyString.h"

//if node is null already initialized ; else make the letters of the newstring empty space, point both links to the new node and point the the string header to the newstring.

int InitializeStr(string *str) 
{
  Initialize(str);
   return 1;
}


/* checks if the string is empty by looking to see if the headers rightlink
and leftlink are pointing to itself.*/
int EmptyStr(string str) 
{
  Empty(str);
  return 1;

}


/*makes a new node and allocates its memory for the new char coming in. 
iterates through the string until given position.  Inserted when position is found*/
int InsertChar(char X, int Pos, string S)
{ 
 	Insert(X, Pos, S);
	return 1;
}	

 /*iterates through the string we are adding. String to add is then
 placed in char by char using insert char(passing it each letter 
iteration and the given position in param*/ 
int InsertString(string S, int Pos, string X)
{	
	int i, len= 0;
	Length(&len, S);
	nodetype *fromStr = S;
	fromStr = fromStr->leftlink;
	
	for(i= 0; i <len; i++)
	{
		
		InsertChar(fromStr->letter, Pos, X);
		fromStr = fromStr->leftlink;
	}
	return 1;
}

/*goes along string to add to determine beginning of substring. 
 while iterating along the string we are adding to, each character of the
 substring is added in one-by one using insertchar*/
int CopyString(string X, int Pos, int start, int end, string S)
{	
	int i, len= 0;
	len = end - start+1;
	nodetype *fromStr = S;
	// go to the starting position
	for (i = 0; i <= start; i++)
		fromStr = fromStr->leftlink;
	
	for(i = 0; i < len; i++)
	{
		InsertChar(fromStr->letter, Pos, X);
		fromStr = fromStr->leftlink;
	}
	return 1;
}

/*iterates through string and adds from the end of the string to the
 beginning of the string using insertchar.  from there using deletestring,
 the rest of the non reversed string is removed*/
 int ReverseString(string S)
{
	int i;
	int len = 0;
	nodetype *XPtr = S;
	Length(&len, S);

	for (i = 0; i <= len; i++)
	{
		InsertChar(XPtr->letter, len+1, S);
		if (XPtr->rightlink)
			XPtr = XPtr->rightlink;
		else
			return 0;
		if (XPtr->rightlink->rightlink == S)
			break;
	}
	DeleteString(1, len, S); 
	return 1;
}
 
/* Prints specified string by iterating through each character node */
int PrintString(string s)
{
	nodetype *iter = s;	
	
	while (iter->rightlink && iter->rightlink->letter && iter->rightlink != s)
	{	
		iter = iter->rightlink;
		printf ("%c", iter->letter);
	}
	printf("\n");
	return 1;
}

/*goes through the string and sets passed(dummy) char to the char at 
the usr-specified position*/
int GetChar(char *C, int Pos, string S)
{

	int i;
	nodetype *new = S;
	while (new->rightlink != NULL)
	{
		for(i = 0; i < Pos; i++)
			new = new->rightlink;
	
		if (new->letter == '\0')
		{
			printf ("#ERROR: letter not found\n");
			return 0;
		}

		*C = new->letter;
		return 1;
	}
}

/*prints usr menu*/
int PrintMenu(void)
{

	printf("\nEnter selection and arguments where\n[char] is one character, [pos] is an integer, and\n[String], [fromString] [toString] are S1, S2 or S3:\n1. InsertChar [char] [pos] [String]\n2. InsertString [fromString] [pos] [toString]\n3. DeleteChar [pos] [String]\n4. DeleteString [pos] [pos] [String]\n5. CopyString [toString] [pos] [pos] [pos] [fromString]\n6. ReverseString [String]\n7. PrintLength [String]\n8. PrintChar [pos] [String]\n9. PrintString [String]\nP. Print this menu\nX. Exit program\n");

	return 1;

}


/*delete char from specified position in string*/
int DeleteChar(int Pos, string S)
{
	Remove(Pos, S);
	return 1;
}


/* deletes characters from position first to position last (inclusive) of S*/  
int DeleteString(int first, int last, string S)
{
	int i;
	int len = 0;
	Length(&len, S);
	// if even numbered
	if (first == 1)
	{
		for (i = 1; i <= last; i++)
			if (!DeleteChar (first-1, S)) // i-1
				return 0;
		return 1;
	}
	for (i = 1; i < last; i++)
		if (!DeleteChar (first-1, S)) // i-1
			return 0;		
	return 1;
}


/* finds length of string by going through each node and incrementing a cntr.  Dummy Length var passed is modified through fn*/
int Length(int *len, string str)
{

	nodetype *iter = str;

	if (iter == NULL || iter->rightlink == NULL)	
		return 0;
	while (iter->rightlink != str)
	{

		iter = iter->rightlink;
		*len += 1;
	}

	return 1;	

}

