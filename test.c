#include <stdio.h>
#include <string.h>
#include "trie.h"


int main(){
  /* Seems to an array rather than a char* */
  char url1[] = "http://www.mail.fun1.yahoo.gov/something/somethingelse";
  char url2[] = "http://www.some1.fun2.google.gov/something/somethingelse";
  char url3[] = "http://www.some2.fun3.ask.gov/something/somethingelse";
  char url4[] = "http://www.some2.fun3.ask.gov/something/somethingelse";
  char url5[] = "http://www.someask.fun3.ask.gov/something/somethingelse";
  

  Trie_Type trie = Create_Trie();


  if (Insert_In_Trie(trie,url1)==0)
    printf("This needs debugged 1\n");

    
  if (Insert_In_Trie(trie,url2)==0)
    printf("This needs debugged 2\n");


  if (Insert_In_Trie(trie,url3)==0)
    printf("This needs debugged 3\n");

  if (Insert_In_Trie(trie,url4)==0)
    printf("This needs debugged 4\n");

  if (Insert_In_Trie(trie,url5)==0)
    printf("This needs debugged 5\n");
  


  printf("Display all:\n");
  Display(trie);

  
  printf("Display to depth:\n");
  Display_Depth(trie,5);
  return 0;
}
