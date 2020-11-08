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
    _insert(bt , left);
    _insert(bt , right);

    printf("no %d: \n", node);
    _delete(bt);

  }
  return 0;
}
