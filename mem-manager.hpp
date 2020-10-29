#ifndef MEMMANAGER
#define MEMMANAGER

#include "slots.hpp"
#include <iostream>

class MemManager
{
private:
	//first process

public:
	MemManager();
	void askSlots();
	void askDisplacement();
	void askProcesses();
	void displaySlots();
	void displayProcesses();
	void runManager();
};

#endif
