#include "header.h"

int main()
{
    Layer layer;

    Command command;

    do
    {
        utls::clear(); // Windows only
        // implement cross-platform solution for clearing terminal

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