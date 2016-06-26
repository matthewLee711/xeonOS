#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void openFile(char* fileName);

int main(void){
  openFile("processes.txt");
  printf("done\n");
  //List * list = emptylist();
  

  // add(1, 3, 5, 6, list);
  // //add(20, list);
  // add(2, 3, 5, 6, list);
  // add(5, 3, 5, 6, list);
  // add(8, 3, 5, 6, list);
  // add(9, 3, 5, 6, list);
  // //add(13, list);
  // display(list);
  // delete(2, list);
  // display(list);
  // delete(1, list);
  // display(list);
  // delete(20, list);
  // display(list);
  // reverse(list);
  // printf("Reversed: ");
  // display(list);
  // destroy(list);
  return 0;
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
  if(file) {
    while((c = getc(file)) != EOF) {
      //extract numbers
      if(c != ',' || c != ' ' || c != '\n') {
        arrSize++;
        numConv = realloc(numConv, arrSize * sizeof *numConv);
        numConv[arrSize] = atoi(&c);
        printf("%c %i\n", c, numConv[arrSize]);
      } 
      //convert to full number
      else {
        printf("eee\n");
        //int mult = 1;
        //for(int i = 0; i < arrSize; i++){mult *= 10;}
        for (int i = 0; i < arrSize; i++) {
          //1 - 10 - 100 - 1000
          //mult /= 10;
          pcb[pcbIndex] = 10 * pcb[pcbIndex] + numConv[i];
        }
        printf("%i\n", pcb[0]);
        //reset
        arrSize = 0;
        numConv = realloc(numConv, arrSize * sizeof *numConv);
        pcbIndex++;
        subCounter++;
      }
      if(subCounter == 4) {
        //reset
        subCounter = 0;
        //debug print
        for (int i = 0; i < 4; ++i) {
          printf("%i ",pcb[i]);
          if(i % 4 == 0){
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