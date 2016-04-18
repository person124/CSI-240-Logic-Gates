#include "component.h"

Component::Component() {
	isCharged = disconected;

	inputEast = true;
	inputNorth = true;
	inputSouth = true;
	inputWest = true;

	outputEast = false;
	outputNorth = false;
	outputSouth = false;
	outputWest = false;

	location.xPos = 0;
	location.yPos = 0;
}

Component::~Component()
{
}

void Component::startOutputNorth()
{
	outputNorth = true;
	inputNorth = false;
}

void Component::startOutputSouth()
{
	outputSouth = true;
	inputSouth = false;
}

void Component::startOutputEast()
{
	outputEast = true;
	inputEast = false;
}

void Component::startOutputWest()
{
	outputWest = true;
	inputWest = false;
}

void Component::acceptInputNorth()
{
	inputNorth = true;
	outputNorth = false;
}

void Component::acceptInputSouth()
{
	inputSouth = true;
	outputSouth = false;
}

void Component::acceptInputEast()
{
	inputEast = true;
	outputEast = false;
}

void Component::acceptInputWest()
{
	inputWest = true;
	outputWest = true;
}

void Component::setLocation(int x, int y)
{
	location.xPos = x;
	location.yPos = y;
}

Charge Component::getCharge()
{
	return isCharged;
}

Charge Component::getOutputCharge()
{
	return isCharged;
}
