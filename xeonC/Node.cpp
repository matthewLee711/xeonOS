#include "Node.h"

Node::Node() {
	pid = 0;
	arrival_time = 0;
	burst_time = 0;
	priority = 0;
	next = nullptr;
}
Node::Node(int pid, int arrival_time, int burst_time, int priority) {
	this->pid = pid;
	this->arrival_time = arrival_time;
	this->burst_time = burst_time;
	this->priority = priority;
	next = nullptr;
}

int Node::getPid() {
	return pid;
}

int Node::getBurstTime() {
	return arrival_time;
}

int Node::getPriority() {
	return priority;
}

int Node::getArrivalTime() {
	return burst_time;
}

void Node::setNext(Node* link) {
	this->next = link;
}

Node* Node::getNext() {
	return this->next;
}
