#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordchecker.c"



int main(){
	FILE * fp;

	fp = fopen("dic.txt","r");

	char bag[100];
	printf("\nEnter Bag of Letters\n");
	scanf("%s[^\n]",bag);

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
}