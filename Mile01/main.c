/*
				Project Milestone 01
Date of Submission	:	14/02/2020
Group Number		:	

Team Members:	
Chaitanya Sharma	19ucc010
Ayush Basak			19ucc016
Aditya Pandey		19ucc043
K.Sai Pranav Raj	19ucc044
Mehul Agarwal		19uec012
Pratik Gupta		19ucs047
Greek Sachdeva		


Milestone Description:

	STEP 1:	The user supplies with a bag of letters of the English Language in UTF-8;
			The bag may contain spaces which will be considered as null
			The bad may also contain uppercase or lowercase letters.
			
	STEP 2:	The user then supplies with a predefined word when prompted.
			<END of USER interaction>
			
	OUTPUTS:
		1.	Prints whether the word given by the user can be made from the bag of letters supplied previously
		2.	Prints whether the word is in the dictionary "dic.txt"
		3.	Prints the time complexity of the run program since the end of user input

*/






#include "mile01.h"
int main()
{    clock_t ti;
    int flag,flag2=1,N,sum=0,score,L;
    char lett[100],asc[130] = {0},word[100],wasc[130]={0},sub[130]={0};
    int sco[27] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10,0};
    int good,bad,mult,weight =0;
    printf("ENTER a bag of letters:	\n\n");
    scanf("%[^\n]s", lett);
    printf("\n\nENTER a word:	\n\n");
    scanf("%s",word);
    int i;
	 ti = clock();
    for(i=0;i<strlen(lett);i++)
    {
        asc[lett[i]]++;
    }  
    for(i=0;i<strlen(word);i++)
    {
        wasc[word[i]]++;
    } 
    L = strlen(lett) - asc[32];
    
     for(i=97;i<122;i++)      // changing count of lowercase to uppercase
     {
         asc[i-32] = asc[i-32] + asc[i];
         asc[i]=0;
     }
     for(i=97;i<122;i++){
         wasc[i-32] = wasc[i-32] + wasc[i];
         wasc[i]=0;  
     }
    for(i=65;i<=122;i++)
    {
        sub[i] = asc[i] - wasc[i];
    }
   for(i=65;i<=122;i++)
   {
       if(sub[i]<0  && (i!= 65 && i !=69 && i !=73 && i !=79 && i !=85)){
           flag2 = 0;
           break;
       }
       else if(sub[i]<0 && (i== 65 || i ==69 || i ==73 || i ==79 || i ==85))
                    sum = sum  + sub[i];
   }
      if(flag2 ==1)
           printf("\n1:	The word is POSSIBLE from the bag of letters\n");
   else if(flag2 ==1 && (sum*(-1)) <= asc[42])
       printf("\n1:	The word is POSSIBLE from the bag of letters\n");
   else
        printf("\n1:	The word is NOT POSSIBLE from the bag of letters\n");
        for(i=0;i<L;i++)                     //to convert lowercase to uppercase
     {
         if(word[i]>=97 && word[i]<=122)
             word[i] = word[i]-32;
     }
good = (L-1)*strlen(word);
bad = 3*(L+1-strlen(word));
if(bad<1)
 bad=1;
 mult = good -bad;
 for(i=0;i<strlen(word);i++)
      weight = weight + sco[word[i]- 65];

weight = weight - (sum*(-1));
 score = weight*mult; 
 if(Dictionary(word))
 {
        printf("\n2:	The word was FOUND in the dictionary\n");
        printf("\n3:	The SCORE:	");
        printf("%d\n",score);

    }
    else
    	printf("\n2:	The word was NOT FOUND in the dictionary\n");

ti = clock() - ti; 
    double time_taken = ((double)ti)/CLOCKS_PER_SEC; // in seconds 
  	time_taken*=1000;
    printf("\nTime taken in milliseconds:	%.2f\n", time_taken);
}

