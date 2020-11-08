#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

List *create(){
  List *list = (List *)calloc(1, sizeof(List));
  return list;
}

void deallocate_list(List *list){
  assert(list != NULL);

  while (list->size){
    Elem *aux = list->first;
    list->first = aux->next;
    free(aux);
    list->size--;
  }
  list->last = NULL;
  free(list);
}

void add_list(List *list, int value){
  assert(list != NULL);

  Elem *aux = (Elem *)calloc(1, sizeof(Elem));
  aux->elem = value;

  if(!list->size) //first insertion
    list->first = aux->next = aux;

  else{
    list->last->next = aux;
    aux->next = list->first;
  }
  list->last = aux;
  list->size++;
}

void search_and_remove(List *list, int pos){
  assert(list != NULL);
  assert(pos <= list->size);

  Elem *elem = list->first;
  Elem *ant = NULL;

  for(int i = 1 ; i < pos ; i++){
    ant = elem;
    elem = elem->next;
  }
  if(ant == NULL){ // beginnig case
    list->first = elem->next;
  }
  else{
    if(elem == list->last){ // final case
      list->last = ant;
    }
    else{ // middle case
      ant->next = list->first = elem->next;
      list->last = ant;
    }
  }
  free(elem);
  list->size--;
  list->last->next = list->first;
}

int list_size(List *list){
  return list->size;
}

int list_get_first(List *list){
  return list->first->elem;
}
