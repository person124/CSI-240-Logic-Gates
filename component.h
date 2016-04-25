#pragma once
#include <string>

using namespace std;
enum Charge
{		
	charged, noCharge, disconected
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

	void setCharged(Charge);


	Charge getCharge();

	Charge getOutputCharge();

	string getID();
	
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
	string ID;
	Charge isCharged, inputCharge;
};
