#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

int main(int argc, char const *argv[]) {
  unsigned int number;

  Queue *queue1 = create();
  Queue *queue2 = create();
  Queue *queue3 = create();
  Queue *queue4 = create();

  scanf("%d\n", &number);

  for(int i = 0; i < number; i++){
    Elem *elem = NULL;
    char name[20];
    char option[6];
    unsigned int age;
    unsigned int condition;
    Elem *rec = NULL;

    scanf("%s", option); //only chars

    if(strcmp(option,"SAI") == 0){
      int cases = 1;
      switch (cases) {
        case 1:
          if(queue_size(queue1)){ rec = recover(queue1); break; }
        case 2:
          if(queue_size(queue2)){ rec = recover(queue2); break; }
        case 3:
          if(queue_size(queue3)){ rec = recover(queue3); break; }
        case 4:
          if(queue_size(queue4)){ rec = recover(queue4); break; }
        case 5:
          printf("%s\n", "FILA VAZIA");
          break;
      }

      if(rec != NULL){
        elem_print(rec);
        free(rec);
      }
    }
    else{
      scanf("%s %d %d", name, &age, &condition);

      elem = capture(name, age, condition); //receive all infos.

      if(condition && age >= 60){ add(queue1, elem); } //add to queue priority1
      if(condition && age < 60){ add(queue2, elem); } //add to queue priority2
      if(!condition && age >= 60){ add(queue3, elem); } //add to queue priority3
      if(!condition && age < 60){ add(queue4, elem); } //add to queue priority4
    }
  }

  delete_queue(queue1);
  delete_queue(queue2);
  delete_queue(queue3);
  delete_queue(queue4);

  return 0;
}
