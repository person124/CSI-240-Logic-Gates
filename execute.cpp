#include "execute.h"

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
