#include "string_stack.h"

#ifndef REVISION_H
#define REVISION_H

#define OK 0
#define CONTROL_NO_EXIST -1
#define STR_NO_EXIST -2

typedef struct str{
  char *old_string;
  char *wrong;
  char *right;
  char *new_string;
  struct str *next;
}Str;

typedef struct control{
  int cases;
  Str *strings;
}Control;

/*@Description: create a stack to handle strings*/
/*@param: none                                  */
/*@return: pointer to stack created or NULL     */
Control *create();
/*@Description: deallocate stack from mem       */
/*@param: pointer to stack                      */
/*@return: OK or CONTROL_NO_EXIST               */
int delete(Control *control);
/*@Description: insert struct to stack                         */
/*@param: pointer to stack, struct from another stack          */
/*@return: OK or CONTROL_NO_EXIST                              */
int add(Control *control , String_stack *str);
/*@Description: pop struct str from stack           */
/*@param: pointer to stack                          */
/*@return: struct str                               */
Str *pop_rev(Control *control);
/*@Description: get correct string                  */
/*@param: pointer to strings struct                 */
/*@return: string                                   */
char *get_new_string(Str *str);
/*@Description: deallocate string struct           */
/*@param: pointer to string struct                 */
/*@return: OK or STR_NO_EXIST                      */
int clean_str(Str *str);
#endif
