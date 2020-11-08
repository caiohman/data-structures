#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[]) {
  int time = 0;
  List *list = create();
  char c;
  int n, j;

  do{
    scanf("%c", &c);
    switch (c) {
      case 'i':
        scanf(" %d %d", &n, &j);
        add(list, n, j, time++);
        break;
      case 'r':
        scanf(" %d", &n);
        remove_item(list, n);
        time++;
        break;
      case 'f':
        break;
    }
  }while(c != 'f'); //char command to stop  

  print_list(list);
  printf("\n");
  deallocate_list(list);

  return 0;
}
