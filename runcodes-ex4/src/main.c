#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);

  for(int i = 0 ; i < number ; i++){
    int n, k;
    List *list = create();

    scanf("%d %d", &n , &k);
    for(int j = 1 ; j <= n ; j++) add_list(list , j);
    int size = list_size(list);

    do{
      if(k <= size) search_and_remove(list , k);
      else{
        int calc = k % size;
        if(calc)
          search_and_remove(list , calc);
        else // when result is 0 add at the list's end.
          search_and_remove(list , size);
      }
      size = list_size(list);
    }while(size > 1);

    printf("Caso %d: %d\n", i + 1 , list_get_first(list));

    deallocate_list(list);
  }

  return 0;
}
