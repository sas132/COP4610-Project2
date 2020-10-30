#include "slots.hpp"

Slot::Slot(int base)
{
	baseLocation = base;
	displacement = -1;
	nextSlot = nullptr;
}

Slot::~Slot()
{

}

int Slot::getBaseLocation()
{
	return baseLocation;
}

int Slot::getDisplacement()
{
	return displacement;
}

Slot* Slot::getNextSlot()
{
	return nextSlot;
}

void Slot::setBaseLocation(int newBase)
{
	baseLocation = newBase;
}

void Slot::setDisplacement(int newDisp)
{
	displacement = newDisp;
}

void Slot::setNextSlot(Slot* newSlot)
{
	nextSlot = newSlot;
}
