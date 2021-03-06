#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int arrival_time;
  int burst_time;
  int priority;
  struct node * next;
  struct node * previous;
} Node;

typedef struct list {
  Node * head;
} List;

//Process_id, arrival_time, burst_time, priority

List * emptylist();
void SJFadd(int id, int arrival_time, int burst_time, int priority, List * list);
void priorityAdd(int id, int arrival_time, int burst_time, int priority, List * list);
void delete(int id, List * list);
void display(List * list);
void reverse(List * list);
void destroy(List * list);

#endif
