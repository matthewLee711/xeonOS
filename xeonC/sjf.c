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

void openFile(char* fileName) {
	char c;
	//Open file
	int arrSize = 0;
	int* numConv = NULL;//dynamically allocated array
	int pcbIndex = 0;
	int pcb[4];//store numbers into here
	int subCounter = 0;

	FILE *file;
	file = fopen(fileName, "r");
	if (file) {
		while ((c = getc(file)) != EOF) {
			//convert to full number
			if (c == ',' || c == ' ' || c == '\n') {
				printf("eee\n");
				//write number
				for (int i = 0; i < arrSize; i++) {
					pcb[pcbIndex] = 10 * pcb[pcbIndex] + numConv[i];
				}
				printf("%i\n", pcb[0]);
				//reset
				arrSize = 0;
				numConv = realloc(numConv, arrSize * sizeof *numConv);
				pcbIndex++;
				subCounter++;
			}
			//extract numbers
			else {
				arrSize++;
				numConv = realloc(numConv, arrSize * sizeof *numConv);
				numConv[arrSize] = atoi(&c);
				printf("%c %i\n", c, numConv[arrSize]);
			}
			//Reset index in
			if (subCounter == 4) {
				//reset
				subCounter = 0;
				//debug print
				for (int i = 0; i < 4; ++i) {
					printf("%i ", pcb[i]);
					if (i % 4 == 0) {
						printf("\n");
					}
				}
				//add elements to linked list
			}
			//printf("%c", c);
		}
		free(numConv);
		fclose(file);
	}
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
