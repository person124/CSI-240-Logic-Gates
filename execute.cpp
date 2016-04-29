#include "execute.h"

/* Purpose: To start the execution of the simulation of the logic gates.
 *     Pre: layer is the linked-list of the different layers, list is
 *          the linked-list of all of the start points, and charge
 *          is the charge to set the starts too.
 *    Post: The charge values of all of the wires and gates and lights
 *          change to fit the simulation
 *  Author: Calum M. Phillips
 */
void execute(Layer& layer, StartingList& list, bool charge)
{
    for (int i = 0; i < list.getCount(); i++)
    {
        StartingPos* pos = list.get(i);
        Component c = layer.get(pos->mL)->get(pos->mX, pos->mY);
        invokeStart(layer, pos, c, charge);
    }
}

void invokeGate(Layer& layer, int l, int x, int y, bool charge, char dir)
{
    Grid* g = layer.get(l);
    string id = g->get(x, y).getID();

    bool chargeUp = g->get(x, y - 1).getCharge();
    bool chargeDown = g->get(x, y + 1).getCharge();

    bool gCharge = false; // = SomeChargeFunc(id, chargeUp, chargeDown);
    if (gCharge != g->get(x, y).getCharge())
    {
        g->get(x, y).setCharged(gCharge);
        pokeLoc(layer, l, x + 1, y, gCharge, 'r');
    }
}

void invokeLight(Layer& layer, int l, int x, int y, bool charge)
{
    Component c = layer.get(l)->get(x, y);
    c.setCharged(charge);
}

void invokeNot(Layer& layer, int l, int x, int y, bool charge)
{
    Component c = layer.get(l)->get(x, y);
    c.setCharged(!charge);
    pokeLoc(layer, l, x + 1, y, c.getCharge(), 'l');
}

void invokeStart(Layer& layer, StartingPos* pos, Component& c, bool charge)
{
    c.setCharged(charge);
    poke(layer, pos->mL, pos->mX, pos->mY, charge);
}

void invokeWire(Layer& layer, int l, int x, int y, bool charge)
{
    Component c = layer.get(l)->get(x, y);
    c.setCharged(charge);
    poke(layer, l, x, y, charge);
}

bool isGate(string id)
{
    return id == "AND" || id == "NAND" || id == "OR" || id == "NOR" || id == "XOR"
            || id == "XNOR";
}

void poke(Layer& layer, int l, int x, int y, bool charge)
{
    pokeLoc(layer, l, x - 1, y, charge, 'r'); //Left
    pokeLoc(layer, l, x, y - 1, charge, 'd'); //Up
    pokeLoc(layer, l, x + 1, y, charge, 'l'); //Right
    pokeLoc(layer, l, x, y + 1, charge, 'u'); //Down
}

void pokeLoc(Layer& layer, int l, int x, int y, bool charge, char dir)
{
    Component c = layer.get(l)->get(x, y);
    if (c.getID() == "WIRE" && !wireCheck(charge, c.getCharge()))
        invokeWire(layer, l, x, y, charge);
    else if (c.getID() == "LIGHT")
        invokeLight(layer, l, x, y, charge);
    else if (c.getID() == "NOT" && dir == 'l')
        invokeNot(layer, l, x, y, charge);
    else if ((dir == 'd' || dir == 'u') && isGate(c.getID()))
        invokeGate(layer, l, x, y, charge, dir);
}

bool wireCheck(bool in, bool out)
{
    if (in == out)
        return true;
    if (!in && out)
        return true;
    return false;
}
