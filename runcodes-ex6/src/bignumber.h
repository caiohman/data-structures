#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#define EQL 0
#define BIG 1
#define SML -1

typedef struct node{
  int elem;
  struct node *next, *before;
}Node;

typedef struct bg{
  int size;
  Node *first, *last;
}Bg;


/*@Description: allocate space for big numbers list*/
/*@param: none                                     */
/*@return: pointer to space                        */
Bg *_create();
/*@Description: allocate space for big numbers list*/
/*@param: pointer to bn list, value to add         */
/*@return: none                                    */
void _add(Bg *, int);
/*@Description: deallocate space of big numbers list*/
/*@param: pointer to bn list                        */
/*@return: none                                     */
void _deallocate(Bg *);
/*@Description: sum two values                                */
/*@param: pointer to first bn list , pointer to second bn list*/
/*@return: print result                                       */
void _sum(Bg *, Bg *);
/*@Description: compare two big numbers                       */
/*@param: pointer to first bn list , pointer to second bn list*/
/*@return: EQL 0 , BIG 1 , SML -1                             */
int _compare(Bg *, Bg *);

#endif
