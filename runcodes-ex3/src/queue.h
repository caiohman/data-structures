#ifndef QUEUE_H
#define QUEUE_H

typedef struct elem{
  char *name;
  unsigned int age;
  unsigned int condition; // 0 for false and 1 for true
  struct elem *next;
}Elem;

typedef struct queue{
  Elem *first, *last;
  unsigned int size;
}Queue;

/*@Description: create queue*/
/*@param: none              */
/*@return: pointer to queue */
Queue *create();
/*@Description: mount element struct*/
/*@param: name, age , condition     */
/*@return: pointer to elem struct   */
Elem *capture(char *, unsigned int , unsigned int );
/*@Description: add elements to queue*/
/*@param: queue, elements            */
/*@return: none                      */
void add(Queue *, Elem *);
/*@Description: check queue size*/
/*@param: queue                 */
/*@return: queue size           */
int queue_size(Queue *queue);
/*@Description: remove from queue - nec to free after*/
/*@param: queue                                      */
/*@return: pointer to elem                           */
Elem *recover(Queue *queue);
/*@Description: print element  */
/*@param: element              */
/*@return: none                */
void elem_print(Elem *elem);
/*@Description: delete all queue's elements*/
/*@param: queue                            */
/*@return: none                            */
void delete_queue(Queue *queue);
#endif
