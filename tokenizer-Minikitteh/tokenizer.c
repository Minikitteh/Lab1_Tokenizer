#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


//tokenizer file
//dont make a main here use test.c

//***************************************//
// Hiram Rios, Matthew Iglesias
// Matthew Montoya, & Jorge Felix helped me
// understand some concpets in this lab,
// mainly pointers along w/ function concepts
//**************************************//


int string_length(char*str){
  //  \0 signifies the end of a string
  // this method must ignore white spaces (havent checked yet tho)
  int counter = 0,i = 0;
  for(i = 0; i < str[i] != '\0'; i++){
    counter++;
  }
  return counter;
}


char is_valid_character(char c){
  //return 1 if valid, 0 otherwise
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
    printf("char is valid alphabet letter");
    return 1;
  }
  if(c <= '9' && c >= '0'){
    printf("char is valid number");
    return 1;
  }
  return 0;
}


int find_word_start(char*str, int index){
  //find beginning of next word & index is the start index
  int wordStart = 0, i = 0;
  for(i = index; str[i] != '\0'; i++){
    if(str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0'){
      wordStart = i+1;
      //break;
    }
  }
  return wordStart;
}


int find_word_end(char*str, int index){
  // find the end index of a word & index is the word start index
  int wordEnd = 0, i = 0;
  for(i = index; str[i] != '\0'; i++){
    if(str[i+1] == '\0' || str[i+1] == ' '){
      wordEnd = i;
      //break;
    }
  }
  return wordEnd;  
}


int count_words(char*str){
  //count the words entered
  int counter = 0, i = 0;
  for(i = 0; str[i] != '\0';  i++){
    //satisfies requirements when you reach the end of a word
    if((str[i] == ' ' && i == 0) || (str[i] == ' ' && str[i+1] != '\0' && str[i+1] != ' ')){
      counter++;
    }
  }
  return counter;
}


void print_tokens(char**str){
  //traverse the str array & print each str
  // %c chars    %s strings
  int i = 0;
  for(i = 0; *str[i] != '\0'; i++){
    printf("%s\n", str[i]);
  }  
}


void free_tokens(char**str){
  //free up the tockens in str array
  int i = 0;
  for(i = 0; *str[i] != '\0'; i++){
    free(str[i]);
  }
  free(str);  
}


char**tokenize(char*str){
  int numWords = count_words(str);
  
  //the following will store a string array of the word inputs
  char ** array = malloc(numWords *sizeof(char*) + 1);
  
  //setting null terminator to the end of array '\0'
  array[numWords] = (char*)malloc(sizeof(char));
  *array[numWords] = '\0';
  
  int start = 0, end = 0, i , j , wordSize, charPtr;
  //determines how many words will be added ** 
  for(i = 0; i < numWords; i++){
    if(i != 0){
      //finding the start of the next word using prev word
      start = find_word_start(str, end);

      //using ptr to traverse thru curr word
      charPtr = start;

      //finding the end of the word using start
      end = find_word_end( str, start);

      wordSize = end - start;
      array[i] = (char*)malloc((wordSize + 2) * sizeof(char));
      for(j = 0; j < wordSize; j++){
	array[i][j] = str[charPtr];
	charPtr++;
      }
      array[i][end + 1] = '\0';
    }
    //start word will be at index 0
    if(i == 0){
      end = find_word_end(str, start);
      //allocating memory for the curr word
      array[i] = (char*)malloc((end+2)*sizeof(char));
      //inputs word into pos of array
      for(j = 0; j < end + 1; j++){
	array[i][j] = str[j];
      }
      array[i][end + 1] = '\0';
    }
  }
  return array;
}

///////////////////////////////////////////////////////////////////////////
// *********** after demo turned in to show testing purposes
/////////////////////////////////////////////////////////////////////////

int main(){
  printf("Testing Functions: (end me) \n");

  //count words
  int numWords = count_words("end me");
  printf("# of words: %d \n", numWords);

  //word start
  int startWord = find_word_start("end me", 0);
  printf("should be 4 for beginning of me: %d \n", startWord);

  //word end
  // int endWord = find_word_end("end me", 0);
  // printf("should be 2 for end: %d \n", endWord);

  //end for word 2
  int endWord2 = find_word_end("end me", startWord);
  printf("should be 5 for me: %d \n", endWord2);

  //tokenize
  printf("will tokenize: end me \n");
  char* phrase = "end me";
  char** tokenizeOutput = tokenize(phrase);

  //print tokens
  printf("print tokens: \n");
  print_tokens(tokenizeOutput);
  
  return 0;
}
















