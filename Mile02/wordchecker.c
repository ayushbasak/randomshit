
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void init(int * succ){
  for(int k = 0;k<26;k++){
    succ[k] = 0;
  }
}

int checkPresence(char * bag,char* word) {
  int posword[26];
  int posbag[26];
  init(posword);
  init(posbag);
  for(char i = 'A';i<='Z';i++){
    for(int j = 0;j<strlen(word);j++){
      if(word[j] == i){
        int code = (int)i-65;
        posword[code]+=1;
      }
    }
  }
  for(char i = 'A';i<='Z';i++){
    for(int j = 0;j<strlen(bag);j++){
      if(bag[j] == i){
        int code = (int)i-65;
        posbag[code]+=1;
      }
    }
  }
  int possible = 1;
  for(int i = 0;i<26;i++){
    //printf("%d %d\n",posword[i],posbag[i]);
    if(posword[i] > posbag[i]){
      possible = 0;
      break;
    }
  }
  return possible;
}
int scoreofword(char * word,char * bag){
  int s = strlen(bag);
  
  int good = (s-1)*(strlen(word));
  int bad = 1;

  if(bad < (3*(s+1-strlen(word))))
    bad = (3*(s+1-strlen(word)));

  int mult = good - bad;
  int pos;

  int weight = 0;
  int sco[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
  for(int i = 'A';i<='Z';i++){
    int count = 0;
    pos = (int)i - 65;
    for(int j = 0;j<strlen(word);j++){
      if(word[j]==i){
        count +=1;
      }
    }

    weight += (sco[pos]*count);
  }

  int score = weight * mult;

  return score;
  

}