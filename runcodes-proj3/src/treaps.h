#ifndef TREAPS_H
#define TREAPS_H

typedef struct node{
  int elem, priority;
  struct node *left, *right;
}Node;

typedef struct treaps{
  Node *root;
  int size;
}Treaps;

/*@Description: Create heap trees                  */
/*@param: none                                     */
/*@return: pointer to tree                         */
Treaps *_create();
/*@Description: Insert Elements into tree          */
/*@param: pointer to tree, element, priority       */
/*@return: node                                    */
void _insert(Treaps *, int , int );
/*@Description: Print tree's elements pre order    */
/*@param: pointer to tree                          */
/*@return: node                                    */
void _print_pre_order(Treaps *);
/*@Description: Print tree's elements in order     */
/*@param: pointer to tree                          */
/*@return: node                                    */
void _print_in_order(Treaps *);
/*@Description: Print tree's elements pos order    */
/*@param: pointer to tree                          */
/*@return: node                                    */
void _print_pos_order(Treaps *);
/*@Description: deallocate tree                    */
/*@param: pointer to tree                          */
/*@return: node                                    */
void _delete(Treaps *);
/*@Description: Print tree's elements level order  */
/*@param: pointer to tree                          */
/*@return: node                                    */
void _print_level_order(Treaps *);
/*@Description: Remove one element of tree         */
/*@param: pointer to tree and element              */
/*@return: node                                    */
void _remove(Treaps *, int );
/*@Description: Search tree's element              */
/*@param: pointer to tree and element              */
/*@return: 1 to sucess and 0 failed                */
int _search(Treaps * , int );

#endif
