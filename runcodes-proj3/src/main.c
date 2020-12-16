#include <stdio.h>
#include <stdlib.h>
#include "treaps.h"
#include <string.h>

int main(int argc, char const *argv[]) {

  int number;
  scanf("%d\n", &number);
  Treaps *treaps = _create();

  while (number > 0) {
    char op[10], print_type[9];
    int value, priority;
    scanf("%s", op);

    if(!strcmp(op , "insercao")){
      scanf(" %d %d\n", &value , &priority);
      _insert(treaps , value , priority);
    }
    else if(!strcmp(op , "impressao")){
      scanf(" %s\n", print_type);
      if(!strcmp(print_type , "preordem"))_print_pre_order(treaps);
      else if(!strcmp(print_type , "ordem"))_print_in_order(treaps);
      else if(!strcmp(print_type , "posordem"))_print_pos_order(treaps);
      else if(!strcmp(print_type , "largura"))_print_level_order(treaps);
    }
    else if(!strcmp(op , "remocao")){
      scanf(" %d\n", &value);
      _remove(treaps , value);
    }
    else if(!strcmp(op , "buscar")){
      scanf(" %d\n", &value);
      printf("%d\n", _search(treaps , value));
    }
    number--;
  }
  _delete(treaps);

  return 0;
}
