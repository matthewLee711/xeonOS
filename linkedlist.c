#include "linkedlist.h"

Node * createnode(int id, int arrival_time, int burst_time, int priority);

Node * createnode(int id, int arrival_time, int burst_time, int priority){
  Node * newNode = malloc(sizeof(Node));
  newNode->id = id;
  newNode->arrival_time = arrival_time;
  newNode->burst_time = burst_time;
  newNode->priority = priority;
  newNode->next = NULL;
  return newNode;
}

List * emptylist(){
  List * list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

void display(List * list) {
  Node * current = list->head;
  if(list->head == NULL) 
    return;
  while(current->next != NULL){
    printf("%d,", current->id);
    current = current->next;
  }
  printf("%d\n", current->id); 
}

void add(int id, int arrival_time, int burst_time, int priority, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = createnode(id, arrival_time, burst_time, priority);
  }
  else {
    current = list->head; 
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(id, arrival_time, burst_time, priority);
  }
}

void delete(int id, List * list){
  Node * current = list->head;            
  Node * previous = current;           
  while(current != NULL){           
    if(current->id == id){      
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }                               
    previous = current;             
    current = current->next;        
  }                                 
}                                   

void reverse(List * list){
  Node * reversed = NULL;
  Node * current = list->head;
  Node * temp = NULL;
  while(current != NULL){
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  list->head = reversed;
}

void destroy(List * list){
  Node * current = list->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}
