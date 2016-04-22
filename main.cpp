#include "header.h"

int main()
{
    Layer layer;
    Command command;

    int currentLayer = 0;
    int layerCount   = 0;
    int xWidth       = 0;
    int yWidth       = 0;

    do
    {
        utls::clear();

        displayGrid();
        displayCommands();

        switch (command.mType)
        {
        case NONE:
            command = getCommand(xWidth, yWidth);
            break;

        case ADD:
            addComponent(command);
            break;

        case REMOVE:
            removeComponent(command);
            break;

        case UP:
            break;

        case DOWN:
            break;

        case RUN:
            break;

        case CLEAR:
            break;

        default:
            command.mType = NONE;
        }

        command = Command();
    }
    while (command.mType != QUIT);

    return 0;
}