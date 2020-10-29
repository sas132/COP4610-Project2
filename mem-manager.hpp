#ifndef MEMMANAGER
#define MEMMANAGER

#include "slots.hpp"
#include "processes.hpp"
#include <iostream>
#include <string>

class MemManager
{
private:
	Process* firstProcess;
	Slot* firstSlot;
	int numSlots;
	int numProcesses;

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
