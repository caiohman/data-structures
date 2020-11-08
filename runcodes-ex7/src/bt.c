#include "bt.h"
#include <assert.h>
#include <stdlib.h>

Bt *_create(){
  Bt *bt = (Bt *)calloc(1 , sizeof(Bt));
  return bt;
}

void _insert_node(Node *node , int value){
  if(!node){
    Node *node = (Node *)calloc(1 , sizeof(Node));
    node->elem = value;
    return;
  }
  if(value < node->elem) return _insert_node(node->left , value);
  if(value > node->elem) return _insert_node(node->right , value);
}

void _insert(Bt *bt , int value){
  assert(bt);

  _insert_node(bt->root , value);
  bt->size++;
}

void _delete_node(Node *node){
  if(node){
    _delete_node(node->left);
    _delete_node(node->right);
    free(node);
  }
}

void _delete(Bt *bt){
  assert(bt);
  _delete_node(bt->root);
  free(bt);
}
