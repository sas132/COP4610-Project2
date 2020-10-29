#ifndef SLOT
#define SLOT

class Slot
{
private:
	int baseLocation;
	int displacement;
	Slot* nextSlot;

public:
	Slot(int base);
	int getBaseLocation();
	int getDisplacement();
	Slot* getNextSlot();
	void setBaseLocation(int newBase);
	void setDisplacement(int newDisp);
	void setNextSlot(Slot* newSlot);
};

#endif
