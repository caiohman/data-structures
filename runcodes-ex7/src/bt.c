#include "bt.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Bt *_create(){
  Bt *bt = (Bt *)calloc(1 , sizeof(Bt));
  return bt;
}

void _insert_node(Node **node , int value, Node *father, Bt *bt){
    Node *aux = (Node *)calloc(1 , sizeof(Node));
    aux->elem = value;
    aux->pops = father;

    if(!(*node)){
      *node = aux;
      return;
    }

    if(!(*node)->left) return _insert_node(&(*node)->left, value, *node, bt);
    if(!(*node)->right) return _insert_node(&(*node)->right, value, *node, bt);

    if(((*node)->left->elem == value ||
     (*node)->right->elem == value) &&
      value != -1) return; //eliminate repeated

    if((*node)->left->elem == -1){
      if((*node)->right->elem == -1) {
        if(bt->count < 2){
          bt->count++;
          _insert_node(&(*node)->pops->right, value, (*node)->pops, bt);
        }
        else{
          bt->count = 0;
          _insert_node(&(*node)->pops->pops->right, value, (*node)->pops->pops, bt);
        }
      }
      else _insert_node(&(*node)->right, value, (*node)->right, bt);
    }
    else _insert_node(&(*node)->left, value, (*node)->left, bt);
}

void _insert(Bt *bt , int value){
  assert(bt);

  _insert_node(&bt->root , value, NULL, bt);
}

void _delete_node(Node *node){
  if(node){
    _delete_node(node->left);
    _delete_node(node->right);
    free(node);
  }
  return;
}

void _delete(Bt *bt){
  assert(bt);
  _delete_node(bt->root);
  free(bt);
  return;
}

int height_node(Node *node){
  if(!node) return -1;

  int left_height = height_node(node->left);
  int right_height = height_node(node->right);

  if(left_height > right_height) return left_height + 1;
  else return right_height + 1;

}

void print_node(Node *node){
	if(node){
    if(node->elem != -1){
      printf("no %d: ", node->elem);
      printf("pai = ");
      (!node->pops)? printf("-1, ") : printf("%d, ", node->pops->elem);
      printf("altura = %d, " , height_node(node));
      printf("grau = ");
      (node->left->elem == -1) ? printf("0, ") : printf("2, ");
      printf("filhos = (%d,%d), ", node->left->elem , node->right->elem);
      printf("tipo = ");
      if(!node->pops) printf("raiz");
      else if(node->right->elem == -1 && node->left->elem == -1) printf("folha");
      else printf("interno");
      printf("\n");
    }
		print_node(node->left);
		print_node(node->right);
	}
  return;
}

void _print_pre(Bt *bt){
	assert(bt);

	print_node(bt->root);
	return;
}
