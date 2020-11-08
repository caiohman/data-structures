#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char const *argv[]) {

  long int number;
  scanf("%ld", &number);

  int *arr = NULL;

  for(long int i = 0; i < number; i++){
    arr = (int *)realloc(arr, (i + 1) * sizeof(int));
    scanf("%d", arr + i);
  }

  Stack *compra = create_stack();
  Stack *descarte = create_stack();
  Stack *morto = create_stack();

  int card, count = 0, found_card = 1;

  for(int j = number - 1; j >= 0; j--) push(compra , arr + j); //store in compra stack

  while(stack_size(morto) != number){ //it only stops when all elem are at morto stack
    int size = stack_size(compra);
    for(int k = 0; k < size; k++) {
      if((card = pop(compra)) == found_card){push(morto, &found_card); found_card++;}
      else push(descarte, &card);
    }
    int descarte_size = stack_size(descarte);
    for(int l = 0; l < descarte_size; l++){int desc = pop(descarte); push(compra, &desc);}
    count++;
  }

  printf("%d\n", count);

  free(arr);
  delete_stack(compra);
  delete_stack(descarte);
  delete_stack(morto);
  return 0;
}
