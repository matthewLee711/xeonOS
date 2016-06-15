#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void){
  List * list = emptylist();
  

  add(1, 3, 5, 6, list);
  //add(20, list);
  add(2, 3, 5, 6, list);
  add(5, 3, 5, 6, list);
  add(8, 3, 5, 6, list);
  add(9, 3, 5, 6, list);
  //add(13, list);
  display(list);
  delete(2, list);
  display(list);
  delete(1, list);
  display(list);
  delete(20, list);
  display(list);
  reverse(list);
  printf("Reversed: ");
  display(list);
  destroy(list);
  return 0;
}
