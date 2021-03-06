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

void display(List * list) {
	Node * current = list->head;
	if (list->head == NULL)
		return;
	while (current->next != NULL) {
		printf("%d %d\n", current->id, current->burst_time);
		current = current->next;
	}
	printf("%d\n", current->id);
}

void SJFadd(int id, int arrival_time, int burst_time, int priority, List * list) {
	Node * current = NULL;

	Node * compare = createnode(id, arrival_time, burst_time, priority);
	Node * temp = NULL;                //Temp node to compare against
	Node * tempPrev = NULL;
	if (list->head == NULL) {
		list->head = createnode(id, arrival_time, burst_time, priority);
	}
	else {
		current = list->head;             //Grab current front
		printf("current head: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
		if (current->next == NULL) {
			printf("badwwwwww\n");
			current->next = createnode(id, arrival_time, burst_time, priority);
		}
		while (current->next != NULL) {
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
			//If equal, compare priority to place it
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
		//If it exists store it
		if (current->previous != NULL) {
			tempPrev = current->previous;
		}
		temp = current;             //temp store the larger
		current = compare;          //move smaller in front
		current->next = temp;       //have smaller point to larger
		current = current->next;    //move to large node
		current->previous = compare;//large node previous point to smaller
		//If not at head, original was pointing to large, now point to small
		if (tempPrev != NULL) {
			current = tempPrev;       //load original pointing to large
			current->next = compare;  //original point to small now
		}
		printf("Finished sorting number\n");
		while (current->previous != NULL) {
			current = current->previous;
			list->head = current;
		}
		while (current->next != NULL) {
			printf("printing: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
			current = current->next;
		}
	}
}

void priorityAdd(int id, int arrival_time, int burst_time, int priority, List * list) {
	printf("adding: %i %i %i %i\n", id, arrival_time, burst_time, priority);
	printf("%d\n", id);
	Node * current = NULL; //hold current node
	Node * holder = NULL;  //hold previous node
	Node * temp = NULL;    //hold new node
	Node * saver = NULL;
	int trigger = 0;
	if (list->head == NULL) {
		list->head = createnode(id, arrival_time, burst_time, priority);
	}
	else {
		current = list->head;
		printf("head: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
		temp = createnode(id, arrival_time, burst_time, priority);
		while (current->priority < temp->priority) {
			printf("iterating: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
			printf("temp: %i %i %i %i\n", temp->id, temp->arrival_time, temp->burst_time, temp->priority);
			holder = current;            //temporily hold previous node
			current = current->next;	 //move to compare against next node
			if (current == NULL) {       //End loop if reach tail
				printf("triggered\n");
				break;
			}
			trigger++;
		}
		//Works fine inserting at tail
		if (current == NULL) {       //End loop if reach tail
			printf("triggered2\n");
			printf("holder: %i %i %i %i\n", holder->id, holder->arrival_time, holder->burst_time, holder->priority);
			printf("new: %i %i %i %i\n", temp->id, temp->arrival_time, temp->burst_time, temp->priority);
			temp->next = current;         //New node point to node ahead
			current = holder;             //load in past node
			holder->next = temp;          //have past node point to new node
			//current = list->head; // reset head
		}
		else {
			temp->next = current;         //New node point to node ahead
			current = holder;             //load in past node
			holder->next = temp;          //have past node point to new node
		}
	}
	//debug print test
	printf("npps: 2120, 1, 7, 1\n");
	current = list->head;
	while (current->next != NULL)
	{
		current = current->next;
		printf("npps: %i %i %i %i\n", current->id, current->arrival_time, current->burst_time, current->priority);
	}
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
