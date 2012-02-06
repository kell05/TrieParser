#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "trie.h"


int Insert_In_Trie (Trie_Type trie , char  url[]){
  
  Trie_Type  temp;
  Trie_Type  parent;
  const int NUM = 24;
  char* fix[NUM];
  int loop;
  int counter;
  int num_domains = 0;
  
  /* Creates the substring */
  /* Error when usning a char* 1st arg  */
  fix[0]=strtok(url,"//");
  if(fix[0]==NULL){
    printf("URL doesn't have a  .\n");
    return 0;
  }


  fix[1]=strtok(url,".");
  num_domains++;
  for(loop=2;loop<NUM;loop++){
    fix[loop]=strtok(NULL,".");
    num_domains++;
    if(fix[loop]==NULL){
      break;
    }
  }
   
  /* Process the gov remove the folder and file extentions*/
  /* gov/something/something/file.html = gov*/

  fix[num_domains-1] = "gov";
 
  parent = trie;
  temp = trie->child;
  for(counter =  num_domains-1;counter > 0;){ 
    
    if (temp == NULL){
      /* Changed to having a code word.*/
      Trie_Type new_node =(Trie_Type)malloc(sizeof(Trie_Type));

      if(new_node== NULL)
	return 0;
      
      new_node->child = NULL;
      new_node->next = parent->child;
      parent->child = new_node;
      parent = new_node;
      parent->postfix = fix[counter--];
      parent->freq = 1;

    } else if (strcmp(temp->postfix,fix[counter])==0){
      temp->freq++;
      parent = temp;
      temp = temp->child;
      counter--;
    }else{
      /* Line correct! */
      temp = temp->next;
    }
  }
  return 1;
}


/*Inserts a postfix into the Trie returns 1 if successful else 0*/

Trie_Type Create_Trie(void){
  Trie_Type new_node =(Trie_Type)malloc(sizeof(Trie_Type));

  if(!new_node)
    return NULL;

  /* Create a null character */
  new_node->postfix = malloc(sizeof(char));
  new_node->postfix = "*";
  new_node->child =NULL;
  new_node->next =NULL;
  new_node->freq =0;
  return new_node;
}


/* Need to pass the latest number of occurances  */
/* Need to fix potential memory leak via free(temp) */
static void display_trie(Trie_Type trie,char* url){
  char temp[1024];
  if(trie != NULL){
    strcpy(temp,url);
    strcat(url,trie->postfix);
   

    if(trie->child != NULL)
      strcat(url,".");

    display_trie(trie->next,temp);

    if(trie->child == NULL)
      printf("%s\t%ld\n",url,trie->freq);

    display_trie(trie->child,url);  
  }
  
}


/* Displays of the number of the  */
void Display(Trie_Type trie){
  Trie_Type temp;
  temp = trie->child;
  char* url = (char*)malloc(sizeof(char*)*1024);
  printf("String\tfrequency\n");
  display_trie(temp,url);
  free(url);
}


/* Need to pass the latest number of occurances  */
static void display_trie_to_depth(Trie_Type trie,char* url,int* current, int depth){
  char temp[1024];
  
  /*  int* tempcurr = (int*)malloc(sizeof(int));*/
  int tempcurr;

  if(trie != NULL){
    strcpy(temp,url);
    strcat(url,trie->postfix);


    if(trie->child != NULL)
      strcat(url,".");
    tempcurr = *current;

    display_trie_to_depth(trie->next,temp,(&tempcurr),depth);
    
    if(((*current) == depth) || (trie->child ==NULL)){
      /* String depth frequency */
      printf("%s\t%d\t%ld\n",url,(*current),trie->freq);
    }
    
    (*current)++;
    display_trie_to_depth(trie->child,url,current,depth);

  }
}


void Display_Depth(Trie_Type trie,int depth){
  Trie_Type temp;
  int* curr = (int*)malloc(sizeof(int));
  /* Tidy up the declarations */
  temp = trie->child;
  (*curr) =0;
  printf("String\tfrequency\n");
  char* url = (char*)malloc(sizeof(char*)*1024);
  display_trie_to_depth(temp,url,curr,depth);
  free(url);
}


int Destroy_Trie (Trie_Type trie){
  
  return 0;
}
