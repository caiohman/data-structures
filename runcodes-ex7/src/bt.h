#ifndef BT_H
#define BT_H

typedef struct node{
  int elem;
  struct node *pops;
  struct node *right, *left;
}Node;

typedef struct bt{
  Node *root;
}Bt;


/*@Description: create binary tree*/
/*@param: none */
/*@return: pointer to tree*/
Bt *_create();
/*@Description: insert element to tree*/
/*@param: pointer to tree, node, left, right */
/*@return: none*/
void _insert(Bt * , int , int , int);
/*@Description: delete entire tree*/
/*@param: pointer to tree */
/*@return: none*/
void _delete(Bt *);
/*@Description: print tree elements*/
/*@param: pointer to tree */
/*@return: none*/
void _print_pre(Bt *);

//void _print_pre_test(Bt *);
#endif
