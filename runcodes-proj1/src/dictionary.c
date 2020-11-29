#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <limits.h>

Node *_node_create(char *key, char * meaning, int level){
  Node *node = (Node *)calloc(1 , sizeof(Node));
  node->key = (Elem *)calloc(1, sizeof(Elem));
  node->key->word = (char *)calloc(strlen(key) , sizeof(char));
  node->key->meaning = (char *)calloc(strlen(meaning) , sizeof(char));
  strcpy(node->key->word, key);
  strcpy(node->key->meaning, meaning);
  node->forward = (Node **)calloc(level + 1, sizeof(Node *));

  return node;
}

Dictionary* _create(){
  Dictionary *dict = (Dictionary *)calloc(1 , sizeof(Dictionary));

  dict->header = _node_create("" , "" , MAX_LEVEL);

  dict->level = 0;
  srand(time(NULL)); //seed for pseudo-random number generator
  return dict;
}

int rand_level(){
  int level = 0;
  while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) //generate pseudo-random numbers
   level++;
  return level;
}

void _insert(Dictionary *dict, char *key, char *meaning){
  assert(dict);

  //create update array and init
  Node *update[MAX_LEVEL + 1];
  memset(update, 0, sizeof(Node *) * (MAX_LEVEL + 1));  //initialize

  Node *current = dict->header;


  //start from highest level reach level 0
  for(int i = dict->level ; i >= 0 ; i--){ // all go to level 1
    while(current->forward[i] &&
    strcmp(current->forward[i]->key->word , key) < 0
    ){
      current = current->forward[i];
    }
    update[i] = current; //store only 1 value per level
  }

  /* reached level 0 and forward pointer to
     right to insert
  */
  current = current->forward[0];

  if((!current) || strcmp(key , current->key->word) != 0) {
      int level = rand_level();
       if (level > dict->level) {
           for (int i = dict->level + 1; i <= level + 1; i++) {
               update[i] = dict->header; // add 1° value of all headers to update
           }
          dict->level = level;
      }

      Node *new_node = _node_create(key , meaning, MAX_LEVEL);


      for (int i = 0; i <= level; i++) {
        new_node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = new_node;
      }
  }
  return;
}

int _search(Dictionary *dict, char *key){
  assert(dict);

  Node *current = dict->header;

  for (int i = dict->level; i >= 0; i--) {
      while (current->forward[i] &&
      strcmp(current->forward[i]->key->word , key) < 0
      ){
          current = current->forward[i];
       }
  }

  current = current->forward[0];

  if ((current) && !strcmp(current->key->word , key)){ //found
    printf("%s %s\n", current->key->word , current->key->meaning);
    return 0;
  }
  return 1;
}

int _delete(Dictionary *dict, char *key){
    assert(dict);

    Node *update[MAX_LEVEL + 1];
    Node *current = dict->header;

    for (int i = dict->level; i >= 0; i--) {
      while (current->forward[i] &&
        strcmp(current->forward[i]->key->word , key) < 0
      ){
        current = current->forward[i];
      }
      update[i] = current;
    }

    current = current->forward[0];

    if ((current) && !strcmp(current->key->word , key)) {

      for (int i = 0; i <= dict->level; i++) {
        if (update[i]->forward[i] != current)
          break;
        update[i]->forward[i] = current->forward[i];
      }

      while(dict->level > 0 &&
      dict->header->forward[dict->level] == 0
      ){
        dict->level--;
      }
        return 0;
    }
    return 1;
}

int _print(Dictionary *dict, char c){
  assert(dict);

  Node *current = dict->header;

  for (int i = dict->level; i >= 0; i--) {
      while (current->forward[i] &&
      current->forward[i]->key->word[0] > c
      ){
          current = current->forward[i];
       }
  }

  current = current->forward[0];

  if ((current) && current->key->word[0] == c){ //found
    do{
      printf("%s %s\n", current->key->word , current->key->meaning);
      current = current->forward[0];
    }while((current) && current->key->word[0] == c);

    return 0;
  }
  return 1;

}

void _free(Dictionary *dict){
    assert(dict);
    //free elements
    // Node *current = dict->header->forward[0];
    // while(current){
    //   free(current->key->word);
    //   free(current->key->meaning);
    //   free(current->key);
    //   current = current->forward[0];
    // }
    //free positions
    for(int i = MAX_LEVEL; i >= 0 ; i--){
      Node *current = dict->header->forward[i];
      while (current) {
          current = current->forward[i];
      }
      free(current);
    }
    free(dict);
}


int _change(Dictionary *dict, char *key, char *meaning){
  assert(dict);

  Node *current = dict->header;

  for (int i = dict->level; i >= 0; i--) {
      while (current->forward[i] &&
      strcmp(current->forward[i]->key->word , key) < 0
      ){
          current = current->forward[i];
       }
  }

  current = current->forward[0];

  if ((current) && !strcmp(current->key->word , key)){ //found
      memset(current->key->meaning, 0 , 140);
      strcpy(current->key->meaning , meaning);

      return 0;
  }
  return 1;
}
