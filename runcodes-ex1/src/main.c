#include <stdio.h>
#include <stdlib.h>
#include "revision.h"
#include "string_stack.h"

int main(int argc, char const *argv[]) {
  Control *control = create();
  String_stack *str = create_stack();

  char *line = NULL;
  size_t len = 0;

  while(getline(&line , &len, stdin) != -1) push(str, line);

  for(int j = 0 ; j < 3 ; j++){
    add(control, str);
  }

  for(int i = 0 ; i < 3 ; i++){
    Str *strr = pop_rev(control);
    printf("%s", get_new_string(strr));
    clean_str(strr);
  }

  free(line);
  delete(control);
  delete_stack(str);
  return 0;
}
