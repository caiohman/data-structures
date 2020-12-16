#include "treaps.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Treaps *_create(){
  Treaps *treaps = (Treaps *)calloc(1 , sizeof(Treaps));
  return treaps;
}

/*********************************************************************/
void _left_rotate(Node **node){
  Node *aux = (*node)->right;
	(*node)->right = aux->left;
	aux->left = *node;
	*node = aux;

  return;
}

void _right_rotate(Node **node) {
	Node *aux = (*node)->left;
	(*node)->left = aux->right;
	aux->right = *node;
	*node = aux;

  return;
}

/********************************************************************/
void _insert_node(Node **node , int elem , int priority){

  if(!(*node)){
    *node = (Node *)calloc(1 , sizeof(Node));
    (*node)->elem = elem;
    (*node)->priority = priority;
    return;
  }

  if((*node)->elem == elem){
    printf("%s\n", "Elemento ja existente");
    return;
  }

  if((*node)->elem > elem)
    _insert_node(&(*node)->left , elem, priority);

  if((*node)->elem < elem)
    _insert_node(&(*node)->right , elem , priority);

  if((*node)->left &&
  (*node)->left->priority > (*node)->priority
  ){
    _right_rotate(node);
  }

  if((*node)->right &&
  (*node)->right->priority > (*node)->priority
  ){
    _left_rotate(node);
  }
}

void _insert(Treaps *treaps, int elem, int priority){
  assert(treaps);

  _insert_node(&treaps->root , elem , priority);
  treaps->size++;
}

/****************************************************************/
void _delete_node(Node *node){
  if(node){
    _delete_node(node->left);
    _delete_node(node->right);
    free(node);
  }
  return;
}

void _delete(Treaps *treaps){
  assert(treaps);

  _delete_node(treaps->root);
  free(treaps);
  return;
}

/**********************************************************************/
void _print_node_pre_order(Node *node){
	if(node){
		printf("(%d, %d) ", node->elem, node->priority);
		_print_node_pre_order(node->left);
		_print_node_pre_order(node->right);
	}
  return;
}

void _print_pre_order(Treaps *treaps){
	assert(treaps);

	_print_node_pre_order(treaps->root);
  printf("\n");
	return;
}

/********************************************************************/
void _print_node_in_order(Node *node) {
	if (node) {
		_print_node_in_order(node->left);
		printf("(%d, %d) ", node->elem, node->priority);
		_print_node_in_order(node->right);
	}
}

void _print_in_order(Treaps *treaps) {
	assert(treaps);
	_print_node_in_order(treaps->root);
  printf("\n");
	return;
}

/*******************************************************************/
void _print_node_pos_order(Node *node) {
	if (node) {
		_print_node_pos_order(node->left);
		_print_node_pos_order(node->right);
		printf("(%d, %d) ", node->elem, node->priority);
	}
}

void _print_pos_order(Treaps *treaps) {
	assert(treaps);
	_print_node_pos_order(treaps->root);
  printf("\n");
	return;
}

/*******************************************************************/
int _height_node(Node *node){
  if(!node) return 0;

  int left_height = _height_node(node->left);
  int right_height = _height_node(node->right);

  if(left_height > right_height) return left_height + 1;
  else return right_height + 1;
}

int _height(Treaps *treaps){
  assert(treaps);
  return _height_node(treaps->root);
}

void print_level(Node *node , int level){
  if(!node) return;
  if(level == 0)printf("(%d, %d) ", node->elem, node->priority);
  else if(level > 0){
    print_level(node->left , level - 1);
    print_level(node->right , level - 1);
  }
}
/*******************************************************************/
void _print_level_order(Treaps *treaps){
  assert(treaps);

  int height = _height(treaps);
  for(int i = 0 ; i < height ; i++){
    print_level(treaps->root , i);
  }
  printf("\n");
}

/*******************************************************************/
void _remove_node(Node **node , int elem){

  if(!(*node)){
    printf("%s\n", "Chave nao localizada");
    return;
  }

  if((*node)->elem == elem){
    if((*node)->left && (*node)->right){
      _left_rotate(node);
      _remove_node(&(*node)->left , elem);
      return;
    }

    if((*node)->left){
      Node *aux = (*node);
      (*node) = (*node)->left;
      free(aux);
    }
    else if((*node)->right){
      Node *aux = (*node);
      (*node) = (*node)->right;
      free(aux);
    }
    else if(!(*node)->left && !(*node)->right){
      *node = NULL;
      free(*node);
    }

    return;
  }

  if((*node)->elem > elem)
    return _remove_node(&(*node)->left , elem);

  if((*node)->elem < elem)
    return _remove_node(&(*node)->right , elem);

  return;
}

void _remove(Treaps *treaps , int elem){
  assert(treaps);

  _remove_node(&treaps->root, elem);
}

/*******************************************************************/
int _search_node(Node **node , int elem){
  if(!(*node)) return 0; // didn't find

  if((*node)->elem == elem) return 1; //found

  if((*node)->elem > elem)
    return _search_node(&(*node)->left , elem);

  if((*node)->elem < elem)
    return _search_node(&(*node)->right , elem);

  return 0;
}

int _search(Treaps * treaps, int elem){
  assert(treaps);

  return _search_node(&treaps->root , elem);
}
