#include "header.h"

int main()
{
    Layer layer;
    StartingList startingList;
    CommandType destination = NONE;
    stringstream ss;

    do
    {
        utls::clear();

        /* Display interface */
        displayGrid(layer);
        displayCommands();

        /* Parse input */
        getInput(ss);
        destination = getCommandType(ss);

        switch (destination)
        {
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

        case QUIT:
            break;

        default:
            destination = QUIT;
        }
        ss.clear();
    }
    while (destination != QUIT);

    return 0;
}