#ifndef LLRB_H
#define LLRB_H

#define POS 2
#define PRE 3
#define SUCCESS 0
#define ERROR -1

typedef struct node{
    int elem;
    char color;
    struct node *left, *right, *pops;
}Node;

typedef struct llrb{
  int size;
  Node *root;
}LLRB;

/*@Description: create left-leaning reb-black tree*/
/*@param: none                                    */
/*@return: pointer to tree                        */
LLRB *_create();
/*@Description: insert elements into tree         */
/*@param: pointer to tree and element             */
/*@return: none                                   */
void _insert(LLRB *, int );
/*@Description: print tree's elements pre order   */
/*@param: pointer to tree                         */
/*@return: none                                   */
void _print_pre_order(LLRB *);
/*@Description: delete elements from tree         */
/*@param: pointer to tree                         */
/*@return: none                                   */
void _delete(LLRB *);
/*@Description: print tree's elements pos order   */
/*@param: pointer to tree                         */
/*@return: none                                   */
void _print_pos_order(LLRB *);
/*@Description: print tree's elements in order    */
/*@param: pointer to tree                         */
/*@return: none                                   */
void _print_in_order(LLRB *);
/*@Description: _search tree's elements           */
/*@param: pointer to tree, element, option        */
/*@return: 0 for sucess and -1 for error          */
int _search(LLRB *, int , int );
/*@Description: find tree's max value             */
/*@param: pointer to tree                         */
/*@return: none                                   */
void _max_value(LLRB *);
/*@Description: find tree's min value             */
/*@param: pointer to tree                         */
/*@return: none                                   */
void _min_value(LLRB *);
#endif
