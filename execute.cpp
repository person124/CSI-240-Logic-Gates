#include "execute.h"

/* Purpose: To start the execution of the simulation of the logic gates.
 *     Pre: layer is the linked-list of the different layers, and list is
 *          the linked-list of all of the start points.
 *    Post: The charge values of all of the wires and gates and lights
 *          change to fit the simulation
 *  Author: Calum M. Phillips
 */
void execute(Layer& layer, StartingList& list)
{
    for (int i = 0; i < list.getCount(); i++)
    {
        StartingPos* pos = list.get(i);
        Component c = layer.get(pos->mL)->get(pos->mX, pos->mY);
        invokeStart(layer, pos, c, Charge::charged);
    }
}

void invokeStart(Layer& layer, StartingPos* pos, Component& c, Charge charge)
{
    c.setCharged(charge);
	poke(layer, pos->mL, pos->mX, pos->mY, charge);
}

void invokeLight(Layer& layer, int l, int x, int y, Charge charge)
{
	Component c = layer.get(l)->get(x, y);
	c.setCharged(charge);
}

void invokeNot(Layer& layer, int l, int x, int y, Charge charge)
{
	Component c = layer.get(l)->get(x, y);
	c.setCharged(charge == charged ? noCharge : charge);
	poke(layer, l, x + 1, y, c.getCharge());
}

void invokeWire(Layer& layer, int l, int x, int y, Charge charge)
{
	Component c = layer.get(l)->get(x, y);
	c.setCharged(charge);
	poke(layer, l, x, y, charge);
}

bool isGate(string id)
{
	return id == "AND" || id == "NAND" || id == "OR" || id == "NOR" || id == "XOR" || id == "XNOR";
}

void poke(Layer& layer, int l, int x, int y, Charge charge)
{
	pokeLoc(layer, l, x - 1, y, charge, 'r'); //Left
	pokeLoc(layer, l, x, y - 1, charge, 'd'); //Up
	pokeLoc(layer, l, x + 1, y, charge, 'l'); //Right
	pokeLoc(layer, l, x, y + 1, charge, 'u'); //Down
}

void pokeLoc(Layer& layer, int l, int x, int y, Charge charge, char dir)
{
	Component c = layer.get(l)->get(x, y);
	if (c.getID() == "NULL" || c.getID() == "POWER")
		return;
	else if (c.getID() == "WIRE" && !wireCheck(charge, c.getCharge()))
		invokeWire(layer, l, x, y, charge);
	else if (c.getID() == "LIGHT")
		invokeLight(layer, l, x, y, charge);
	else if (c.getID() == "NOT" && dir == 'l')
		invokeNot(layer, l, x, y, charge);
	else if (isGate(c.getID()))
		return;
}

bool wireCheck(Charge in, Charge out)
{
	if (in == out)
		return true;
	if (in == noCharge && out == charged)
		return true;
	return false;
}