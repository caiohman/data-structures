#ifndef LIST_H
#define LIST_H

typedef struct node{
  struct node *prox, *back;
  int chave, tempo, pos;
}Node;

typedef struct list{
  Node *first, *last;
  int size;
}List;

/*@Description: create list */
/*@param: none*/
/*@return: pointer to list*/
List *create();
/*@Description: add element to list */
/*@param: pointer to list, elem,position's back number, time*/
/*@return: 0 means ok and error from assert*/
int add(List *, int , int, int);
/*@Description: clean list */
/*@param: pointer to list*/
/*@return: error from assert or none*/
void deallocate_list(List *);
/*@Description: print list's elements */
/*@param: pointer to list*/
/*@return: error from assert or none*/
void print_list(List *);
/*@Description: remove item from list */
/*@param: pointer to list , element*/
/*@return: error from assert or none*/
void remove_item(List *, int);

#endif
