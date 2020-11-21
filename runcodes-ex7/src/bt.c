#include "bt.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Bt *_create(){
  Bt *bt = (Bt *)calloc(1 , sizeof(Bt));
  return bt;
}

void _insert_node(Node **node , int node_val, int left_val, int right_val){
    Node *aux = (Node *)calloc(1 , sizeof(Node));
    aux->elem = node_val;

    aux->left = (Node *)calloc(1, sizeof(Node));
    aux->left->elem = left_val;
    aux->left->pops = aux;

    aux->right = (Node *)calloc(1, sizeof(Node));
    aux->right->elem = right_val;
    aux->right->pops = aux;

    if(!(*node)){ //empty
      *node = aux;
      return;
    }

    if((*node)->elem == node_val){ //found
      aux->pops = (*node)->pops;
      (*node) = aux;
      return;
    }

    if((*node)->left &&
    ((*node)->left->elem != -1 ||
    (*node)->right->elem != -1 ))
      return _insert_node(&(*node)->left, node_val, left_val, right_val);

    if((*node)->pops->right != (*node))
      return _insert_node(&(*node)->pops->right, node_val, left_val, right_val);

    if((*node)->pops->pops->right != (*node)->pops)
      return _insert_node(&(*node)->pops->pops->right, node_val, left_val, right_val);

    if((*node)->pops->pops->pops->right != (*node)->pops->pops)
      return _insert_node(&(*node)->pops->pops->pops->right, node_val, left_val, right_val);

    if((*node)->pops->pops->pops->pops->right != (*node)->pops->pops->pops)
      return _insert_node(&(*node)->pops->pops->pops->pops->right, node_val, left_val, right_val);

}

void _insert(Bt *bt , int node, int left, int right){
  assert(bt);
  _insert_node(&bt->root , node, left, right);
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
      if(node->right->elem == -1 && node->left->elem == -1)printf("0, ");
      else if(node->left->elem == -1 || node->right->elem == -1)printf("1, ");
      if(node->right->elem != -1 && node->left->elem != -1)printf("2, ");
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

void print_node_test(Node *node){
	if(node){
		printf("%d ", node->elem);
		print_node_test(node->left);
		print_node_test(node->right);
	}
  return;
}


void _print_pre_test(Bt *bt){
	assert(bt);

	print_node_test(bt->root);
  printf("\n");
	return;
}
