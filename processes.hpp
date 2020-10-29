#ifndef PROCESSES
#define PROCESSES

class Process
{
private:
	int size;
	char name;
	Process* nextProcess;

public:
	Process(char newName, int newSize);
	int getSize();
	char getName();
	Process* getNextProcess();
	void setNextProcess(Process* next);
};

#endif
