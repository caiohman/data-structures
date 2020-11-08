#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Queue *create(){
  Queue *queue = (Queue *)calloc(1, sizeof(Queue));
  return queue;
}

Elem *capture(char *e_name, unsigned int e_age, unsigned int e_condition){
  Elem *elem = (Elem *)calloc(1, sizeof(Elem));
  elem->name = (char *)calloc(1, strlen(e_name) + 1);
  strcpy(elem->name, e_name);
  elem->age = e_age;
  elem->condition = e_condition;

  return elem;
}

void add(Queue *queue, Elem *elem){
  if(!queue->size){ //only element
    queue->first = queue->last = elem;
  }
  else{ //have more elements
    queue->last->next = elem;
    queue->last = elem;
  }
  queue->size++;
  return;
}

int queue_size(Queue *queue){
  return queue->size;
}

Elem *recover(Queue *queue){
  if(queue->size){
    Elem *aux = queue->first;
    queue->first = aux->next;
    queue->size--;
    if(!queue->size) queue->last = queue->first = NULL;
    return aux;
  }
  else return NULL;
}

void elem_print(Elem *elem){
  printf("%s %d %d\n", elem->name, elem->age, elem->condition);
}

void delete_queue(Queue *queue){
  int size = queue->size;
  for(int i = 0 ; i < size ; i++){
    Elem *aux = queue->first;
    queue->first = aux->next;
    free(aux);
  }
  queue->last = NULL;
  return;
}
