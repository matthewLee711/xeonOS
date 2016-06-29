#include "sjf.h"

void SJFschedulerDynamic(int id, int arrival_time, int burst_time, int priority) {
  Node * current = list->current;
  Node * temp = malloc(sizeof(Node));
  temp->id = id;
  temp->arrival_time = arrival_time;
  temp->burst_time = burst_time;
  temp->priority = priority;
  temp->next = NULL;

  //sort
  while(true) {
    //swap if smaller
    if(temp->arrival_time < current->arrival_time) {
      
    }
    //end loop
    else if(temp->arrival_time > current->arrival_time) {

    }
  }
}

void SJFscheduler(List* list) {
  Node * swap = list->head;
  Node * compare = list->head;
  Node * temp;
  int swap;
  //insertion sort
  while(true) {
    //Move to next set if a is less than b
    if(swap->arrival_time < compare->arrival_time) {
        swap = swap->next;
        compare = compare->next;
    }
    //Swap until a is less than b
    else if(swap->arrival_time > compare->arrival_time) {
      //swap contents of both linked lists
      temp->arrival_time = compare->arrival_time;
      compare->arrival_time = swap->arrival_time;
      swap->arrival_time = temp->arrival_time;

      //check if at head of linked list
      if (swap->previous == NULL) {
        printf("%s\n", "nope");
      }
       //back it up if not
      else {
        swap = swap->previous;
        compare = compare->previous;
      }
    }
    //if equal, just place next to each other
    else if(swap->arrival_time == compare->arrival_time) {

    }
    //End if reach end of loop
    else if(swap->next == null) {
      break;
    }
  }

}

void SJFdisplayPCB(List* list) {
  /* code */
  //calculate average wait time
  //Process_id, arrival_time, burst_time, priority
  //Create a hashmap
}


///Iterator Code
// Value array[N];
// typedef Value* iterator;
// iterator array_begin(Value a[]){ return &a[0];}
// iterator array_end(Value a[], int n){ return &a[n];}
// iterator array_next(iterator i) { return ++i;}

// iterator it = array_begin(a);
// iterator end = array_end(a,N);
// for (;it < end; it=array_next(it))
// {
//     Value v = *it;
// }
