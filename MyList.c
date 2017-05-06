#include "MyList.h"

//if node is null already initialized ; else make the letters of the newstring empty space, point both links to the new node and point the the string header to the newstring.

int Initialize(string *str) {
   nodetype *new = (nodetype *)malloc(sizeof(nodetype));
   if (new==NULL) {printf("**error**");return 0;}
   new->leftlink=new;
   new->rightlink=new;
   *str=new;
   return 1;
}
//checks if string is empty by checkking if the rightmost character is pointing to the the string node and if the heads is pointing to itself.
int Empty(string str) {
   if (str->rightlink==str && str->leftlink==str) 
		return 1;
   return 0;
}

/*inserts char by checking for the three ways to insert (into empty list,
into middle of the string, into the last position)*/
int Insert(char X, int Pos, string S)
 { 
 	int i;

 	nodetype *new;
	nodetype *prev = S;

  	new = (nodetype *)malloc(sizeof(nodetype));
	if (new==NULL) {perror("malloc");return 0;}

	new->letter = X;

	for(i = 0; i < Pos-1; i++)
		prev = prev->rightlink;
	
	//first char to insert 
	if (Empty(S))
	{
		new->leftlink = S;
		new->rightlink = S;
		S->rightlink = new;
		S->leftlink = new; 
		return 1;	

	}
	
	else
	{
			//if end of the string	
			if(prev->rightlink == S)
			{
				prev->rightlink = new;
				new->leftlink = prev;
				new->rightlink = S;
				S->leftlink = new;			
				return 1;	
			}		
			//middle of string	
			else
			{	
				prev->rightlink->leftlink = new;
				new->rightlink = prev->rightlink;
				prev->rightlink = new;
				new->leftlink = prev;
				return 1;
			}
			
	}	
 	return 1;
 }

/*removes chars from given position */
int Remove(int Pos, string S)
{
	int i;
	nodetype *iter = S; // fix
	nodetype *temp ;
	temp = (nodetype *) malloc(sizeof(nodetype*));
	
	// check for empty string
	if(Empty(S)) 
	{	
		printf("#ERROR: nothing to remove\n"); 
		return 0;
	}
	
	// iterate and check for wrong position
	for (i = 0; i <= Pos; i++)
	{
		if (iter && iter->rightlink && iter->rightlink->letter)
			iter = iter->rightlink;
		else
		{
			printf("#ERROR: invalid string or argument [pos]\n");
			return 0;			
		}	
	}

	temp = iter;
	iter->leftlink->rightlink = iter->rightlink;
	iter->rightlink->leftlink = iter->leftlink;

	free(temp);
	return 1;

}


