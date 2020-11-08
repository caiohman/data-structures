#include "revision.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Control *create(){
  Control *control = (Control *)calloc(1 , sizeof(Control));
  return control;
}

int delete(Control *control){
  if(control == NULL) return CONTROL_NO_EXIST;
  free(control);
  return OK;
}

void rev(Str *strr){
  //to check for \n\r
  strr->wrong[strcspn(strr->wrong, "\r\n")] = 0;
  strr->right[strcspn(strr->right, "\r\n")] = 0;

  int len = strlen(strr->old_string);
  int right_len = strlen(strr->right);
  int wrong_len = strlen(strr->wrong);

  for(int i = 0; i < len; i++){
    int l = 0, j = 0;
    while(*(strr->old_string + i) == *(strr->wrong + j)){
      i++;j++;
    }
    if(j == wrong_len){
      if(strr->new_string == NULL){
        strr->new_string = (char *)calloc(strlen(strr->old_string) + 1 , sizeof(char));
        strcpy(strr->new_string, strr->old_string);
      }
      int k;
      for(k = (i - j) ; k < i && l < right_len ; k++){ //check if right word has less chars or more chars
        *(strr->new_string + k) = *(strr->right + l++);
      }
      if(right_len == l && k < i){ //case right string is smaller than wrong string
        int m = 0;
        for(; k < len ; k++){
          *(strr->new_string + k) = *(strr->new_string + i + (m++));
        }
        len -= m;
      }
      if(right_len > l){ //case right string is bigger than wrong string
        int size = right_len - l;
        strr->new_string = (char *)realloc(strr->new_string, sizeof(char) * (size + strlen(strr->new_string) + 1));

        for(int p = 0 ; p < (len - k + 1) ; p++){ //move acual text to right.
          *(strr->new_string + len + size - p) = *(strr->new_string + len - p);
        }
        for(; k < len && right_len > l ; k++){
          *(strr->new_string + k) = *(strr->right + l++); // add string to text.
        }
        len += size;
      }
    }
  }
  if(strr->new_string == NULL){
    strr->new_string = (char *)calloc(strlen(strr->old_string) + 1 , sizeof(char));
    strcpy(strr->new_string, strr->old_string);
  }
  //printf("%s", strr->new_string);
}

int add(Control *control , String_stack *str){
  if(control == NULL) return CONTROL_NO_EXIST;

  Str *strr = (Str *)calloc(1, sizeof(Str));
  strr->right = pop(str);
  strr->wrong = pop(str);
  strr->old_string = pop(str);
  rev(strr);

  if(!control->cases) control->strings = strr;
  else{
    strr->next = control->strings; //insert at the beginning
    control->strings = strr;
  }
  control->cases++;
  return OK;
}

Str *pop_rev(Control *control){
  if(control == NULL) return NULL;
  Str *aux = control->strings;
  control->strings = aux->next;
  control->cases--;
  return aux;
}
char *get_new_string(Str *str){
  if(str == NULL) return NULL;
  return str->new_string;
}

int clean_str(Str *str){
  if(str == NULL) return STR_NO_EXIST;
  free(str);
  return OK;
}
