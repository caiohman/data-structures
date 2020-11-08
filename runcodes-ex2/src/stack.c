#include <stdlib.h>
#include <assert.h>
#include "stack.h"

Stack *create_stack(){
  Stack *stack = (Stack *)calloc(1, sizeof(Stack));
  return stack;
}

int delete_stack(Stack *stack){
  assert(stack != NULL);
  free(stack);
  return OK;
}

int push(Stack *stack, int *element){
  assert(stack != NULL);

  Elem *elem = (Elem *)calloc(1, sizeof(Elem));
  elem->value = *element;

  if(!stack->size) stack->Elements = elem;
  else{
    elem->next = stack->Elements; //insert at the beginning
    stack->Elements = elem;
  }
  stack->size++; //increase list size
  return OK;
}

int pop(Stack *stack){
  assert(stack != NULL);
  if(stack->size){
    Elem *aux = stack->Elements;
    stack->Elements = aux->next;
    stack->size--;
    return aux->value;
  }
  return STACK_EMPTY;
}

int stack_size(Stack *stack){
  assert(stack != NULL);
  return stack->size;
}
