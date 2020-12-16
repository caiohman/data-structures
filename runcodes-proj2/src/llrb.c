#include "llrb.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*to study
https://www.geeksforgeeks.org/left-leaning-red-black-tree-insertion/
https://www.ime.usp.br/~yoshi/Sedgewick/Algs4th/Slides/33BalancedSearchTrees.pdf

*/


LLRB *_create(){
  LLRB *llrb = (LLRB *)calloc(1 , sizeof(LLRB));
  return llrb;
}
/*********************************************************************/
void _left_rotate(Node **node){
  Node *aux = (*node)->right;
	(*node)->right = aux->left;
	aux->left = *node;
	*node = aux;
  /* update pops and color*/
  (*node)->pops = (*node)->left->pops;
  (*node)->left->pops = *node;
  char c = (*node)->left->color;
  (*node)->left->color = (*node)->color;
  (*node)->color = c;

  return;
}

void _right_rotate(Node **node) {
	Node *aux = (*node)->left;
	(*node)->left = aux->right;
	aux->right = *node;
	*node = aux;
  /* update pops and color*/
  (*node)->pops = (*node)->right->pops;
  (*node)->right->pops = *node;
  char c = (*node)->right->color;
  (*node)->right->color = (*node)->color;
  (*node)->color = c;

  return;
}

/*********************************************************************/
void _max_node(Node **node, int value){
  if((*node)->right && (*node)->right->elem > value)
    return _max_node(&(*node)->right, (*node)->right->elem);

  printf("%d\n", (*node)->elem);

  return;
}

void _min_node(Node **node, int value){
  if((*node)->left && (*node)->left->elem < value)
    return _min_node(&(*node)->left , (*node)->left->elem);

  printf("%d\n", (*node)->elem);

  return;
}

/*********************************************************************/
void _insert_node(Node **node, int elem, Node *pops){

  if(!(*node)){
    (*node) = (Node *)calloc(1 , sizeof(Node));
    (*node)->elem = elem;
    (*node)->color = 'r'; //means red
    (*node)->pops = pops;

    return;
  }

  if((*node)->elem > elem)
    _insert_node(&(*node)->left , elem, (*node));

  if((*node)->elem < elem)
    _insert_node(&(*node)->right , elem, (*node));

  //simple left rotate
  if(((*node)->right && !(*node)->left) ||
  (
    (*node)->right && (*node)->left &&
    (*node)->right->color == 'r' && (*node)->left->color == 'b'
  )
  ){
    _left_rotate(node);
  }

  //simple right rotate
  if((*node)->left &&
  (*node)->left->left &&
  (*node)->left->color == 'r' &&
  (*node)->left->left->color == 'r'
  ){
    _right_rotate(node);
  }

  // change colors
  if((*node)->left &&
  (*node)->right &&
  (*node)->left->color == 'r' &&
  (*node)->right->color == 'r'
  ){
    //invert node color
    if((*node)->pops){ //check if it isn't root
      ((*node)->color == 'r') ? ((*node)->color = 'b') : ((*node)->color = 'r');
    }
    (*node)->left->color = (*node)->right->color = 'b'; //set to black
  }

  return;
}

void _insert(LLRB *llrb, int value){
  assert(llrb);

  if(!llrb->size){ //root case
    llrb->root = (Node *)calloc(1 , sizeof(Node));
    llrb->root->elem = value;
    llrb->root->color = 'b'; //means black
    llrb->size++;
    return;
  }

  _insert_node(&llrb->root, value, llrb->root);
  llrb->size++;
}

/*********************************************************************/
int _search_node(Node **node, int elem, int op) {

  if(!(*node)) //couldn't find
    return ERROR;

  if((*node)->elem == elem){ //found
    if(op == POS){
       if(!(*node)->right) { // there is no right node
          Node *aux1 = (*node);
          Node *aux2 = aux1->pops;

         while(aux2 && aux1 == aux2->right){
           aux1 = aux2;
           aux2 = aux2->pops;
         }
         if(!aux2) printf("%s\n", "erro");
         else { printf("%d\n", aux2->elem); }
       }
       else{ //there is right node
         _min_node(&(*node)->right, (*node)->right->elem);
       }
    }
    else if(op == PRE){

      if(!(*node)->left) { // there is no left node
         Node *aux1 = (*node);
         Node *aux2 = aux1->pops;

        while(aux2 && aux1 == aux2->left){
          aux1 = aux2;
          aux2 = aux2->pops;
        }
        if(!aux2) printf("%s\n", "erro");
        else { printf("%d\n", aux2->elem); }
      }
      else{ //there is left node
        _max_node(&(*node)->left, (*node)->left->elem);
      }

    }


    return SUCCESS;
  }

  int rst;
  if((*node)->elem > elem)
    rst = _search_node(&(*node)->left , elem, op);

  if((*node)->elem < elem)
    rst = _search_node(&(*node)->right , elem, op);

  return rst;
}

int _search(LLRB *llrb, int value, int op){
  assert(llrb);

  int rst = _search_node(&llrb->root, value, op);
  return rst;
}

/*********************************************************************/
void _max_value(LLRB *llrb){
  assert(llrb);

  _max_node(&llrb->root, llrb->root->elem);
}

/*********************************************************************/
void _min_value(LLRB *llrb){
  assert(llrb);

  _min_node(&llrb->root, llrb->root->elem);
}

/*********************************************************************/
void _delete_node(Node *node){
  if(node){
    _delete_node(node->left);
    _delete_node(node->right);
    free(node);
  }
  return;
}

void _delete(LLRB *llrb){
  assert(llrb);

  _delete_node(llrb->root);
  free(llrb);
  return;
}

/**********************************************************************/
void print_node_pre_order(Node *node){
	if(node){
		printf("%d ", node->elem);
		print_node_pre_order(node->left);
		print_node_pre_order(node->right);
	}
  return;
}

void _print_pre_order(LLRB *llrb){
	assert(llrb);

	print_node_pre_order(llrb->root);
  printf("\n");
	return;
}

/********************************************************************/
void _print_node_in_order(Node *node) {
	if (node) {
		_print_node_in_order(node->left);
		printf("%d ", node->elem);
		_print_node_in_order(node->right);
	}
}

void _print_in_order(LLRB *llrb) {
	assert(llrb);
	_print_node_in_order(llrb->root);
  printf("\n");
	return;
}

/*******************************************************************/
void _print_node_pos_order(Node *node) {
	if (node) {
		_print_node_pos_order(node->left);
		_print_node_pos_order(node->right);
		printf("%d ", node->elem);
	}
}

void _print_pos_order(LLRB *llrb) {
	assert(llrb);
	_print_node_pos_order(llrb->root);
  printf("\n");
	return;
}
