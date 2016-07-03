#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void openFile(char* fileName, List * list);

int main(void) {
	List * list = emptylist();
	//Process_id, arrival_time, burst_time, priority
	openFile("processes.txt", list);
	//Processes user inputs
	int num, nitems;
	char input[100];
	int stop = 0;
	char inputInner[100];
	int send[4];
	while (stop != 1) {
		printf("Press 0 to exit the program\n");
		printf("Press 1 to input a PCB into a scheduler\n");
		printf("Press 2 to remove a PCB\n");
		nitems = scanf("%d", &num);
		//End program
		if (nitems == 0) {
			break;
		}
		//Input pcb
		else if (nitems == 1) {
			printf("Enter an ID\n");
			nitems = scanf("%d", &num);
			send[0] = nitems;
			printf("Enter an arrival time\n");
			nitems = scanf("%d", &num);
			send[1] = nitems;
			printf("Enter an burst time\n");
			nitems = scanf("%d", &num);
			send[2] = nitems;
			printf("Enter an priority\n");
			nitems = scanf("%d", &num);
			send[3] = nitems;

			printf("To insert in Shortest Job First Scheduler, press 0\n");
			printf("To insert in Non Preemptive Priority Scheduler, press 1\n");
			nitems = scanf("%d", &num);
			if (nitems == 0) {
				SJFadd(send[0], send[1], send[2], send[3], list);
			}
			else if (nitems == 1) {
				priorityAdd(send[0], send[1], send[2], send[3], list);
			}
			else {
				printf("That is not a valid input\n");
			}
		}
		//delete pcb
		else if (nitems == 2) {
			printf("Type an id to delete a PCB\n");
			nitems = scanf("%d", &num);
			delete(nitems, list);
		}
		else {
			printf("Please enter a valid number\n");
		}

	}

	display(list);
	destroy(list);
	return 0;
}

void openFile(char* fileName, List * list) {
	char c;
	//Open file
	int arrSize = 0;
	int numConv[10];
	int pcbIndex = 0;
	int pcb[4] = { 0, 0, 0, 0 };
	int subCounter = 0;

	FILE *file;
	file = fopen(fileName, "r");
	if (file) {
		while ((c = getc(file)) != EOF) {
			//convert to full number
			if (c == ',' || c == '\n') {
				for (int i = 0; i < arrSize; i++) {
					pcb[pcbIndex] = 10 * pcb[pcbIndex] + numConv[i];
				}
				//reset
				arrSize = 0;
				//clear out numConv
				for (int i = 0; i < 10; i++) { numConv[i] = 0; }
				pcbIndex++;   //move to next index for add
				subCounter++; //counter to reset add
			}
			else if (c == ' ') {}//do nothing
								 //extract numbers
			else {
				numConv[arrSize] = atoi(&c); arrSize++;
			}
			//Reset index for add
			if (subCounter == 4) {
				//reset
				subCounter = 0;
				pcbIndex = 0;

				//SJFadd(pcb[0], pcb[1], pcb[2], pcb[3], list);
				priorityAdd(pcb[0], pcb[1], pcb[2], pcb[3], list);
				//clear out pcb[]
				for (int i = 0; i < 4; i++) {
					pcb[i] = 0;
				}
			}
		}
		fclose(file);
	}
}
