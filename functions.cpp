#include "header.h"

void addComponent(const Command command)
{
    
}


void displayGrid()
{
    for (int i = 0; i < 0; i++)
    {
        for (int j = 0; j < 0; j++)
        {
            // display current grid tile
        }
        cout << endl;
    }
    cout << endl;
}

void displayCommands()
{
    for (int i = 0; i < COMMAND_SIZE; i++)
    {
        cout << right << setw(15) << COMMAND_NAME[i];
    }
    cout << endl;
}

void displayComponents()
{
    for (int i = 0; i < COMPONENT_SIZE; i++)
    {
        cout << COMPONENT_NAME[i] << "\t";
    }
    cout << endl;
}

Command getCommand()
{
    Command      tmp;
    string       input = "";
    stringstream ss;

    /* Get command input from user */
    cout << "Enter command:  ";
    getline(cin, input);
    input = utls::toUpper(input);
    getline(ss, input);

    /* Read command type */
    tmp.mType = getCommandType(ss);

    switch (tmp.mType)
    {
    case ADD:
        /* Get component type, x position, and y position */
        tmp.mComponent = getComponentType(ss);
        tmp.mParameter1 = getPosition(ss, 0); // pass x width limit
        tmp.mParameter2 = getPosition(ss, 0); // pass y height limit

        break;

    case REMOVE:
        /* Get x position and y position */
        tmp.mParameter1 = getPosition(ss, 0); // pass x width limit
        tmp.mParameter2 = getPosition(ss, 0); // pass y height limit

        break;

    case UP:
        /* Get up amount */
        tmp.mParameter1 = getPosition(ss, 0); // pass LL upwards limit

        /* Default is 1 */
        if (tmp.mParameter1 == -1)
        {
            tmp.mParameter1 = 1;
        }

        break;

    case DOWN:
        /* Get down amount */
        tmp.mParameter1 = getPosition(ss, 0); // pass LL downwards limit

        /* Default is 1 */
        if (tmp.mParameter1 == -1)
        {
            tmp.mParameter1 = 1;
        }

        break;
    }
}

CommandType getCommandType(stringstream &ss)
{
    CommandType type  = NONE;
    string      input = "";

    ss >> input;

    for (int i = 0; i < COMMAND_SIZE; i++)
    {
        if (COMMAND_NAME[i] == input)
        {
            type = static_cast<CommandType>(i);
        }
    }
    return type;
}

ComponentType getComponentType(stringstream &ss)
{
    ComponentType type  = EMPTY;
    string        input = "";

    ss >> input;

    for (int i = 0; i < COMPONENT_SIZE; i++)
    {
        if (COMPONENT_NAME[i] == input)
        {
            type = static_cast<ComponentType>(i);
        }
    }
    return type;
}

int getPosition(stringstream &ss, const int bound)
{
    int    position = -1;
    string input    = "";

    input = utls::getInput();

    if (utls::isDigit(input))
    {
        if (stoi(input) >= 0 && position <= bound)
        {
            position = stoi(input);
        }
    }
    return position;
}

void layerUp(const Command command, const int &layer)
{
    // validate parameter
}

void layerDown(const Command command, const int &layer)
{
    // validate parameter
}

void removeComponent(const Command command)
{
    // check that command parameters are valid
}