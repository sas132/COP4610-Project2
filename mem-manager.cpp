#include "mem-manager.hpp"
#include "slots.hpp"
#include <iostream>
#include <string>

MemManager::MemManager()
{
	firstSlot = nullptr;
	std::cout << "This memory manager program allocates slots to processes using the First Fit Dynamic Relocation.\n\n";
	askSlots();
}

void MemManager::askSlots()
{
	std::string str;
	std::cout << "Please enter the base locations of the slots: ";
	std::getline(std::cin, str);
	int current = 0;
	Slot* lastSlot = nullptr;
	for(int i = 0; i < str.size(); i++)
	{
		if(str.at(i) != ' ' || isalpha(str.at(i)) == false)
		{
			current = (current * 10) + ((int)str.at(i) - 48);
		}
		else if(isalpha(str.at(i) == false))
		{
			if(firstSlot == nullptr)
			{
				firstSlot->setBaseLocation(current);
				lastSlot = firstSlot;
			}
			else
			{
				Slot* temp = new Slot(current);
				lastSlot->setNextSlot(temp);
				lastSlot = temp;
			}
			current = 0;
		}
		else
		{
			std::cerr << "ERROR: Invalid Input.\n";
		}
	}
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
	std::cout << "Taking up Process " << /*display name of process*/ std::endl;
	//send size of process to slot for testing
	//have it send boolean value if successful or not

}
