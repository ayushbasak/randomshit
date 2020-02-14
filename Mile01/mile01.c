/*
FILE Description:

Function
	1.	Dictionary(char *):
		
		Opens the dic.txt in a file pointer.
		Checks for each word in the dictionary for the given word in the parameter
			returns 1 if word is found
			returns 0 if word is not found

*/

#include "mile01.h"
FILE *fx;
int Dictionary(char * word)
{
	char dictWord[25];
	fx = fopen("dic.txt","r");
	
	if(fx == NULL)
	{
		printf("File not found\n");
		exit(0);
	}

	while(!feof(fx))
	{
		fscanf(fx,"%s",dictWord);

		if (strcmp(word,dictWord) == 0){
			return 1;
			break;
		}
	}

	return 0;

	fclose(fx);
}
