#include "mem-manager.hpp"
#include "slots.hpp"
#include "processes.hpp"
#include <iostream>
#include <string>

MemManager::MemManager()
{
	firstSlot = nullptr;
	numSlots = 0;
	std::cout << "This memory manager program allocates slots to processes using the First Fit Dynamic Relocation.\n\n";
	askSlots();
}

void MemManager::askSlots()
{
	std::string str;
	std::cout << "Please enter the base locations of the slots: ";
	std::getline(std::cin, str);
	int current = 0;
	Slot* lastSlot = new Slot(-1);
	
	for(int i = 0; i < str.size(); i++)
	{
		if(isdigit(str.at(i)))
		{
			current = (current * 10) + ((int)str.at(i) - 48);
		}
		else if(str.at(i) == ' ')
		{
			if(firstSlot == nullptr)
			{
				lastSlot->setBaseLocation(current);
				firstSlot = lastSlot;
			}
			else
			{
				Slot* temp = new Slot(current);
				lastSlot->setNextSlot(temp);
				lastSlot = temp;
			}
			current = 0;
			numSlots++;
		}
		else
		{
			std::cerr << "ERROR: Invalid Input.\n";
		}
	}

	Slot* temp = new Slot(current);
	lastSlot->setNextSlot(temp);
	numSlots++;

	askDisplacement();
}

void MemManager::askDisplacement()
{
	std::string str;
	std::cout << "\nPlease enter the displacements for the base locations previously entered by you: ";
	std::getline(std::cin, str);
	int current = 0;
	Slot* currentSlot = firstSlot;
	
	for(int i = 0; i < str.size(); i++)
	{
		if(isdigit(str.at(i)))
		{
			current = (current * 10) + ((int)str.at(i) - 48);
		}
		else if(str.at(i) == ' ')
		{
			if(currentSlot != nullptr)
			{
				currentSlot->setDisplacement(current);
				currentSlot = currentSlot->getNextSlot();
				current = 0;
			}
			else
			{
				std::cerr << "ERROR: Number of Displacements more than Slots.\n";
			}
		}
		else
		{
			std::cerr << "ERROR: Invalid Input.\n";
		}
	}

	currentSlot->setDisplacement(current);

	displaySlots();
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
	Slot* temp = firstSlot;

	for(int i = 0; i < numSlots; i++)
	{
		std::cout << temp->getBaseLocation() << "\t";
		temp = temp->getNextSlot();
	}

	std::cout << "\n";
	temp = firstSlot;

	for(int j = 0; j < numSlots; j++)
	{
		std::cout << temp->getDisplacement() << "\t";
		temp = temp->getNextSlot();
	}
	std::cout << "\n";
}

void runManager()
{
	std::cout << "Taking up Process " << /*display name of process*/ std::endl;
	//send size of process to slot for testing
	//have it send boolean value if successful or not

}
