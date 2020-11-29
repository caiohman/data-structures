#ifndef DICTIONARY_H
#define DICTIONARY_H

/*   - Macros - */
#define MAX_LEVEL 10
#define MAX_WORD 50
/****************/

typedef struct elem{
  char *word;
  char *meaning;
}Elem;

typedef struct node{
  Elem *key;
  struct node **forward;
}Node;

typedef struct dictionary{
  int level;
  Node *header;
}Dictionary;

/*@Description: create a dictionary*/
/*@Param: none                     */
/*@Return: pointer to dictionary   */
Dictionary *_create();
/*@Description: insert elements to dictionary*/
/*@Param: pointer to dictionary              */
/*@Return: none                              */
void _insert(Dictionary * , char * , char * );
/*@Description: print elements from dictionary whith given char*/
/*@Param: pointer to dictionary                                */
/*@Return: none                                                */
int _print(Dictionary *, char);
/*@Description: deallocate space of  dictionary*/
/*@Param: pointer to dictionary, first letter  */
/*@Return: 0 for sucess and 1 for failure      */
void _free(Dictionary *);
/*@Description: delete element of dictionary  */
/*@Param: pointer to dictionary, word         */
/*@Return: 0 for sucess and 1 for failure     */
int _delete(Dictionary *, char *);
/*@Description: search element of dictionary  */
/*@Param: pointer to dictionary, word         */
/*@Return: 0 for sucess and 1 for failure     */
int _search(Dictionary *, char *);
/*@Description: change meaning of dictionary's element  */
/*@Param: pointer to dictionary, word                   */
/*@Return: 0 for sucess and 1 for failure               */
int _change(Dictionary *, char *, char *);

#endif
