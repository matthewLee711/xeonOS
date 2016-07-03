#include "Scheduler.h"

Scheduler::Scheduler() {
  Node * head = nullptr;
}

void Scheduler::schedulerChooser(std::vector<int> pcb, int schedulerChoice) {
  if(schedulerChoice == 0) {
    shortestJobFirst(pcb[0], pcb[1], pcb[2], pcb[3]);
  }
  else if (schedulerChoice == 1) {
    priorityScheduler(pcb[0], pcb[1], pcb[2], pcb[3]);
  }
  else if (schedulerChoice == 2) {
    defaultInsert(pcb[0], pcb[1], pcb[2], pcb[3]);
  }
}

void Scheduler::shortestJobFirst(int pid, int arrival_time, int burst_time, int priority) {
  printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
  Node * link = new Node(pid, arrival_time, burst_time, priority);
  if(head == nullptr) {

  }
}

void Scheduler::priorityScheduler(int pid, int arrival_time, int burst_time, int priority) {
  printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
}

void Scheduler::defaultInsert(int pid, int arrival_time, int burst_time, int priority){
  Node * link = new Node(pid, arrival_time, burst_time, priority);
  if(head == nullptr) {
    head = link;
  }
  else {
    while(head->getNext() != nullptr) {
      current = current->getNext();
    }
    current->setNext(link);
  }
}

void Scheduler::defaultDelete(){

}

void Scheduler::delete(){

}


Scheduler::~Scheduler() {

}
