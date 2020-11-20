#include <stdio.h>
#include <stdlib.h>
#include "bt.h"

int main(int argc, char const *argv[]) {
  Bt *bt = _create();
  int number;
  scanf("%d", &number);

  for(int i = 0 ; i < number ; i++){
    int node, left, right;
    scanf("%d %d %d", &node , &left , &right);
    //printf("%d %d %d\n", node, left, right);
    _insert(bt, node, i);
    _insert(bt, left, i);
    _insert(bt , right , i);
  }

  _print_pre(bt);
  _delete(bt);
  printf("\n");
  return 0;
}
