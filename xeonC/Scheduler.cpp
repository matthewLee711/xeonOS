#include "Scheduler.h"

Scheduler::Scheduler():head(nullptr) { }

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
}

void Scheduler::shortestJobFirst(int pid, int arrival_time, int burst_time, int priority) {
	//printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	Node * current;
	if (head == nullptr || link->getBurstTime() <= head->getBurstTime()) {
		link->setNext(head);
		head = link;
	}
	else {
		current = head;
		while (current->getNext() != nullptr && link->getBurstTime() < current->getBurstTime()) {
			current = current->getNext();
		}
		link->setNext(current->getNext());
		current->setNext(link);
	}
}

void Scheduler::priorityScheduler(int pid, int arrival_time, int burst_time, int priority) {
	//printf("%i %i %i %i\n", pid, arrival_time, burst_time, priority);
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	Node * current;
	if (head == nullptr || link->getPriority() <= head->getPriority()) {
		link->setNext(head);
		head = link;
	}
	else {
		current = head;
		while (current->getNext() != nullptr && link->getPriority() < current->getPriority()) {
			current = current->getNext();
		}
		link->setNext(current->getNext());
		current->setNext(link);
	}
}

//insert at tail. head will point to first node. add nodes will point
void Scheduler::defaultInsert(int pid, int arrival_time, int burst_time, int priority) {
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	if (head == nullptr) {
		head = link;
		std::cout << "good" << std::endl;
	}
	else {
		//temp store head. use current for iterating
		//if new node less than head, set head to point to new node.
		Node * temp = head;
		while (temp->getNext() != nullptr) {
			temp = temp->getNext();
		}
		temp->setNext(link);
	}
}

void Scheduler::defaultDelete() {

}

void Scheduler::deletePCB() {

}

void Scheduler::display() {
	Node * temp = head;//making reference to head
	while (temp->getNext() != nullptr) {
		printf("%i %i %i %i\n", temp->getPid(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());
		temp = temp->getNext();
	}
}


Scheduler::~Scheduler() {

}
