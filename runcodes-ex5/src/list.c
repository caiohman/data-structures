#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

List *create(){
  List *list = (List *)calloc(1, sizeof(List));
  return list;
}

int add(List *list, int elem, int pos_back, int time){
  assert(list != NULL);

  Node *node = (Node *)calloc(1, sizeof(Node));
  node->chave = elem;
  node->tempo = time;

  if((!pos_back) || (pos_back > list->size))
    node->back = NULL;

  else{
    Node *aux = list->first;
    int i = pos_back;
    while(list->size - i){
      aux = aux->prox;
      i++;
    }
    node->back = aux;
  }

  if(!list->size){
    list->first = list->last = node;
    list->last->pos = 0;
  }
  else{
    list->last->prox = node;
    node->pos = list->last->pos + 1;
    list->last = node;
  }
  list->size++;

  return 0;
}

void deallocate_list(List *list){
  assert(list != NULL);
  Node *aux = list->first;

  for(int i = 0; i < list->size; i++){
      Node *node = aux;
      aux = aux->prox;
      free(node);
  }
  free(list);
}

void print_list(List *list){
  assert(list != NULL);
  Node *aux = list->first;

  if(!list->size)
    printf("%d", -1);

  for(int i = 0; i < list->size; i++){
      Node *node = aux;
      aux = aux->prox;
      printf("[%d,%d", node->chave, node->tempo);
      if(node->back != NULL)
        printf(",%d] ", node->back->pos);
      else{ printf("] "); }
  }
}

void remove_item(List *list, int chave){
  assert(list != NULL);
  Node *elem = list->first;
  Node *ant = NULL;
  int i = 0;

  for(; i < list->size ; i++){
    if(elem->chave == chave)
      break;
    ant = elem;
    elem = elem->prox;
  }

  if(ant == NULL){ // beginnig case
    list->first = elem->prox;
  }

  else{
    if(elem == list->last){ // final case
      list->last = ant;
    }
    else{ // middle case
      ant->prox = elem->prox;
    }
  }

  Node *update = elem;
  int inc = update->pos;
  for(; i < list->size - 1 ; i++){ //update element's position
    if(update->prox != NULL){
      update->prox->pos = inc++;
      update = update->prox;
    }
  }

  Node *null = list->first;
  while (null != NULL) {  //find another link to node elem
    if(null->back == elem) null->back = NULL; //clean it
    null = null->prox;
  }

  free(elem);
  list->size--;
}
