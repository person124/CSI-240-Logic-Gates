#pragma once
#include <string>

using namespace std;



class Component
{
public:
	Component();
	~Component();
	Component(string);
	
	void setCharged(bool);

	bool getCharge();

	bool getOutputCharge();

	string getID();

	void setID();

	void operator=(const string &aString);

protected:
	string ID;
	bool isCharged;
};
