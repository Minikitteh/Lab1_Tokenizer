#include <stdio.h>
#include <stdlib.h>
#include "history.h"

// history.c file

///////////////////////////////////////
/*
typedef struct s_Item{
  int id;
  char str;
  struct s_Item* next;
}
  
typedef struct s_List{
  struct s_Item* root;
} List;
*/
/////////////////////////////////////////

List* init_history(){
  List* nodeList = NULL;
  nodeList = malloc(sizeof(List));
  Item* nodeItem = NULL;
  nodeItem = malloc(sizeof(Item));

  // -> works as .get ex root.next == root -> next
  // assigning root to item
  nodeList->root = nodeItem;
  nodeItem->id = 0;
  nodeItem->str =  "";
  nodeItem->next = NULL;
  return nodeList;

}

void add_history(List*list, char*str){
  //need to traverse thru linke list
  // str is the input str
  
  Item* temp = list->root;
  int count = 1;
  //finding last node
  while(temp->next != NULL){
    temp = temp->next;
    count++;
  }
  //if list is empty
  if(temp->id == 0){
    temp->id = count;
    temp->str = str;
    return; //escape from func
  }
  //give values to the nodes of the input
  temp->next = malloc(sizeof(Item));
  // +1 to number values properly
  temp->next->id = count +1;
  temp->next->str = str;
  temp->next->next = NULL; 
  
}

char* get_history(List*list, int id){
  Item* temp = list->root;
  int count = 0, numItem = 0;

  //counting nodes
  while(temp != NULL){
    temp = temp->next;
    count ++;
  }

  numItem = count; //number of nodes
  Item* temp2 = list->root;
  while(temp2 != NULL){
    //match fount return str
    if(temp2->id == id){
      return temp2->str;
    }
  temp2 = temp2->next;
  }
  return NULL;    

}

void print_history(List*list){
  Item* temp = list->root;
  while(temp != NULL){
    //printing id and node
    printf("%d: %s \n", temp->id, temp->str);
    temp = temp -> next;
  }
}


void free_history(List*list){
  //de-allocate the memory we dont have a garbage coll
  Item* temp = list->root;
  Item* temp2; //iter
  while(temp != NULL){
    temp2 = temp;
    temp = temp->next;
    free(temp2);
  }
  free(list);
}

///////////////////////////////////////////////////////////////
//******* AFTTER DUE DATE to show proof of functions working
//////////////////////////////////////////////////////////////

int main(){
  List* temp = init_history();

  //adding history
  add_history(temp, "I tried");
  add_history(temp, "boi oh boi");
  add_history(temp, "cries");

  //print history
  print_history(temp);

  //get history
  char* getHist = get_history(temp, 3);
  printf("%s\n", getHist);

  //free history
  free_history(temp);

  return 0;
}








