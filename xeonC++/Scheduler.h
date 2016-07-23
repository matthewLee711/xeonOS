#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <iostream>
#include "Node.h"
#include "Memory.h"

class Scheduler {
private:
	Node * head;
	Memory * memHead;
	double sjfAverageTime;
  double priorityAverageTime;
public:
	Scheduler();
	void schedulerChooser(std::vector<int>pcb, Scheduler * list, int schedulerChoice);
	void shortestJobFirst(int pid, int arrival_time, int burst_time, int priority);
	void priorityScheduler(int pid, int arrival_time, int burst_time, int priority);
	void memSchedulerChooser();
	//initializes memory
	void memoryInitializer(int startingAddress, int availableSpace);
	//best fit scheduler -- can still use node
	void firstFitScheduler();
	void bestFitScheduler();
	void displayMemory();
	void defaultInsert(int pid, int arrival_time, int burst_time, int priority);
	void defaultDelete();
  void deleteToEmpty();
	int deletePCB(int pid);
  double averageWaitTime();
	void display();
	~Scheduler();
	/*
Size_of_memory
Number_of_available spaces
starting_address_1, available_space_1
starting_address_2,  available_space_2
…….
starting_address_N, available_space_N
number_of_processes
pid, arrival_time, duration, size_of_memory
pid, arrival_time, duration, size_of_memory
	*/

//ready queue will sort based on arrival time
//create memory sizes - memory will store PCB info

//initial load will put as many PCB in memory - FIRST FIT, BEST FIT
//insert a node will decrease memory size
//finishing processing a node will remove PCB and go to original

};

#endif
