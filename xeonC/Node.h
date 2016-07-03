#ifndef NODE_H
#define NODE_H

class Node {
private:
  Node next;

  int pid;
  int burst_time;
  int priority;
  int arrival_time;

public:
  Node();
  Node(int id, int arrival_time, int burst_time, int priority);
  int getPid();
  int getBurstTime();
  int getPriority();
  int getArrivalTime();
  Node getNext();
  void setNext(Node* link);

};

#endif
