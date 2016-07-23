#include "Node.h"

Node::Node() {
	pid = 0;
	arrival_time = 0;
	burst_time = 0;
	priority = 0;
	duration = 0;
	size_of_memory = 0;
	next = nullptr;
}
Node::Node(int pid, int arrival_time, int burst_time, int priority) {
	this->pid = pid;
	this->arrival_time = arrival_time;
	this->burst_time = burst_time;
	this->priority = priority;
	next = nullptr;
}

Node::Node(int id, double arrival_time, int duration, int size_of_memory) {
	this->pid = pid;
	this->arrival_time = arrival_time;
	this->duration = duration;
	this->size_of_memory = size_of_memory;
}

int Node::getSizeOfMemory() {
	return size_of_memory;
}

int Node::getDuration() {
	return duration;
}

void Node::setDuration(int duration) {
	this->duration = duration;
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
