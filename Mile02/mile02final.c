/*
				Project Milestone 02
Date of Submission	:	11/03/2020
Group Number		:	61

Team Members:	
Chaitanya Sharma	19ucc010
Ayush Basak			19ucc016
Aditya Pandey		19ucc043
K.Sai Pranav Raj	19ucc044
Mehul Agarwal		19uec012
Pratik Gupta		19ucs047
Greek Sachdeva		19dec008


Milestone Description:

	STEP 1:	The user supplies with a bag of letters of the English Language in UTF-8;
			The bag may contain spaces which will be considered as null
			The bad may also contain uppercase or lowercase letters.
			
	OUTPUTS:
		1.	Checks and Prints if a word from the dictionary is possible in the bag of letters
		2.	Computes and Prints the word with largest score possible

*/

#include "wordchecker.c"
int main(){
	clock_t ti;
	ti = clock();
	FILE * fp;

	fp = fopen("dic.txt","r");

	char bugga[100];
	printf("\nEnter Bag of Letters\n");
	scanf("%s[^\n]",bugga);

	char bag[100];
	for(int i = 0;i<strlen(bugga);i++){
		bag[i] = toupper(bugga[i]);
	}

	int maxScore = 0;
	char maxWord[100];

	if(fp == NULL){
		printf("FILE NOT FOUND!");
		exit(0);
	}
	else{
		int found = 0;
		while(!feof(fp)){
			char word[100];
			fscanf(fp,"%s",word);
			if(checkPresence(bag,word)){
				found = 1;
				int score = scoreofword(word,bag);
				if(maxScore < score){
					maxScore = score;
					strcpy(maxWord,word);
				}
			}
			
		}
		if(found == 0)
			printf("No word in the dictionary is possible from the bag of letters\n");
		else{
			printf("\nThe Word from the bag with largest score possible is : \n\n");
			printf("%s with score of %d\n",maxWord,maxScore);
		}
	}

	ti = clock() - ti;

	double time = ((double)ti)/CLOCKS_PER_SEC;
	printf("\n\nTotal execution time is : %f seconds\n\n",time);
}