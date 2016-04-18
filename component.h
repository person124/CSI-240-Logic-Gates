#pragma once
#include <string>

using namespace std;
enum Charge
{		
	charged, noCharge, disconected
};

enum ComponentID
{
	wire, verticalWire, light, start
};

struct position
{
	int xPos, yPos;
};

class Component
{
public:
	Component();
	~Component();

	void startOutputNorth();
	void startOutputSouth();
	void startOutputEast();
	void startOutputWest();

	void acceptInputNorth();
	void acceptInputSouth();
	void acceptInputEast();
	void acceptInputWest();

	void setLocation(int x, int y);

	Charge getCharge();

	Charge getOutputCharge();
	
protected:
	bool
		inputNorth,
		inputSouth,
		inputEast,
		inputWest,

		outputNorth,
		outputSouth,
		outputEast,
		outputWest;
	
	
	position location;
	ComponentID ID;
	Charge isCharged;
};
