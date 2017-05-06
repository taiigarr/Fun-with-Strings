#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "MyList.h"
#define MAX 200

/* Obtains string(s) requested by the user.
Note that a max of two strings are obtained 
from one single call to this function.
*/
void getNextString(char* str, string *SPtr, string *SPtr2, string S1, string S2, string S3);

int main(void)
{
 	int index = 0;
 	string S1, S2, S3;
 	string S, SI; // proxy strings
	char str[MAX] = "";
	int slen = 0;
	char dummy = '\0';
 	
	S1 = (string) malloc(sizeof(string));
	S2 = (string) malloc(sizeof(string));
	S3 = (string) malloc(sizeof(string));
	
	Initialize(&S1);
	Initialize(&S2);
	Initialize(&S3);	
	
	InsertChar('T', 1, S1);
	InsertChar('I', 2, S1);
	InsertChar('f', 3, S1);
	//InsertChar('f', 4, S1);
	
	InsertChar('M', 1, S2);
	InsertChar('I', 2, S2);
	InsertChar('L', 3, S2);
	InsertChar('O', 4, S2);
	InsertChar('S', 4, S2);
	
	PrintMenu();	
	
	while(1){	
		slen = 0;
		//scanf( "%[^\n]\n", str );
		fgets (str, MAX, stdin);
		getNextString(str, &S, &SI, S1, S2, S3);
		//printf("%s\n", str);
		int i;

			switch(str[0])
			{
			  case '1':
		   		 index  = str[4] - '0';
				 InsertChar(str[2], index, S); // ,str[6]
				 break;		
			  case '2':
				 index  = str[5] - '0';
				 InsertString(S, index, SI);
				 break;
			  case '3':
			  	 index = str[2] - '0';
				 DeleteChar(index-1, S);
				 break;
			  case '4':
				 DeleteString(str[2]-'0', str[4]-'0', S);
				 break;
			  case '5':
			     index  = str[5] - '0';
				 CopyString(S, index, str[7]-'0', str[9]-'0', SI);
				 break;
			  case '6':
				 ReverseString(S);			
				 break;
			  case '7':
				 Length(&slen, S);
				 printf ("%d\n", slen);
				 break;
			  case '8':
			  	 GetChar(&dummy,str[2],S);
	   			 printf("%c\n", dummy);
				 break;
			  case '9':
				 PrintString(S);
				 break;
			  case 'P':
				 PrintMenu();
				 break;
			  case 'X':
				     exit(0); // exit code 0 means good
				     break;
			  default:
				printf("USAGE:\n");
				PrintMenu();
				break;		
			}	
	}

	//PrintString(S1);	
	return 1;
}


void getNextString(char* str, string *SPtr, string *SPtr2, string S1, string S2, string S3)
{
	//string *curPtr = SPtr;
	int i;
	int isFirst = 1;
	for (i = 0; i < strlen(str)-1; i++)
	{
		//#TODO: determine string S
		if (isFirst && str[i] == 'S' && isdigit(str[i+1]) )
		{
			isFirst = 0;
		   	switch(str[i+1])
		  	 {
		  	 case '1':
		  	 	*SPtr = S1; break;
		  	 case '2':
		  	 	*SPtr = S2; break;
		  	 case '3':
		  	 	*SPtr = S3; break;
		  	 default:
		  	 	printf("#ERROR: No such string!\n"); exit(1);
		  	 }
			continue;
		}
		if (str[i] == 'S' && isdigit(str[i+1]) )
		{
		   	switch(str[i+1])
		  	 {
		  	 case '1':
		  	 	*SPtr2 = S1; break;
		  	 case '2':
		  	 	*SPtr2 = S2; break;
		  	 case '3':
		  	 	*SPtr2 = S3; break;
		  	 default:
		  	 	printf("#ERROR: No such string!\n"); exit(1);
		  	 }
		}
	}
}
