#include "header.h"


/* Purpose:  To add a component according to user input
 *     Pre:  Current layer exists,
 *           stringstream with component type, x position, and y position
 *    Post:  Adds component of given type at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void addComponent(Layer &layer, StartingList &startingList, stringstream &ss)
{
    Component     component;

    int           currentLayer = 0;
    string        data         = "";
    ComponentType type         = EMPTY;
    int           xPos         = -1;
    int           xSize        = 0;
    int           yPos         = -1;
    int           ySize        = 0;

    currentLayer = layer.getCurrentLayer();

    type = getComponentType(ss);

    if (type == EMPTY)
    {
        return;
    }
    data.clear();

    /* Read x position */
    ss >> data;
    if (utls::isDigit(data))
    {
        xPos = stoi(data);
        xSize = layer.get(currentLayer)->getWidth();

        /* Validate x position */
        if (xPos < 0 || xPos > xSize)
        {
            return;
        }
    }
    else
    {
        return;
    }
    data.clear();

    /* Read y position */
    ss >> data;
    if (utls::isDigit(data))
    {
        yPos = stoi(data);
        ySize = layer.get(currentLayer)->getHeight();

        /* Validate y position */
        if (yPos < 0 || yPos > ySize)
        {
            return;
        }
    }
    else
    {
        return;
    }
    data.clear();

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }
    data.clear();

    component.setID(COMPONENT_NAME[static_cast<int>(type)]);

    layer.get(currentLayer)->set(xPos, yPos, component);

    if (type == POWER)
    {
        startingList.add(currentLayer, xPos, yPos);
    }
}


/* Purpose:  To display the current layer's grid on the screen
 *     Pre:  Current layer exists
 *    Post:  Displays grid on the screen
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void displayGrid(Layer &layer)
{
    Component     tmp;

    int           currentLayer = 0;
    string        id           = "";
    ComponentType type         = EMPTY;

    currentLayer = layer.getCurrentLayer();

    for (int i = 0; i < layer.get(currentLayer)->getHeight(); i++)
    {
        for (int j = 0; j < layer.get(currentLayer)->getWidth(); j++)
        {
            tmp = layer.get(currentLayer)->get(i, j);

            id = tmp.getID();

            type = getComponentType(id);

            /* */
            if (tmp.getCharge() == charged)
            {
                cout << COMPONENT_ON[static_cast<int>(type)];
            }
            else
            {
                cout << COMPONENT_OFF[static_cast<int>(type)];
            }
        }

        tmp = Component();
        id.clear();

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


/* Purpose:  To display a message on the screen and pause the program
 *     Pre:  Message type
 *    Post:  Dislays message text on teh screen and pauses the program
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void displayMessage(MESSAGE_TYPE code)
{
    cout << endl << MESSAGE_TEXT[static_cast<int>(code)] << endl;

    utls::pause();
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
    string      data = "";
    CommandType type  = ENTRY;

    ss >> data;
    for (int i = 0; i < COMMAND_SIZE; i++)
    {
        if (COMMAND_NAME[i] == data)
        {
            type = static_cast<CommandType>(i);
        }
    }
    data.clear();

    return type;
}


/* Purpose:  To read a component type from a string
 *     Pre:  String containing component type name
 *    Post:  Returns component type (EMPTY for invalid input)
 *  Author:  Matthew James Harrison
 ******************************************************************************/
ComponentType getComponentType(string id)
{
    ComponentType type = EMPTY;

    for (int i = 0; i < COMPONENT_SIZE; i++)
    {
        if (COMPONENT_NAME[i] == id)
        {
            type = static_cast<ComponentType>(i);
        }
    }

    return type;
}


/* Purpose:  To read a component type from the user's input stream
 *     Pre:  Stringstream containing user input
 *    Post:  Returns component type (EMPTY for invalid input)
 *  Author:  Matthew James Harrison
 ******************************************************************************/
ComponentType getComponentType(stringstream &ss)
{
    string        data = "";
    ComponentType type = EMPTY;

    ss >> data;

    for (int i = 0; i < COMPONENT_SIZE; i++)
    {
        if (COMPONENT_NAME[i] == data)
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

    ss >> data;

    if (data.empty())
    {
        amount = 1;
    }
    else if (utls::isDigit(data))
    {
        amount = stoi(data);

        if (amount < 1)
        {
            return;
        }
    }
    else
    {
        return;
    }
    data.clear();

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }
    data.clear();

    for (int i = 0; i < amount; i++)
    {
        ++layer;
    }
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
    if (data.empty())
    {
        amount = 1;
    }
    else if (utls::isDigit(data))
    {
        amount = stoi(data);

        if (amount < 1)
        {
            return;
        }
    }
    else
    {
        return;
    }
    data.clear();

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }
    data.clear();

    for (int i = 0; i < amount; i++)
    {
        --layer;
    }
}


/* Purpose:  To remove a component according to user input
 *     Pre:  Current layer exists,
 *           stringstream with x position and y position
 *    Post:  Removes component at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void removeComponent(Layer &layer, stringstream &ss)
{
    int    currentLayer = 0;
    string data         = "";
    int    xPos         = -1;
    int    xSize        = 0;
    int    yPos         = -1;
    int    ySize        = 0;

    currentLayer = layer.getCurrentLayer();

    /* Read x position */
    ss >> data;
    if (utls::isDigit(data))
    {
        xPos = stoi(data);
        xSize = layer.get(currentLayer)->getWidth();

        /* Validate x position */
        if (xPos < 0 || xPos > xSize)
        {
            return;
        }
    }
    else
    {
        return;
    }
    data.clear();

    /* Read y position */
    ss >> data;
    if (utls::isDigit(data))
    {
        yPos  = stoi(data);
        ySize = layer.get(currentLayer)->getHeight();

        /* Validate y position */
        if (yPos < 0 || yPos > ySize)
        {
            return;
        }
    }
    else
    {
        return;
    }
    data.clear();

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }
    data.clear();

    layer.get(currentLayer)->remove(xPos, yPos);
}


/* Purpose:  To create a new system according to user specifications
 *     Pre:  Current layer exists,
 *           stringstream with x width and y height
 *    Post:  Creates new system with given width and height
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void setup(Layer &layer, stringstream &ss)
{
    int    currentLayer = 0;
    string data         = "";
    int    xSize        = 0;
    int    ySize        = 0;

    currentLayer = layer.getCurrentLayer();

    /* Read x size */
    ss >> data;
    if (utls::isDigit(data))
    {
        xSize = stoi(data);
    }
    else
    {
        return;
    }
    data.clear();

    /* Read y size */
    ss >> data;
    if (utls::isDigit(data))
    {
        ySize = stoi(data);
    }
    else
    {
        return;
    }
    data.clear();

    /* Check for junk */
    ss >> data;
    if (!data.empty())
    {
        return;
    }
    data.clear();

    // Actually set the width and height
    layer.get(currentLayer)->resize(xSize, ySize);
}