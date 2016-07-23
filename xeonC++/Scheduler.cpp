#include "Scheduler.h"

Scheduler::Scheduler() :head(nullptr), memHead(nullptr) {
	globalCounter = 1;
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
	else {
		std::cout << "Invalid Scheduler Choice\n";
	}
}

void Scheduler::shortestJobFirst(int pid, int arrival_time, int burst_time, int priority) {
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	Node * current;
	if (head == nullptr || link->getBurstTime() <= head->getBurstTime()) {
		link->setNext(head);
		head = link;
	}
	else {
		current = head;
		while (current->getNext() != nullptr && current->getNext()->getBurstTime() < link->getBurstTime()) {
			current = current->getNext();
		}
		link->setNext(current->getNext());
		current->setNext(link);
	}
}

void Scheduler::priorityScheduler(int pid, int arrival_time, int burst_time, int priority) {
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	Node * current;
	if (head == nullptr || link->getPriority() <= head->getPriority()) {
		link->setNext(head);
		head = link;
	}
	else {
		current = head;
		while (current->getNext() != nullptr && current->getNext()->getPriority() < link->getPriority()) {
			current = current->getNext();
		}
		link->setNext(current->getNext());
		current->setNext(link);
	}
}

//Insert at tail
void Scheduler::defaultInsert(int pid, int arrival_time, int burst_time, int priority) {
	Node * link = new Node(pid, arrival_time, burst_time, priority);
	if (head == nullptr) {
		head = link;
	}
	else {
		Node * current = head;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(link);
	}
}

void Scheduler::memSchedulerChooser() {

}

void Scheduler::initProcesses(int id, double arrival_time, int duration, int size_of_memory) {
	Node * link = new Node(id, arrival_time, duration, size_of_memory);
	if (head == nullptr) {
		head = link;
	}
	else {
		Node * current = head;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(link);
	}
	displayMemory();
	printf("-----------------------\n");
}

void Scheduler::headDelete() {
	if (head == nullptr) {
		std::cout << "You can't delete from an empty queue\n";
	}
	else {
		Node * temp = head->getNext();
		printf("Deleted pcb from ready queue: %i %i\n", head->getPid(), head->getDuration());
		printf("--------------------------------------------\n");
		delete head;
		head = temp;
	}
}

//checks if empty and adds processes to non-empty memories
//need check if ready queue is empty -- or crash
void Scheduler::allocateProcesses() {
	Node * current = head;
	Memory * memCurrent = memHead;
	while (memCurrent->getNext() != nullptr) {
		if (current != nullptr && memCurrent->getMemorySize() > current->getSizeOfMemory()) {//queue is empty error
			printf("allocate processes: size %i dur %i\n", current->getSizeOfMemory(), current->getDuration());
			//memCurrent->getRunQueue().push(current);//this doesnt work for some reason
			memCurrent->runQueue.push_front(current);
			memCurrent->runDuration.push(current->getDuration());//lol
			printf("runqueue push: size %i dur %i\n", memCurrent->getRunQueue().front()->getSizeOfMemory(), memCurrent->getRunQueue().front()->getDuration());
			printf("orig mem size: %i\n", memCurrent->getMemorySize());
			memCurrent->setMemorySize(memCurrent->getMemorySize() - current->getSizeOfMemory());
			printf("new mem size: %i\n", memCurrent->getMemorySize());
			printf("inside run queue: %i\n", memCurrent->getRunQueue().front()->getSizeOfMemory());
			headDelete();//once added, remove PCB from ready queue
			current = head;//re-update to new head
		}//add pcb to memory that has enough space, decrement memory
		else {
			printf("next memory\n");
			memCurrent = memCurrent->getNext();
		}//move to next memory slot, if cannot add process to it
	}
	//return true -- to indicate memory allocated
	//return memory not allocated
	//return ....
}
/*
void Scheduler::globalDecrement() {
	Memory * memCurrent = memHead;
	printf("memCurr size %i \n", memCurrent->getMemorySize());
	//printf("memCurr dur %i \n", memCurrent->runQueue.front()->getDuration()); //why not work
	printf("memCurr dur test %i \n", memCurrent->runDuration.front());
	while (memCurrent != nullptr) {
		if (memCurrent->runDuration.empty()) {
			printf("bad"); break;
		}
		memCurrent->runDuration.front();
		printf("decrement %i \n", memCurrent->runQueue.front()->getDuration());
		if (memCurrent->getRunQueue().front()->getDuration() == 0) {
			printf("popping %i \n", memCurrent->runQueue.front()->getDuration());
			memCurrent->setMemorySize(memCurrent->getMemorySize() + memCurrent->getRunQueue().front()->getSizeOfMemory());

			memCurrent->getRunQueue().pop();
		}//process reaches zero-> add back memory, remove process
		memCurrent = memCurrent->getNext();
	}
}*/

