#include "header.h"

int main()
{
    Layer layer;
    CommandType destination = SETUP;
    stringstream ss;

    do
    {
        utls::clear();

        displayGrid(layer);
        displayCommands();

        switch (destination)
        {
        case SETUP:
            break;

        case ENTRY:
            getInput(ss);
            destination = getCommandType(ss);
            break;

        case ADD:
            addComponent(layer, ss);
            break;

        case REMOVE:
            removeComponent(layer, ss);
            break;

        case UP:
            break;

        case DOWN:
            break;

        case RUN:
            break;

        default:
            destination = SETUP;;
        }

        destination = ENTRY;
    }
    while (destination != QUIT);

    return 0;
}