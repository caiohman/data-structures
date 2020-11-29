#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dictionary.h"

int main(int argc, char const *argv[])
{

  Dictionary *dict = _create();
  char op[15], word[51], meaning[140];

  while(scanf("%s ", op) != EOF){
      if(!strcmp(op , "insercao")){
        scanf("%s ", word);
        fflush(stdin);
        scanf("%[^\n]s", meaning);
        _insert(dict, word, meaning);
        continue;
      }
      if(!strcmp(op , "alteracao")){
        scanf("%s ", word);
        fflush(stdin);
        scanf("%[^\n]s", meaning);
        (_change(dict , word, meaning)) ? printf("%s\n", "OPERACAO INVALIDA"): fflush(stdin);
        continue;
      }
      if(!strcmp(op , "remocao")){
        scanf("%s ", word);
        (_delete(dict , word)) ? printf("%s\n", "OPERACAO INVALIDA"): fflush(stdin);
        continue;
      }
      if(!strcmp(op , "busca")){
        scanf("%s ", word);
        (_search(dict , word)) ? printf("%s\n", "OPERACAO INVALIDA"): fflush(stdin);
        continue;
      }
      if(!strcmp(op , "impressao")){
        char c;
        scanf("%c", &c);
        (_print(dict , c)) ? printf("NAO HA PALAVRAS INICIADAS POR %c\n", c): fflush(stdin);

        continue;
      }
  }

  _free(dict);
 return 0;
}
