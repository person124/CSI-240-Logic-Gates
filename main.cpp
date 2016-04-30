/* Filename:      main.cpp
 * File author:   Matthew James Harrison
 * Project Team:  Peter Belsley, Matthew Harrison, Calum Phillips
 * Class:         CSI-240-04
 * Assignment:    Final Project: Logic Gate
 * Date Assigned: April 18, 2016
 * Due Date:      April 29, 2016, at 11:59 pm
 *
 * Description:
 *   A program that simulates logic gates within a grid system.
 *
 * Certification of Authenticity:
 *   I certify that this is entirely my own work, except where I have given
 *   fully documented references to the work of others. I understand the
 *   definition and consequences of plagiarism and acknowledge that the assessor
 *   of this assignment may, for the purpose of assessing this assignment:
 *     -  Reproduce this assignment and provide a copy to another member of
 *        academic staff; and/or
 *     -  Communicate a copy of this assignment to a plagiarism checking
 *        service (which may then retain a copy of this assignment on its
 *        database for the purpose of future plagiarism checking)
 ******************************************************************************/

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
            load(layer, startingList, ss);
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