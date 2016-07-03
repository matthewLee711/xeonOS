#include "Scheduler.h"

Scheduler::Scheduler() {
	Node * head = nullptr;
}

void Scheduler::schedulerChooser(std::vector<int> pcb, Scheduler * list, int schedulerChoice) {
	if (schedulerChoice == 0) {
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
	if (head == nullptr) {
		head = link;
	}
}

void Scheduler::priorityScheduler(int pid, int arrival_time, int burst_time, int priority) {
	printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
}
//insert at at. head will point to first node. add nodes will point
void Scheduler::defaultInsert(int pid, int arrival_time, int burst_time, int priority) {
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	if (head == nullptr) {
		head = link;
	}
	else {
		//temp store head. use current for iterating
		//if new node less than head, set head to point to new node.
		while (head->getNext() != nullptr) {
			head->getNext();
		}
		head->setNext(link);
	}
}

void Scheduler::defaultDelete() {

}

void Scheduler::deletePCB() {

}

void Scheduler::display() {
	/*Node * temp = head;
	while (temp->getNext != nullptr) {
		std::cout << "pid: " << temp->getPid() << std::endl;
		temp->getNext();
	}*/
}


Scheduler::~Scheduler() {

}
