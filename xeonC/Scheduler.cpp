#include "Scheduler.h"

Scheduler::Scheduler() :head(nullptr) { }

void Scheduler::schedulerChooser(std::vector<int> pcb, Scheduler * list, int schedulerChoice) {
	if (schedulerChoice == 0) {
		std::cout << "SJF\n";
		shortestJobFirst(pcb[0], pcb[1], pcb[2], pcb[3]);
	}
	else if (schedulerChoice == 1) {
		std::cout << "PRIORITY\n";
		priorityScheduler(pcb[0], pcb[1], pcb[2], pcb[3]);
	}
	else if (schedulerChoice == 2) {
		//defaultDelete();
		defaultInsert(pcb[0], pcb[1], pcb[2], pcb[3]);
	}
  else {
    std::cout << "Invalid Scheduler Choice\n";
  }
}

void Scheduler::shortestJobFirst(int pid, int arrival_time, int burst_time, int priority) {
	printf("insert: %i %i %i %i\n", pid, arrival_time, burst_time, priority);
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	Node * current;
	if (head == nullptr || link->getBurstTime() <= head->getBurstTime()) {
		link->setNext(head);
		head = link;
		//printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
	}
	else {
		current = head;
		while (current->getNext() != nullptr && current->getNext()->getBurstTime() < link->getBurstTime()) {
			current = current->getNext();
		}
		link->setNext(current->getNext());
		current->setNext(link);
    printf("point: %i %i %i %i\n", link->getPid(), link->getArrivalTime(), link->getBurstTime(), link->getPriority());
	}
	display();
	std::cout << "----------------------------\n";
}

void Scheduler::priorityScheduler(int pid, int arrival_time, int burst_time, int priority) {
	//printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	Node * current;
	if (head == nullptr || link->getPriority() <= head->getPriority()) {
		link->setNext(head);
		head = link;
		//printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
	}
	else {
		current = head;
		while (current->getNext() != nullptr && current->getNext()->getPriority() < link->getPriority()) {
			current = current->getNext();
		}
		link->setNext(current->getNext());
		current->setNext(link);
	}
  //printf("point: %i %i %i %i\n", link->getPid(), link->getArrivalTime(), link->getBurstTime(), link->getPriority());
	display();
	std::cout << "----------------------------\n";
}

//Insert at tail
void Scheduler::defaultInsert(int pid, int arrival_time, int burst_time, int priority) {
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	if (head == nullptr) {
		head = link;
		//std::cout << "good" << std::endl;
	}
	else {
		Node * current = head;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(link);
	}
  display();
  std::cout << "----------------------------\n";
}

void Scheduler::defaultDelete() {
  if(head == nullptr) {
    std::cout<<"You can't delete from an empty queue\n";
  }
  else {
    Node * temp = head->getNext();
    delete head;
    head = temp;
  }
}

int Scheduler::deletePCB(int pid) {
  if(head == nullptr) {
    std::cout<<"You can't delete from an empty queue\n";
  }
  else {
    Node * temp = head;
    while(temp->getPid() != pid) {
      temp = temp->getNext();
      if(temp == nullptr) {
        std::cout<<"The PID you want to delete does not exist\n";
        return 0;
      }
    }
    temp->setNext(temp->getNext()->getNext());
  }
}

void Scheduler::display() {
	Node * temp = head;//making reference to head
	while (temp->getNext() != nullptr) {
		printf("%i %i %i %i\n", temp->getPid(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());
		temp = temp->getNext();
	}
  printf("%i %i %i %i\n", temp->getPid(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());
}

Scheduler::~Scheduler() {

}
