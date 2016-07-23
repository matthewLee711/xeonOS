#include "Memory.h"

Memory::Memory() {
	originalMemorySize = 0;
	memorySize = 0;
	startingAddress = 0;
	next = nullptr;
}

Memory::Memory(Memory* next, int originalMemorySize, int memorySize, int startingAddress) {
	this->originalMemorySize = originalMemorySize;
	this->memorySize = memorySize;
	this->startingAddress = startingAddress;
	next = nullptr;
}

Memory* Memory::getNext() {
	return this->next;
}

void Memory::setNext(Memory* next) {
	this->next = next;
}

int Memory::getOriginalMemorySize() {
	return originalMemorySize;
}

int Memory::getStartingAddress() {
	return startingAddress;
}

void Memory::setStartingAddress(int startingAddress) {
	this->startingAddress = startingAddress;
}
