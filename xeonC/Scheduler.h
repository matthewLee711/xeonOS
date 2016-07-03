#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Node.h"

class Scheduler {
private:
  Node * head;

public:
  Scheduler();
  void schedulerChooser(vector<int>pcb, Scheduler * list, int schedulerChoice);
  void shortestJobFirst(int pid, int arrival_time, int burst_time, int priority);
  void priorityScheduler(int pid, int arrival_time, int burst_time, int priority);
  void defaultInsert();
  void defaultDelete();
  void delete();
  ~Scheduler();
};

#endif
