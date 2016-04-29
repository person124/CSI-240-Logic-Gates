#include "header.h"

/* Purpose:  Program main loop
 *  Author:  Matthew James Harrison
 ******************************************************************************/
int main()
{
    Layer layer;
    StartingList startingList;
    CommandType destination = NONE;
    stringstream ss;

    do
    {
        utls::clear();
        ss.clear();

        /* Display interface */
        displayComponents();
        displayGrid(layer);
        displayCommands();

        /* Get input and parse command type */
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
            run(layer, startingList, ss);
            break;

        case RESIZE:
            resize(layer, startingList, ss);
            break;

        case CLEAR:
            clear(layer, startingList, ss);
            break;

        case SAVE:
            save(layer, ss);
            break;

        case LOAD:
            load(layer, ss);
            break;

        case QUIT:
            displayMessage(MSG_SHUTDOWN);
            break;

        default:
            displayMessage(MSG_INV_COMMAND);
            destination = NONE;
        }
    }
    while (destination != QUIT);

    return 0;
}