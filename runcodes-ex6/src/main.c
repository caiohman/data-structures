#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"

int main(int argc, char const *argv[]) {

  int number, count = 1;
  scanf("%d\n", &number);

  while (number > 0) {

    char *operation = (char *)calloc(4 , sizeof(char));
    char *first_number = (char *)calloc(20 , sizeof(char));
    char *second_number = (char *)calloc(20 , sizeof(char));
    int check_zeros_begin = 0;

    Bg *first = _create();
    Bg *second = _create();

    scanf("%s %s %s\n", operation, first_number , second_number);

    int f_len = strlen(first_number);
    for(int i = 0 ; i < f_len ; i++){
      if(!check_zeros_begin){
        if(first_number[i] - '0'){
          _add(first , first_number[i] - '0');
          check_zeros_begin = 1;
        }
      }
      else{
        _add(first , first_number[i] - '0');
      }
    }
    check_zeros_begin = 0;
    int s_len = strlen(second_number);
    for(int j = 0 ; j < s_len ; j++){
      if(!check_zeros_begin){
        if(second_number[j] - '0'){
          _add(second , second_number[j] - '0');
          check_zeros_begin = 1;
        }
      }
      else{
        _add(second , second_number[j] - '0');
      }
    }

    printf("Resultado %d: " , count++);

    if(!strcmp(operation , "sum"))
      _sum(first , second);

    if(!strcmp(operation , "big"))
      printf("%d\n", _compare(first , second) == BIG);

    if(!strcmp(operation , "sml"))
      printf("%d\n", _compare(first , second) == SML);

    if(!strcmp(operation , "eql"))
      printf("%d\n", _compare(first , second) == EQL);

    _deallocate(first);
    _deallocate(second);

    number--;
  }


  return 0;
}
