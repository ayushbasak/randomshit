#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char string[100];
	char temp[100];
	FILE * fp;
	FILE *f2 ,*f3 ,*f4 , *f5 , *f6 , *f7 , *f8 , *f9, *f10, *f11, *f12, *f13, *f14, *f15, *f16;
	fp = fopen("dic.txt","r");

	f2 = fopen("Two.txt","w");
	f3 = fopen("Three.txt","w");
	f4 = fopen("Four.txt","w");
	f5 = fopen("Five.txt","w");
	f6 = fopen("Six.txt","w");
	f7 = fopen("Seven.txt","w");
	f8 = fopen("Eight.txt","w");
	f9 = fopen("Nine.txt","w");
	f10 = fopen("Ten.txt","w");
	f11 = fopen("Eleven.txt","w");
	f12 = fopen("Twelve.txt","w");
	f13 = fopen("Thirteen.txt","w");
	f14 = fopen("Fourteen.txt","w");
	f15 = fopen("Fifteen.txt","w");
	f16 = fopen("Sixteen.txt","w");

	if(fp == NULL){
		printf("\nFILE NOT FOUND!\n");
		exit(0);
	}

	while(!feof(fp)){
		fscanf(fp,"%s",temp);
		strcpy(string,temp);
		strcat(string,"\n");
		if(strlen(string) == 3){
			fputs(string,f2);
		}
		else if(strlen(string) == 4){
			fputs(string,f3);
		}
		else if(strlen(string) == 5){
			fputs(string,f4);
		}
		else if(strlen(string) == 6){
			fputs(string,f5);
		}
		else if(strlen(string) == 7){
			fputs(string,f6);
		}
		else if(strlen(string) == 8){
			fputs(string,f7);
		}
		else if(strlen(string) == 9){
			fputs(string,f8);
		}
		else if(strlen(string) == 10){
			fputs(string,f9);
		}
		else if(strlen(string) == 11){
			fputs(string,f10);
		}
		else if(strlen(string) == 12){
			fputs(string,f11);
		}
		else if(strlen(string) == 13){
			fputs(string,f12);
		}
		else if(strlen(string) == 14){
			fputs(string,f13);
		}
		else if(strlen(string) == 15){
			fputs(string,f14);
		}
		else if(strlen(string) == 16){
			fputs(string,f15);
		}
		else if(strlen(string) == 17){
			fputs(string,f16);
		}
	}

	fclose(fp);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
	fclose(f6);
	fclose(f7);
	fclose(f8);
	fclose(f9);
	fclose(f10);
	fclose(f11);
	fclose(f12);
	fclose(f13);
	fclose(f14);
	fclose(f15);
	fclose(f16);


}