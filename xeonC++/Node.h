#ifndef NODE_H
#define NODE_H

class Node {
private:
	Node* next;
	int pid;
	int burst_time;
	int priority;
	int arrival_time;
	int size_of_memory;
	int duration;

public:
	Node();
	Node(int id, int arrival_time, int burst_time, int priority);
	Node(int id, double arrival_time, int duration, int size_of_memory);
	int getSizeOfMemory();
	int getDuration();
	void setDuration(int duration);
	void decrementDuration();
	int getPid();
	int getBurstTime();
	int getPriority();
	int getArrivalTime();
	Node* getNext();
	void setNext(Node* link);
};

#endif
