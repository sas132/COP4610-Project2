#include "processes.hpp"

Process::Process(char newName, int newSize)
{
	name = newName;
	size = newSize;
	nextProcess = nullptr;
}

Process::~Process()
{

}

int Process::getSize()
{
	return size;
}

char Process::getName()
{
	return name;
}

Process* Process::getNextProcess()
{
	return nextProcess;
}

void Process::setNextProcess(Process* next)
{
	nextProcess = next;
}
