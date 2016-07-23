#ifndef MEMORY_HEADER
#define MEMORY_HEADER

class Memory {
private:
	Memory* next;
	int originalMemorySize;
	int memorySize;
	int startingAddress;

public:
	Memory();
	Memory(int memorySize, int startingAddress);
	Memory* getNext();
	void setNext(Memory* next);
	int getOriginalMemorySize();//dont need set
  int getMemorySize();
  void setMemorySize(int memorySize);
	int getStartingAddress();
	void setStartingAddress(int startingAddress);
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
