#ifndef _POSTFIX_TRIE_
#define _POSTFIX_TRIE_


typedef struct node{
  char*  postfix;
  struct node* next;
  struct node* child;
  long  freq;      	     
} Trie_Node;


typedef Trie_Node *Trie_Type;


/* Returns an instance of Trie or NULL if unsuccessful*/

Trie_Type Create_Trie(void);


/*Inserts a postfix into the Trie returns 1 if successful else 0*/

int Insert_In_Trie (Trie_Type trie , char  postfix[], char* delimiter);


/* Destroys the Trie returns 1 if successful else 0 */ 
int Destroy_Trie (Trie_Type trie);


/* Finds the string 1 on found 0 on not found */
void Search_Trie ( Trie_Type trie, char* str , int*  Found );



/* Displays all of the domains and there frequency  */
void Display(Trie_Type trie);


/* Displays all of the domains and there frequency to a specific depth */
void Display_Depth(Trie_Type trie, int depth);


#endif /* Trie for postfixes of URLs */
