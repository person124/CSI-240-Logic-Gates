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
        displayComponents();
        displayGrid(layer);
        displayCommands();

        /* Parse input */
        getInput(ss);
        destination = readCommandType(ss);

        switch (destination)
        {
        case ADD:
            addComponent(layer, startingList, ss);
            break;

        case REMOVE:
            removeComponent(layer, startingList, ss);
            break;

        case UP:
            changeLayer(layer, ss, UP);
            break;

        case DOWN:
            changeLayer(layer, ss, DOWN);
            break;

        case RUN:
            execute(layer, startingList);
            break;

        case RESIZE:
            resize(layer, startingList, ss);
            break;

        case QUIT:
            displayMessage(MSG_SHUTDOWN);
            break;

        default:
            destination = NONE;
        }
        ss.clear();
    }
    while (destination != QUIT);

    return 0;
}