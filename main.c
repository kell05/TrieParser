#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trie.h"
#define MAX 1024

int main(int argc, char *argv[]){
  /* Seems to an array rather than a char* */

  FILE *fp;
  char* line;
  char* rem;
  int counter;
  int pos;
  char linefull[MAX];
  char clear[MAX];
  printf("Num of args %d\n",argc);

  for(counter =0;counter < MAX;counter++)
    clear[counter]=' ';


  Trie_Type trie;
  if(argc != 2){
    printf("Not enough arguments need one file\n");
    return 1;
  }


  
  printf("file name %s\n",argv[1]);
  if ((fp= fopen(argv[1],"r"))==NULL){
    printf("File could not be opened\n");
    return 1;
  }

  /* Create the data structure */
  trie = Create_Trie();
  
  while(fgets(linefull,MAX,fp)!= NULL){
    char t[1025];
    /*printf("%s",linefull);*/

    rem = strstr(linefull,".gov");
    /*Need to kill everything after the .gov*/
    pos = ((int)rem) - ((int)linefull);

    /* The 4 is for the length of .gov  */
    pos = pos + 4;
    /*fprintf(stderr,"This is pos %d\n",pos);*/
    /*linefull[pos] = '\0';*/
    
    strcpy(((char*)t),linefull);
    rem = strstr(((char*)t),"://");


    strcpy(((char*)t),rem+3);
    line = (char*)malloc(sizeof(char)*MAX);
    
    if(line== NULL)
      printf("Ran out of memory\n");

    counter = 0;
    while(t[counter] != '/'){
      line[counter] = t[counter];
      counter++;
    }

    if(Insert_In_Trie(trie,line)==0){
      printf("Error in adding line\n");
      return 1;
    }

    /*    printf("added line %s\n",line);*/
    
    
  }
  /*  Display_Depth(trie,3);*/
  Display(trie);
  /* Unsure of why this causes an error !! */
  /*fclose(fp);*/
  return 0;
}



