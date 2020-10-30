#include "mem-manager.hpp"
#include "slots.hpp"
#include "processes.hpp"
#include <iostream>
#include <string>

MemManager::MemManager()
{
	firstSlot = nullptr;
	firstProcess = nullptr;
	numSlots = 0;
	numProcesses = 0;
	std::cout << "This memory manager program allocates slots to processes using the First Fit Dynamic Relocation.\n\n";
	askSlots();
	askProcesses();
	runManager();
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
	std::cout << "\n";

	displaySlots();
}

void MemManager::askProcesses()
{
	std::string str;
	std::cout << "Please enter the list of process sizes: ";
	std::getline(std::cin, str);
	int current = 0;
	Process* currentProcess;

	for(int i = 0; i < str.size(); i++)
	{
		if(isdigit(str.at(i)))
		{
			current = (current * 10) + ((int)str.at(i) - 48);
		}

		else if(str.at(i) == ' ')
		{
			int name = numProcesses + 65;
			Process* tempProcess = new Process((char)name, current);
			if(firstProcess == nullptr)
			{
				firstProcess = tempProcess;
				currentProcess = firstProcess;
			}
			else
			{
				currentProcess->setNextProcess(tempProcess);
				currentProcess = tempProcess;
			}
			numProcesses++;
			current = 0;
		}
		else
		{
			std::cerr << "ERROR: Invalid Input.\n";
		}
	}

	Process* tempProcess = new Process((char)(numProcesses + 65), current);
	currentProcess->setNextProcess(tempProcess);
	numProcesses++;

	currentProcess = firstProcess;

	std::cout << "\nProcesses:\n";
	for(int i = 0; i < numProcesses; i++)
	{
		std::cout << currentProcess->getName() << "\t";
		currentProcess = currentProcess->getNextProcess();
	}

	currentProcess = firstProcess;
	std::cout << "\n";

	for(int j = 0; j < numProcesses; j++)
	{
		std::cout << currentProcess->getSize() << "\t";
		currentProcess = currentProcess->getNextProcess();
	}

	std::cout << "\n";
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

void MemManager::runManager()
{
	Process* currentProcess = firstProcess;
	std::cout << "\n";

	for(int i = 0; i < numProcesses; i++)
	{
		std::cout << "Taking up Process " << currentProcess->getName() << "\n";
		Slot* fitting = testSlots(currentProcess->getSize());
		if(fitting != nullptr)
		{
			std::cout << "Slot assignment successful. " << currentProcess->getName() <<
				" - Base location " << fitting->getBaseLocation() << "\n";
			fitting->setDisplacement(fitting->getDisplacement() - currentProcess->getSize());
			fitting->setBaseLocation(fitting->getBaseLocation() + currentProcess->getSize());

			if(fitting->getDisplacement() == 0)
			{
				deleteSlot(fitting);
			}

			displaySlots();
			Process* temp = currentProcess->getNextProcess();
			currentProcess->setNextProcess(nullptr);
			delete currentProcess;
			currentProcess = temp;
			std::cout << "\n";
		}
		else
		{
			std::cout << "Slot assignment NOT successful for " << currentProcess->getName() << ".\n\n";
			std::cout << "Allocation cannot proceed further\n\n";
			std::cout << "Ending the program now...\n";

			i = 1000; //big number to exit for loop

			for(int k = 0; k < numProcesses - i; k++)
			{
				Process* temp = currentProcess->getNextProcess();
				currentProcess->setNextProcess(nullptr);
				delete currentProcess;
				currentProcess = temp;
			}
		}
	}
	for(int j = 0; j < numSlots; j++)
	{
		deleteSlot(firstSlot);
	}
}

Slot* MemManager::testSlots(int size)
{
	Slot* currentSlot = firstSlot;
	for(int i = 0; i < numSlots; i++)
	{
		if(size <= currentSlot->getDisplacement())
		{
			return currentSlot;
		}
		else
		{
			currentSlot = currentSlot->getNextSlot();
		}
	}
	return nullptr;
}

void MemManager::deleteSlot(Slot* slot)
{
	if(slot != firstSlot)
	{
		Slot* temp = firstSlot;

		for(int i = 0; i < numSlots; i++)
		{
			if(slot == temp->getNextSlot())
			{
				i = 1000; //unreasonably high number to break out of for loop.
			}
			else if(temp != nullptr)
			{
				temp = temp->getNextSlot();
			}
		}

		temp->setNextSlot(slot->getNextSlot());
		slot->setNextSlot(nullptr);
		delete slot;
	}
	else
	{
		firstSlot = slot->getNextSlot();
		slot->setNextSlot(nullptr);
		delete slot;
	}

	numSlots--;
}
