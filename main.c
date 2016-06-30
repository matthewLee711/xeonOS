#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
//#include "fcfs.h"
//#include "sjf.h"

void openFile(char* fileName);
void openFile2(char* fileName, List * list);
int main(void) {
  List * list = emptylist();
	openFile2("processes.txt", list);
	printf("done\n");
  //Process_id, arrival_time, burst_time, priority
	// add(2760, 1, 16, 1, list);
	// add(2750, 1, 9, 2, list);
	// add(2730, 3, 14, 5, list);
	// add(2750, 5, 3, 7, list);
	// add(2750, 6, 2, 9, list);
	// add(2750, 10, 20, 23, list);
	// add(2750, 11, 4, 4, list);
	// add(2750, 12, 6, 3, list);
	// add(2750, 15, 7, 3, list);
  printf("Testing\n");
	display(list);
  printf("Finished\n");
  char str[100];


  int stop = 0;
  int input;
  int inputInner;
  int send[4];
  // while(stop != 1) {
  //   printf("Press 0 to exit the program\n");
  //   printf("Press 1 to input a PCB into a scheduler\n");
  //   printf("Press 2 to remove a PCB\n");
  //   scanf("%d\n", &input);
  //   //End program
  //   if(input == 0) {
  //     break;
  //   }
  //   //Input pcb
  //   else if(input == 1) {
  //     printf("Enter an ID\n");
  //     scanf("%i\n", &inputInner);
  //     send[0] = inputInner;
  //     printf("Enter an arrival time\n");
  //     scanf("%i\n", &inputInner);
  //     send[1] = inputInner;
  //     printf("Enter an burst time\n");
  //     scanf("%i\n", &inputInner);
  //     send[2] = inputInner;
  //     printf("Enter an priority\n");
  //     scanf("%i\n", &inputInner);
  //     send[3] = inputInner;
  //
  //     printf("To insert in Shortest Job First Scheduler, press 0\n");
  //     printf("To insert in Non Preemptive Priority Scheduler, press 1\n");
  //     scanf("%i\n", &inputInner);
  //     if(inputInner == 0) {
  //       //SJFadd(send[0], send[1], send[2], send[3], list);
  //     }
  //     else if(inputInner == 1) {
  //       //priorityAdd(send[0], send[1], send[2], send[3], list);
  //     }
  //     else {
  //       printf("That is not a valid input\n");
  //     }
  //   }
  //   //delete pcb
  //   else if(input == 2) {
  //     printf("Type an id to delete a PCB\n");
  //     scanf("%i\n", &inputInner);
  //     delete(inputInner, list);
  //   }
  //   else{
  //     printf("Please enter a valid number\n");
  //   }
  //
  // }


	// delete(20, list);
	// reverse(list);
	// printf("Reversed: ");
	// display(list);
	// destroy(list);
	return 0;
}

void openFile2(char* fileName, List * list) {
	char c;
	//Open file
	int arrSize = 0;
	int numConv[10];
	int pcbIndex = 0;
	int pcb[4] = { 0, 0, 0, 0 };//store numbers into here
	int subCounter = 0;

	FILE *file;
	file = fopen(fileName, "r");
	if (file) {
		//while ((c = getc(file)) != EOF) {}
		while ((c = getc(file)) != EOF) {
			//convert to full number
			if (c == ',' || c == '\n') {
        //debug
        // printf("convert\n");
				// printf("cause of entry: %c %i\n", c, atoi(&c));
				// for (int i = 0; i < arrSize; i++) {
				// 	printf("num: %i index: %i\n", numConv[i], i);
				// }
				// for (int i = 0; i < 4; i++) {
				// 	printf("inside pcb: %i ", pcb[i]);
				// }printf("\n");
				//write number
				for (int i = 0; i < arrSize; i++) {
					pcb[pcbIndex] = 10 * pcb[pcbIndex] + numConv[i];
					//printf("converting. pcb: %i , num: %i\n", pcb[pcbIndex], numConv[i]);
				}
				//printf("converted num: %i %i %i %i\n", pcb[0], pcb[1], pcb[2], pcb[3]);
				//reset
				arrSize = 0;
				//clear out numConv
				for (int i = 0; i < 10; i++) { numConv[i] = 0; }
				pcbIndex++;//move to next index for add
				subCounter++; //counter to reset add
			}
			else if(c == ' ') {}//do nothing
			//extract numbers
			else {

				numConv[arrSize] = atoi(&c); arrSize++;
				//printf("extract: %c %i\n", c, numConv[arrSize]);
			}
			//Reset index for add
			if (subCounter == 4) {
				//reset
				subCounter = 0;
				pcbIndex = 0;
				//debug print
				printf("---------------------debug\n");
				for (int i = 0; i < 4; ++i) {
					printf("%i\n", pcb[i], i);
				}
				printf("---------------------debug\n");
        //SJFadd(pcb[0], pcb[1], pcb[2], pcb[3], list);
        priorityAdd(pcb[0], pcb[1], pcb[2], pcb[3], list);
        //clear out pcb[]
				for (int i = 0; i < 4; i++) {
					pcb[i] = 0;
				}
				// for (int i = 0; i < 4; i++) {
				// 	printf("clear: %i ", pcb[i]);
				// }
				//add elements to linked list
			}
			//printf("%c", c);
		} //End of while loop

		fclose(file);
	}
	printf("completed parse");
}
