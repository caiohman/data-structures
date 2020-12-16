#include <stdio.h>
#include <stdlib.h>
#include "llrb.h"

int main(int argc, char const *argv[]) {
  LLRB *llrb = _create();

  int number;
  scanf("%d\n", &number);

  while (number > 0) {
    int op;
    int value;
    scanf("%d", &op);

    switch (op) {
      case 1: //insertion
        scanf(" %d\n", &value);
        _insert(llrb , value);
        break;
      case 2: //pos
        scanf(" %d\n", &value);
        if(_search(llrb, value, POS) == ERROR) printf("%s\n", "erro");
        break;
      case 3: //pre
        scanf(" %d\n", &value);
        if(_search(llrb, value, PRE) == ERROR) printf("%s\n", "erro");
        break;
      case 4: //max
        _max_value(llrb);
        break;
      case 5: //min
        _min_value(llrb);
        break;
      case 6: //pre-order
        _print_pre_order(llrb);
        break;
      case 7: //in-order
        _print_in_order(llrb);
        break;
      case 8://pos-order
        _print_pos_order(llrb);
        break;
    }
    number--;
  }
  _delete(llrb);
  return 0;
}
