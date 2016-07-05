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
	//arrival_time
	//Completion time = burst_time + arrival_time
	//Turnaround time = completionTime - arrival_time
	//Wait time = (completionTime - arrival_time) - Burst time
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
	if (head == nullptr) {
		std::cout << "You can't delete from an empty queue\n";
	}
	else {
		Node * current = head;
		while (current->getNext()->getNext() != nullptr) {
			current = current->getNext();
		}
		printf("point: %i %i %i %i\n", current->getPid(), current->getArrivalTime(), current->getBurstTime(), current->getPriority());
		delete current->getNext();
		current->setNext(nullptr);
	}
}
/*
int Scheduler::deletePCB(int pid) {
	if (head == nullptr) {
		std::cout << "You can't delete from an empty queue\n";
	}
	else if (head->getPid() == pid) {
		printf("2 %i ---- %i",head->getPid(), pid);
		Node * temp = head;
		delete head;
		head = temp->getNext();
	}
	else {
		printf("3 %i ---- %i", head->getPid(), pid);
		Node * temp = head;
		while (temp->getPid() != pid) {
			temp = temp->getNext();
			if (temp == nullptr) {
				std::cout << "The PID you want to delete does not exist\n";
				return 0;
			}
		}
		delete temp->getNext();
		temp->setNext(temp->getNext()->getNext());
		return pid;
	}
}
*/
int Scheduler::deletePCB(int pid) {
	Node * current = head;
	Node * previous = current;
	while (current != NULL) {
		if (current->getPid() == pid) {
			previous->setNext(current->getNext());
			if (current == head)
				head = current->getNext();
			delete current;
			current = nullptr;
			return 0;
		}
		previous = current;
		current = current->getNext();
	}
	return 0;
}

double Scheduler::averageWaitTime() {
	double waitTime = 0.0;
	double totalTime = 0; //for purposes of calculating incremental wait time
	double finalBurst = 0;
	double total = 0;
	int totalNodes = 0;
	Node * current = head;

	while (current != nullptr) {
		totalNodes++;
		total += current->getBurstTime();
		waitTime += total;
		waitTime -= current->getArrivalTime();
		current = current->getNext();
	}

	waitTime -= total; //for last process
	waitTime /= double(totalNodes);
	std::cout << "avg wait time: " << waitTime << std::endl;
	return waitTime;
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
