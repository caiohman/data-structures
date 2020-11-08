#ifndef LIST_H
#define LIST_H

typedef struct elem{
  int elem;
  struct elem *next;
}Elem;

typedef struct list{
  Elem *first, *last;
  int size;
}List;

/*@Description: create list of data*/
/*@param: none                     */
/*@return: pointer to list         */
List *create();
/*@Description: delete list        */
/*@param: list                     */
/*@return: none                    */
void deallocate_list(List *);
/*@Description: insert elem to list */
/*@param: list and element          */
/*@return: none                     */
void add_list(List *, int );
/*@Description: insert elem to list              */
/*@param: list and element and position requered */
/*@return: none                                  */
void search_and_remove(List *, int );
/*@Description: show list's number of elements */
/*@param: list                                 */
/*@return: number of elements                  */
int list_size(List *);
/*@Description: get list's first element*/
/*@param: list                          */
/*@return: value stored                 */
int list_get_first(List *);
#endif
