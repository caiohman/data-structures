#ifndef STACK_H
#define STACK_H

#define STACK_NO_EXIST -1
#define OK 0
#define STACK_EMPTY -2

typedef struct elem{
  int value;
  struct elem *next;
}Elem;

typedef struct stack{
  int size;
  Elem *Elements;
}Stack;

Stack *create_stack();
int delete_stack(Stack *stack);
int push(Stack *stack, int *element);
int pop(Stack *stack);
int stack_size(Stack *stack);
#endif
