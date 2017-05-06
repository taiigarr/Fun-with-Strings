int InsertChar(char X, int Pos, string S)
 { 
 	int i;
 	nodetype *new = S;
 	for (i = 0; i <= Pos; i++)
 		new = new->rightlink;
 	// got into the right position, make a new one
 	new = (nodetype *)malloc(sizeof(nodetype));
	if (new==NULL) {printf("**error**");return 0;}
	
 	new->letter = X;	
 	S->rightlink = new;
 	new->leftlink = S;
 	new->rightlink = S->leftlink;
 	S->leftlink = new;
 }
