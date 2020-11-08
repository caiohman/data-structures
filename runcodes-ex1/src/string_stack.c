#include "string_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

String_stack *create_stack(){
  String_stack *str = (String_stack *)calloc(1, sizeof(String_stack));
  return str;
}

int delete_stack(String_stack *str){
  if(str == NULL) return LIST_NO_EXIST;
  free(str);
  return OK;
}

int push(String_stack *str, char *element){
  if(str == NULL) return LIST_NO_EXIST;

  Elem *elem = (Elem *)calloc(1, sizeof(Elem));
  elem->String = (char *)calloc(strlen(element) + 1, sizeof(char));
  strcpy(elem->String, element);

  if(!str->size) str->elements = elem;
  else{
    elem->next = str->elements; //insert at the beginning
    str->elements = elem;
  }
  str->size++; //increase list size
  return OK;
}

char *pop(String_stack *str){
  Elem *aux = str->elements;
  str->elements = aux->next;
  char *element = (char *)calloc(strlen(aux->String)+1, sizeof(char));
  strcpy(element, aux->String);
  free(aux);
  str->size--;
  return element;
}
