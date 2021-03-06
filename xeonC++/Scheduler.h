#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <iostream>
#include "Node.h"

class Scheduler {
private:
	Node * head;
	double sjfAverageTime;
  double priorityAverageTime;
public:
	Scheduler();
	void schedulerChooser(std::vector<int>pcb, Scheduler * list, int schedulerChoice);
	void shortestJobFirst(int pid, int arrival_time, int burst_time, int priority);
	void priorityScheduler(int pid, int arrival_time, int burst_time, int priority);
	void defaultInsert(int pid, int arrival_time, int burst_time, int priority);
	void defaultDelete();
  void deleteToEmpty();
	int deletePCB(int pid);
  double averageWaitTime();
	void display();
	~Scheduler();
};

#endif
