#ifndef MEMMANAGER
#define MEMMANAGER

#include "slots.hpp"
#include <iostream>
#include <string>

class MemManager
{
private:
	//first process
	Slot* firstSlot;

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
