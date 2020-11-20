#ifndef BT_H
#define BT_H

typedef struct node{
  int elem;
  struct node *pops;
  struct node *right, *left;
}Node;

typedef struct bt{
  int count;
  Node *root;
}Bt;

Bt *_create();
void _insert(Bt * , int );
void _delete(Bt *);
void _print_pre(Bt *);
#endif
