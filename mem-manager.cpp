#include "mem-manager.hpp"
#include <iostream>

MemManager::MemManager()
{
	std::cout << "This memory manager program allocates slots to processes using the First Fit Dynamic Relocation.\n\n";
}

void MemManager::askSlots()
{
	std::cout << "Please enter the base locations of the slots: ";
	//accept input
	//send input to parser
	//send each data to a slot
}

void MemManager::askDisplacement()
{
	std::cout << "Please enter the displacements for the base locations previously entered by you: ";
	//accept input
	//send input to parser
	//send each data to related slot
}

void MemManager::askProcesses()
{

	std::cout << "Please enter the list of process sizes: ";
	//accept input
	//send input to parser
	//send each data to a process
}

void MemManager::displaySlots()
{
	std::cout << "Current slot map:\n";
	//display each slot, seperated by tab
	//display remaining size
}

void runManager()
{
	std::cout << "Taking up Process " << /*display name of process*/ endl;
	//send size of process to slot for testing
	//have it send boolean value if successful or not

}
