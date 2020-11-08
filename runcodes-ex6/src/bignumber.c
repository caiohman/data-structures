#include <stdlib.h>
#include <stdio.h>
#include "bignumber.h"
#include <assert.h>

Bg *_create(){
  Bg *bg = (Bg *)calloc(1, sizeof(Bg));
  return bg;
}

void _print_foward(Bg *bg){
  Node *aux = bg->first;

  do{
    printf("%d", aux->elem);
    aux = aux->next;
  }while(aux != bg->first);
  printf("\n");
}

void _deallocate(Bg *bg){
  assert(bg != NULL);

  while (bg->size){
    Node *aux = bg->first;
    bg->first = aux->next;
    free(aux);
    bg->size--;
  }
  bg->last = NULL;
  free(bg);
}

void _add(Bg *bg, int number){
  assert(bg != NULL);

  Node *node = (Node *)calloc(1 , sizeof(Node));
  node->elem = number;

  if(!bg->size){ //first insertion
    bg->first = node->next = node->before = node;
  }
  else{
    node->before = bg->last;
    node->next = bg->first;
    bg->last->next = node;
  }
  bg->last = bg->first->before = node;
  bg->size++;
}

void _add_begin(Bg *bg, int number){
  assert(bg != NULL);

  Node *node = (Node *)calloc(1 , sizeof(Node));
  node->elem = number;

  node->next = bg->first;
  node->before = bg->last;
  bg->first = bg->last->next = node;
  bg->size++;
}

int check_sinal(Bg *bg){
  if(bg->first->elem == -3)
    return 1; // negative number
  return 0;
}

void _sum(Bg *first, Bg *second){

  //check existance
  assert(first != NULL);
  assert(second != NULL);

  //check if there is something
  assert(first->size);
  assert(second->size);

  Node *aux1 = first->last;
  Node *aux2 = second->last;
  int carry = 0;

  if(first->size == second->size || first->size > second->size){
    do{
      aux1->elem += carry;
      int aux = aux1->elem + aux2->elem; //sum and store in an aux
      carry = aux / 10; // if number is greater than 9
      aux1->elem = aux % 10;
      aux1 = aux1->before;
      aux2 = aux2->before;
    }while(aux1 != first->last && aux2 != second->last);

    if(first->size == second->size){
      if(carry)
        _add_begin(first, carry); // add at the beginning
    }
    else{
      if(first->size > second->size){
        if(carry){
          do{
            int aux = aux1->elem + carry;
            carry = aux / 10;
            aux1->elem = aux % 10;
            aux1 = aux1->before;
          }while(aux1 != first->last);
        }
      }
    }
    _print_foward(first);
  }

  else{
    do{
      aux2->elem += carry;
      int aux = aux1->elem + aux2->elem; //sum and store in an aux
      carry = aux / 10; // if number is greater than 9
      aux2->elem = aux % 10;
      aux1 = aux1->before;
      aux2 = aux2->before;
    }while(aux1 != first->last && aux2 != second->last);

    if(carry){
      do{
        int aux = aux2->elem + carry;
        carry = aux / 10;
        aux2->elem = aux % 10;
        aux2 = aux2->before;
      }while(aux2 != second->last);

      if(carry)
        _add_begin(second, carry); // add at the beginning
    }
    _print_foward(second);
  }
}

int _compare(Bg *first, Bg *second){

  //check existance
  assert(first != NULL);
  assert(second != NULL);

  //check if there is something
  assert(first->size);
  assert(second->size);

  if(!check_sinal(first) && check_sinal(second)) //positive and negative
    return BIG;

  if(check_sinal(first) && !check_sinal(second)) //negative and positive
    return SML;

  if(first->size == second->size){
    Node *aux1 = first->first;
    Node *aux2 = second->first;

    do{
      if(aux1->elem > aux2->elem)
        return BIG;
      if(aux1->elem < aux2->elem)
        return SML;

      aux1 = aux1->next;
      aux2 = aux2->next;
    }while(aux1 != first->first);
    return EQL;
  }

  if(first->size > second->size){
    Node *aux1 = first->first;
    Node *aux2 = second->first;
    int count = 0;

    do{
      if(count + second->size < first->size){
        if(aux1->elem > 0)
          return BIG;
      }
      else{
        if(aux1->elem > aux2->elem)
          return BIG;
        if(aux1->elem < aux2->elem)
          return SML;
        aux2 = aux2->next;
      }
      aux1 = aux1->next;
      count++;
    }while(aux1 != first->first);
    return EQL;
  }

  if(first->size < second->size){
    Node *aux1 = first->first;
    Node *aux2 = second->first;
    int count = 0;

    do{
      if(count + first->size < second->size){
        if(aux2->elem > 0)
          return SML;
      }
      else{
        if(aux2->elem > aux1->elem)
          return SML;
        if(aux2->elem < aux1->elem)
          return BIG;
        aux1 = aux1->next;
      }
      aux2 = aux2->next;
      count++;
    }while(aux2 != first->first);
    return EQL;
  }
  return 0;
}
