#include "header.h"


/* Purpose:  To add a component according to user input
 *     Pre:  Current layer exists,
 *           stringstream with component type, x position, and y position
 *    Post:  Adds component of given type at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void addComponent(Layer &layer, stringstream &ss)
{
    Component     tmp;
    string        data = "";
    ComponentType component = EMPTY;
    int           xPos = -1;
    int           yPos = -1;

    /* Read component type */
    component = getComponentType(ss);
    if (component == EMPTY)
    {
        return;
    }

    /* Read x position */
    ss >> data;
    if (utls::isDigit(data))
    {
        xPos = stoi(data);

        /* Validate x position */
        if (xPos < 0 || xPos > layer.get(layer.getCurrentLayer())->getWidth())
        {
            return;
        }
    }
    else
    {
        return;
    }

    /* Read y position */
    ss >> data;
    if (utls::isDigit(data))
    {
        yPos = stoi(data);

        /* Validate y position */
        if (yPos < 0 || yPos > layer.get(layer.getCurrentLayer())->getHeight())
        {
            return;
        }
    }
    else
    {
        return;
    }

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }

    // Actually add the component
}


/* Purpose:  To display the current layer's grid on the screen
 *     Pre:  Current layer exists
 *    Post:  Displays grid on the screen
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void displayGrid(Layer &layer)
{
    Component tmp;

    for (int i = 0; i < layer.get(layer.getCurrentLayer())->getHeight(); i++)
    {
        for (int j = 0; j < layer.get(layer.getCurrentLayer())->getWidth(); j++)
        {
            tmp = layer.get(layer.getCurrentLayer())->get(i, j);

            if (tmp.getCharge() == charged)
            {
                //cout << COMPONENT_ON[static_cast<int>(tmp.getComponentID()];
            }
            else
            {
                //cout << COMPONENT_OFF[static_cast<int>(tmp.getComponentID()];
            }
        }
        cout << endl;
    }
    cout << endl;
}


/* Purpose:  To display a list of user commands on the screen
 *     Pre:  None
 *    Post:  Displays list of user commands on the screen
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void displayCommands()
{
    for (int i = 0; i < COMMAND_SIZE; i++)
    {
        cout << right << setw(15) << COMMAND_NAME[i];
    }
    cout << endl;
}


/* Purpose:  To display a list of component names on the screen
 *     Pre:  None
 *    Post:  List of component names displayed on the screen
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void displayComponents()
{
    for (int i = 0; i < COMPONENT_SIZE; i++)
    {
        cout << right << setw(15) << COMPONENT_NAME[i];
    }
    cout << endl;
}


/* Purpose:  To get a line of input from the user
 *     Pre:  Stringstream for storing input
 *    Post:  Stores user input in stringstream
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void getInput(stringstream &ss)
{
    string input = "";

    cout << "Enter command:  ";

    getline(cin, input);
    input = utls::toUpper(input);

    getline(ss, input);
}


/* Purpose:  To read a command type from the user's input
 *     Pre:  Stringstream containing user input
 *    Post:  Returns command type (ENTRY for invalid input)
 *  Author:  Matthew James Harrison
 ******************************************************************************/
CommandType getCommandType(stringstream &ss)
{
    CommandType type  = ENTRY;
    string      data  = "";

    ss >> data;

    for (int i = 0; i < COMMAND_SIZE; i++)
    {
        if (COMMAND_NAME[i] == data)
        {
            type = static_cast<CommandType>(i);
        }
    }
    return type;
}


/* Purpose:  To read a component type from the user's input
 *     Pre:  Stringstream containing user input
 *    Post:  Returns component type (EMPTY for invalid input)
 *  Author:  Matthew James Harrison
 ******************************************************************************/
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


/* Purpose:  To move the user up by a given number of layers
 *     Pre:  Current layer exists,
 *           stringstream with move amount
 *    Post:  Moves user up by a given number of layers
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void layerUp(Layer &layer, stringstream &ss)
{
    string data = "";
    int    amount = 0;

    /* Read amount */
    ss >> data;
    if (utls::isDigit(data))
    {
        amount = stoi(data);

        if (layer.getCurrentLayer() == layer.getCount())
        {
            return;
        }
    }
    else
    {
        return;
    }

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }

    // change layer here
}


/* Purpose:  To move the user up down a given number of layers
 *     Pre:  Current layer exists,
 *           stringstream with move amount
 *    Post:  Moves user down by a given number of layers
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void layerDown(Layer &layer, stringstream &ss)
{
    string data = "";
    int    amount = 0;

    /* Read amount */
    ss >> data;
    if (utls::isDigit(data))
    {
        amount = stoi(data);

        if (layer.getCurrentLayer() == 0)
        {
            return;
        }
    }
    else
    {
        return;
    }

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }

    // change layer here
}


/* Purpose:  To remove a component according to user input
 *     Pre:  Current layer exists,
 *           stringstream with x position and y position
 *    Post:  Removes component at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void removeComponent(Layer &layer, stringstream &ss)
{
    string data = "";
    int    xPos = -1;
    int    yPos = -1;

    /* Read x position */
    ss >> data;
    if (utls::isDigit(data))
    {
        xPos = stoi(data);

        /* Validate x position */
        if (xPos < 0 || xPos > layer.get(layer.getCurrentLayer())->getWidth())
        {
            return;
        }
    }
    else
    {
        return;
    }

    /* Read y position */
    ss >> data;
    if (utls::isDigit(data))
    {
        yPos = stoi(data);

        /* Validate y position */
        if (yPos < 0 || yPos > layer.get(layer.getCurrentLayer())->getHeight())
        {
            return;
        }
    }
    else
    {
        return;
    }

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }

    // Actually remove the component
}


/* Purpose:  To create a new system according to user specifications
 *     Pre:  Current layer exists,
 *           stringstream with x width and y height
 *    Post:  Creates new system with given width and height
 *  Author:  Matthew James Harrison
 ******************************************************************************/
CommandType setup(Layer &layer, stringstream &ss)
{
    return ENTRY;

    CommandType destination = NEW;
    string      data        = "";
    int         xSize       = 0;
    int         ySize       = 0;

    /* Read x size */
    ss >> data;
    if (utls::isDigit(data))
    {
        xSize = stoi(data);
    }
    else
    {
        return destination;
    }

    /* Read y size */
    ss >> data;
    if (utls::isDigit(data))
    {
        ySize = stoi(data);
    }
    else
    {
        return destination;
    }

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return destination;
    }

    // Actually set the width and height

    return destination;
}