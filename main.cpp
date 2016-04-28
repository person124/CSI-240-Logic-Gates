#include "header.h"

int main()
{
    Layer layer;
    StartingList startingList;
    CommandType destination = ENTRY;
    stringstream ss;

    do
    {
        utls::clear();

        displayGrid(layer);
        displayCommands();

        switch (destination)
        {
        case ENTRY:
            getInput(ss);
            destination = getCommandType(ss);
            break;

        case ADD:
            addComponent(layer, startingList, ss);
            break;

        case REMOVE:
            removeComponent(layer, ss);
            break;

        case UP:
            layerUp(layer, ss);
            break;

        case DOWN:
            layerDown(layer, ss);
            break;

        case RUN:
            execute(layer, startingList);
            break;

        case SETUP:
            setup(layer, ss);
            break;

        default:
            destination = ENTRY;
        }

        ss.clear();
        destination = ENTRY;
    }
    while (destination != QUIT);

    return 0;
}