#include "header.h"

int main()
{
    // create linked list of dynamic arrays
    int layer = 0;
    int sizeX = 0;
    int sizeY = 0;

    Command command;

    do
    {
        utls::clear(); // Windows only

        displayGrid();
        displayCommands();

        switch (command.mType)
        {
        case NONE:
            command = getCommand();
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

        default:
            command.mType = NONE;
        }
        command = Command();
    }
    while (command.mType != QUIT);

    return 0;
}