#ifndef STRING_STACK_H
#define STRING_STACK_H

#define OK 0
#define LIST_NO_EXIST -1

typedef struct elem{
  char *String;
  struct elem *next;
}Elem;

typedef struct stack{
  int size;
  Elem *elements;
}String_stack;


/*@Description: create a stack to handle strings*/
/*@param: none                                  */
/*@return: pointer to stack created or NULL     */
String_stack *create_stack();
/*@Description: deallocate stack from mem       */
/*@param: pointer to stack                      */
/*@return: OK or LIST_NO_EXIST                  */
int delete_stack(String_stack *str);
/*@Description: push string to stack            */
/*@param: pointer to stack and string           */
/*@return: OK or LIST_NO_EXIST                  */
int push(String_stack *str, char *element);
/*@Description: pop string from stack           */
/*@param: pointer to stack                      */
/*@return: string                               */
char *pop(String_stack *str);

#endif
