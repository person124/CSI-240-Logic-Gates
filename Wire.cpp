#include "Wire.h"

Wire::Wire()
{
	inputNorth = true;
	inputSouth = true;
	inputEast = true;
	inputWest = true;

	outputNorth = true;
	outputSouth = true;
	outputEast = true;
	outputWest = true;
	ID = wire;
}

Wire::~Wire()
{

}