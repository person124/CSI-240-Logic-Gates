#include "execute.h"

void execute(Layer& layer, StartingList& list)
{
    for (int i = 0; i < list.getCount(); i++)
    {
        StartingPos* pos = list.get(i);
        Component c = layer.get(pos->mL)->get(pos->mX, pos->mY);
        invoke(c, Charge::charged);
    }
}

void invoke(Component& c, Charge charge)
{
    c.setCharged(charge);
}
