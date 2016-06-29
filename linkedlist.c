#include "linkedlist.h"

Node * createnode(int id, int arrival_time, int burst_time, int priority);

Node * createnode(int id, int arrival_time, int burst_time, int priority) {
	Node * newNode = malloc(sizeof(Node));
	newNode->id = id;
	newNode->arrival_time = arrival_time;
	newNode->burst_time = burst_time;
	newNode->priority = priority;
	newNode->next = NULL;
	newNode->previous = NULL;
	return newNode;
}

List * emptylist() {
	List * list = malloc(sizeof(List));
	list->head = NULL;
	return list;
}

// void display(List * list) {
//   Node * current = list->head;
//   if(list->head == NULL)
//     return;
//   while(current->next != NULL){
//     printf("%d,", current->id);
//     current = current->next;
//   }
//   printf("%d\n", current->id);
// }

void display(List * list) {
	Node * current = list->head;
	if (list->head == NULL)
		return;
	while (current->next != NULL) {
		printf("%d %d\n", current->id, current->burst_time);
		current = current->next;
	}
	//backwards
	// while (current->previous != NULL) {
	// 	printf("%d,", current->id);
	// 	current = current->previous;
	// }
	printf("%d\n", current->id);
}

void add(int id, int arrival_time, int burst_time, int priority, List * list) {
	printf("adding: %i %i %i %i\n", id, arrival_time, burst_time, priority);
	printf("%d\n", id);
	Node * current = NULL;
	if (list->head == NULL) {
		list->head = createnode(id, arrival_time, burst_time, priority);
	}
	else {
		current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = createnode(id, arrival_time, burst_time, priority);
	}
}

void add2(int id, int arrival_time, int burst_time, int priority, List * list) {
	Node * current = NULL;
	Node * tempPrev = NULL;
	if (list->head == NULL) {
		list->head = createnode(id, arrival_time, burst_time, priority);
	}
	else {
		current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = createnode(id, arrival_time, burst_time, priority);
		tempPrev = current;
		current = current->next;
		current->previous = tempPrev;
	}
}

void SJFadd(int id, int arrival_time, int burst_time, int priority, List * list) {
  // printf("Displaying list before sort\n");
  // display(list);
  Node * current = NULL;
	//temp node to compare against
	Node * compare = createnode(id, arrival_time, burst_time, priority);
	Node * temp = NULL;
	Node * tempPrev = NULL;
	if (list->head == NULL) {
		list->head = createnode(id, arrival_time, burst_time, priority);
	}
	else {
		current = list->head;             //Grab current front
		//printf("about to enter: %i %i\n", current->burst_time, compare->burst_time);
    if(current->next == NULL) {
      printf("badwwwwww\n");
      current->next = createnode(id, arrival_time, burst_time, priority);
    }//
    //int stop = 1;
		while (current->next != NULL) {
			//printf("entered: %i\n", current->burst_time);
			//If compare is smaller, insert smaller in front of current
			if (current->burst_time > compare->burst_time) {
        break;
			}
			//If compare is bigger, move to next node
			else if (current->burst_time < compare->burst_time) {
				//move to next node
        printf("dsfjasdjfalsdfjasdflkjasd: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
				current = current->next;
			}
			//If equal, compare time to place it
			else if (current->burst_time == compare->burst_time) {
				//If the lower 5--3--8
				if (current->priority > compare->priority) {
					break;
				}
				//if current priority is smaller, move to next to compare against
				else if (current->priority < compare->priority) {
					current = current->next;
				}
				//If they are equal, compare arrival times.
				else if (current->priority == compare->priority) {
					//If time in current is larger, place small in front
					if (current->arrival_time > compare->arrival_time) {
						break;
					}
					//If time in current is smaller, move to next
					else if (current->arrival_time < compare->arrival_time) {
						current = current->next;
					}
					//If times equal, just place it lol
					else if (current->arrival_time == compare->arrival_time) {
						break;
					}
				}
			}
			//When reach end, end loop
			if (current->next == NULL) {
				break;
			}
		}
		//Check if there exists a previous Node
		//If it exists, store it
		if (current->previous != NULL) {
			tempPrev = current->previous;
		}
		//swap
    //FIGURE OUT WAY TO STORE HEAD
		temp = current;             //temp store the larger
		current = compare;          //move smaller in front
    // printf("prev node: %i %i %i %i\n", temp->id, temp->arrival_time, temp->burst_time, temp->priority);
    // printf("comp node: %i %i %i %i\n", compare->id, compare->arrival_time, compare->burst_time, compare->priority);
    // printf("newNode: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
		current->next = temp;       //have smaller point to larger
		current = current->next;    //move to large node
		current->previous = compare;//large node previous point to smaller
	  //If not at head, original was pointing to large, now point to small
		if (tempPrev != NULL) {
			current = tempPrev;       //load original pointing to large
			current->next = compare;  //original point to small now
		}
    printf("Finished sorting number\n");
    while(current->previous != NULL) {
      current = current->previous;
      list->head = current;
    }
    while(current->next != NULL) {
      printf("printing: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
      current = current->next;
    }
    //display(list);
	}//end of else

}


void delete(int id, List * list) {
	Node * current = list->head;
	Node * previous = current;
	while (current != NULL) {
		if (current->id == id) {
			previous->next = current->next;
			if (current == list->head)
				list->head = current->next;
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}

void reverse(List * list) {
	Node * reversed = NULL;
	Node * current = list->head;
	Node * temp = NULL;
	while (current != NULL) {
		temp = current;
		current = current->next;
		temp->next = reversed;
		reversed = temp;
	}
	list->head = reversed;
}

void destroy(List * list) {
	Node * current = list->head;
	Node * next = current;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	free(list);
}
