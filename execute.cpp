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

}
