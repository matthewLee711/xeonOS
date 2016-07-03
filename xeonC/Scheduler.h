#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Node.h"

class Scheduler {
private:

public:
  List();
  void schedulerChooser(vector<int>pcb, int schedulerChoice);
  void shortestJobFirst(int pid, int arrival_time, int burst_time, int priority);
  void priorityScheduler(int pid, int arrival_time, int burst_time, int priority);
  
};

#endif
