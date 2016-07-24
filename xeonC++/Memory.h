#ifndef MEMORY_HEADER
#define MEMORY_HEADER
#include <deque>
#include "Node.h"

class Memory {
private:
	Memory* next;
	int originalMemorySize;
	int memorySize;
	int startingAddress;


public:
	std::deque<Node *> runQueue;
	//std::vector<Node *> runQueue;
	std::queue<int> runDuration;
	Memory();
	Memory(int memorySize, int startingAddress);
	Memory* getNext();
	void setNext(Memory* next);
	int getOriginalMemorySize();//dont need set
	int getMemorySize();
	void setMemorySize(int memorySize);
	int getStartingAddress();
	void setStartingAddress(int startingAddress);
	std::deque<Node *> getRunQueue();
	int memID;
};

#endif


// Size_of_memory
// Number_of_available spaces
// starting_address_1, available_space_1
// starting_address_2, available_space_2
// …….
// starting_address_N, available_space_N
// number_of_processes
// pid, arrival_time, duration, size_of_memory
// pid, arrival_time, duration, size_of_memory