//iterate through and decrement, return if something reach 0?
void Scheduler::globalDecrement() {
	Memory * memCurrent = memHead;
	printf("memCurr size %i \n", memCurrent->getMemorySize());
	//printf("memCurr dur %i \n", memCurrent->runQueue.front()->getDuration()); //why not work
	printf("memCurr dur test %i \n", memCurrent->runDuration.front());
	while (memCurrent != nullptr) {
		if (memCurrent->getRunQueue().empty()) {
			printf("bad"); break;
		}
		memCurrent->runQueue.front()->decrementDuration();
		printf("decrement %i \n", memCurrent->runQueue.front()->getDuration());
		if (memCurrent->getRunQueue().front()->getDuration() == 0) {
			printf("popping %i \n", memCurrent->runQueue.front()->getDuration());
			memCurrent->setMemorySize(memCurrent->getMemorySize() + memCurrent->getRunQueue().front()->getSizeOfMemory());

			memCurrent->getRunQueue().pop_front();
			//memCurrent->getRunQueue().pop();
		}//process reaches zero-> add back memory, remove process
		memCurrent = memCurrent->getNext();
	}
}

//returns if memory is empty
bool Scheduler::isEmpty() {
	if (memHead == nullptr) {
		return true;
	}
	//NEED head is empty
	//iterate until clear.
}

void Scheduler::memoryInitializer(int startingAddress, int availableSpace) {
	Memory * link = new Memory(startingAddress, availableSpace);
	if (memHead == nullptr) {
		memHead = link;
	}
	else {
		Memory * current = memHead;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(link);
	}
	displayMemory();
}

//function which adds as many pcbs to memQueue as possible
//startingAddress,availableSpace
//[200,300],[600, 600],[1400, 350],[2000, 200],[2500, 750],[3500, 125]
void Scheduler::firstFitScheduler() {
	//keep iterating through trying to add proccesses.
	//use decrement global counter
	allocateProcesses();
	globalDecrement();
}

void Scheduler::bestFitScheduler() {

}

void Scheduler::displayMemory() {
	if (memHead != nullptr) {
		Memory * temp = memHead;
		while (temp->getNext() != nullptr) {
			printf("%i %i\n", temp->getMemorySize(), temp->getStartingAddress());
			temp = temp->getNext();
		}
		printf("%i %i\n", temp->getMemorySize(), temp->getStartingAddress());
	}
	else {
		std::cout << "The queue is empty\n";
	}
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
		printf("Deleted: %i %i %i %i\n", current->getPid(), current->getArrivalTime(), current->getBurstTime(), current->getPriority());
		delete current->getNext();
		current->setNext(nullptr);
	}
}



void Scheduler::deleteToEmpty() {
	if (head != nullptr) {
		Node *current = head;
		Node *temp;
		while (current != nullptr)
		{
			temp = current;
			current = current->getNext();
			delete temp;
			temp = nullptr;
		}
		head = nullptr;
	}
	else if (head == nullptr) {
		std::cout << "Queue is already empty\n";
	}
}

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
	std::cout << "--------------------------------------------------\n";
	std::cout << "The PID you are trying to delete does not exist\n";
	return 0;
}

double Scheduler::averageWaitTime() {
	double waitTime = 0.0;
	double totalTime = 0;
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

	waitTime -= total;
	waitTime /= double(totalNodes);
	std::cout << "Average wait time: " << waitTime << std::endl;
	return waitTime;
}

void Scheduler::display() {
	if (head != nullptr) {
		Node * temp = head;
		while (temp->getNext() != nullptr) {
			printf("%i %i %i %i\n", temp->getPid(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());
			temp = temp->getNext();
		}
		printf("%i %i %i %i\n", temp->getPid(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());
	}
	else {
		std::cout << "The queue is empty\n";
	}
}

Scheduler::~Scheduler() {
	if (head != nullptr) {
		Node * currrent = head;
		while (currrent != nullptr)
		{
			delete currrent;
			currrent = currrent->getNext();
		}
	}
}
