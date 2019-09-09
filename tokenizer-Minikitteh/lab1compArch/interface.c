#include <stdio.h>
#include <stdlib.h>

//interface file

#define MAX 100

int main(){
  printf("# :");
  char buffer[MAX];
  fgets(buffer, MAX, stdin);
  printf("User Input:", buffer);

  return 0;
}
