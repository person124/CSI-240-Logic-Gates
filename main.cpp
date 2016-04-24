#include "header.h"

int main()
{
    Layer layer;
    StartingList startingList;
    CommandType destination = NEW;
    stringstream ss;

    do
    {
        utls::clear();

        displayGrid(layer);
        displayCommands();

        switch (destination)
        {
        case NEW:
            getInput(ss);
            destination = setup(layer, ss);
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
            layerUp(layer, ss);
            break;

        case DOWN:
            layerDown(layer, ss);
            break;

        case RUN:
            execute(layer, startingList);
            break;

        default:
            destination = NEW;
        }

        ss.clear();
        destination = ENTRY;
    }
    while (destination != QUIT);

    return 0;
}