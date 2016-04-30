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
    for (int i = 0; i < list.getSize(); i++)
    {
        StartingPos* pos = list.get(i);
        Component* c = &layer.get(pos->mL)->get(pos->mX, pos->mY);
        c->setCharged(true);
        poke(layer, pos->mL, pos->mX, pos->mY, true);
    }
}

void invokeGate(Layer& layer, int l, int x, int y, bool charge, char dir)
{
    Grid* g = layer.get(l);

    bool chargeUp = g->get(x, y - 1).getCharge();
    bool chargeDown = g->get(x, y + 1).getCharge();

    Component* c = &g->get(x, y);
    bool gCharge = getGateOutput(c->getID(), chargeUp, chargeDown);
    c->setCharged(gCharge);
    pokeLoc(layer, l, x + 1, y, gCharge, 'l');
}

void invokeLight(Layer& layer, int l, int x, int y, bool charge)
{
    if (!charge && isAlone(layer, l, x, y))
        layer.get(l)->get(x, y).setCharged(false);
    else
        layer.get(l)->get(x, y).setCharged(charge);
}

void invokeNot(Layer& layer, int l, int x, int y, bool charge)
{
    layer.get(l)->get(x, y).setCharged(!charge);
    pokeLoc(layer, l, x + 1, y, !charge, 'l');
}

void invokeVert(Layer& layer, int l, int x, int y, bool charge)
{
    Component* c = &layer.get(l)->get(x, y);
    if (charge && c->getCharge())
        return;
    if (!charge)
    {
        if (isAlone(layer, l, x, y))
            return;
    }
    c->setCharged(charge);
    if (layer.get(l + 1) != NULL)
        pokeLoc(layer, l + 1, x, y, charge, 'v');
    if (layer.get(l - 1) != NULL)
        pokeLoc(layer, l - 1, x, y, charge, 'v');
}

void invokeWire(Layer& layer, int l, int x, int y, bool charge)
{
    Component* c = &layer.get(l)->get(x, y);
    if (charge && c->getCharge())
        return;
    if (!charge)
    {
        if (isAlone(layer, l, x, y))
            return;
    }
    c->setCharged(charge);
    poke(layer, l, x, y, charge);
}

bool isAlone(Layer& layer, int l, int x, int y)
{
    Grid* g = layer.get(l);
    return g->get(x + 1, y).getCharge() || g->get(x - 1, y).getCharge()
            || g->get(x, y + 1).getCharge() || g->get(x, y - 1).getCharge();
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
    Component* c = &layer.get(l)->get(x, y);
    if (c->getID() == "WIRE")
        invokeWire(layer, l, x, y, charge);
    else if (c->getID() == "LIGHT")
        invokeLight(layer, l, x, y, charge);
    else if (c->getID() == "VERT")
        invokeVert(layer, l, x, y, charge);
    else if (c->getID() == "NOT" && dir == 'l')
        invokeNot(layer, l, x, y, charge);
    else if ((dir == 'd' || dir == 'u') && isGate(c->getID()))
        invokeGate(layer, l, x, y, charge, dir);
}
