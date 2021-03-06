/* Filename:      functions.cpp
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

/* Purpose:  To add a component according to user input
 *     Pre:  Current layer exists,
 *           stringstream with component type, x position, and y position
 *    Post:  Adds component of given type at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void addComponent(Layer &layer, StartingList &startingList, stringstream &ss)
{
    string        data         = "";
    ComponentType type         = EMPTY;
    int           xPos         = -1;
    int           yPos         = -1;

    /* Get command data */
    type = readComponentType(ss);
    xPos = readNumber(ss);
    yPos = readNumber(ss);

    /* If no junk data */
    if (!hasJunk(ss))
    {
        /* If type and position are valid */
        if (isPosition(layer, xPos, yPos) && type != EMPTY)
        {
            addComponent(layer, startingList, type, xPos, yPos);
        }
        else
        {
            displayMessage(MSG_INV_ADD);
        }
    }
}


/* Purpose:  To add a component of given type at given x and y position
 *     Pre:  Current layer exists,
 *           List of starting position,
 *           Component type
 *           Integer x and y positions
 *    Post:  Adds component of given type at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void addComponent(Layer &layer, StartingList &startingList, const ComponentType type, const int xPos, const int yPos)
{
    Component component;
    int       currentLayer = 0;
    Component tmp;

    currentLayer = layer.getCurrentLayer();
    tmp          = layer.get(currentLayer)->get(xPos, yPos);

    /* If the target position has a power component */
    if (tmp.getID() == COMPONENT_NAME[static_cast<int>(POWER)])
    {
        startingList.remove(currentLayer, xPos, yPos);
    }

    /* Add the component */
    component = Component(COMPONENT_NAME[static_cast<int>(type)]);
    layer.get(currentLayer)->set(xPos, yPos, component);

    /* If adding a power component */
    if (type == POWER)
    {
        startingList.add(currentLayer, xPos, yPos);
    }
}


/* Purpose:  To move the user up or down by a given number of layers
 *     Pre:  Current layer exists,
 *           stringstream with move amount
 *    Post:  Moves user up or down by a given number of layers
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void changeLayer(Layer &layer, stringstream &ss, CommandType direction)
{
    int    amount = 0;
    string data = "";

    /* Read command data */
    amount = readNumber(ss);

    /* If no junk data */
    if (!hasJunk(ss))
    {
        /* If not negative amount */
        if (amount >= 0)
        {
            /* Change given amount of layers */
            for (int i = 0; i < amount; i++)
            {
                if (direction == UP)
                {
                    ++layer;
                }
                else if (direction == DOWN)
                {
                    --layer;
                }
            }
        }
        else
        {
            displayMessage(MSG_INV_LAYER);
        }
    }
    else
    {
        displayMessage(MSG_INV_LAYER);
    }
}


/* Purpose:  To clear all components from the current layer
 *     Pre:  Current layer exists
 *           List of starting positions
 *           Stringstream from user input
 *    Post:  Displays grid on the screen
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void clear(Layer &layer, StartingList &startingList, stringstream &ss)
{
    int currentLayer = 0;
    int height = 0;
    int width = 0;

    currentLayer = layer.getCurrentLayer();
    height       = layer.get(currentLayer)->getHeight();
    width        = layer.get(currentLayer)->getWidth();

    /* If no junk data */
    if (!hasJunk(ss))
    {
        /* Traverse each row */
        for (int i = 0; i < height; i++)
        {
            /* Traverse each column of current row */
            for (int j = 0; j < width; j++)
            {
                removeComponent(layer, startingList, j, i);
            }
        }
    }
    else
    {
        displayMessage(MSG_INV_COMMAND);
    }
}


/* Purpose:  To display the current layer's grid on the screen
 *     Pre:  Current layer exists
 *    Post:  Displays grid on the screen
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void displayGrid(Layer &layer)
{
    int           currentLayer = 0;
    int           height       = 0;
    string        id           = "";
    Component     tmp;
    ComponentType type         = EMPTY;
    int           width        = 0;

    currentLayer = layer.getCurrentLayer();
    height       = layer.get(currentLayer)->getHeight();
    width        = layer.get(currentLayer)->getWidth();

    /* Display top guide */
    cout << "     ";
    for (int i = 0; i < width; i++)
    {
        if (i < 10)
        {
            cout << "  " << i << "  ";
        }
        else if (i < 100)
        {
            cout << "  " << i << " ";
        }
        else if (i < 1000)
        {
            cout << " " << i << " ";
        }
        else
        {
            cout << "  " << "?" << "  ";
        }
    }
    cout << endl << endl << endl;

    /* Traverse each row */
    for (int i = 0; i < height; i++)
    {
        /* Display left guide */
        cout << "  " << i << "  ";

        /* Traverse each column of current row */
        for (int j = 0; j < width; j++)
        {
            /* Get current component data */
            tmp  = layer.get(currentLayer)->get(j, i);
            id   = tmp.getID();
            type = readComponentType(id);
    
            /* Display on or off graphic */
            if (tmp.getCharge())
            {
                cout << COMPONENT_ON[static_cast<int>(type)];
            }
            else
            {
                cout << COMPONENT_OFF[static_cast<int>(type)];
            }
        }
        /* Display right guide */
        cout << "  " << i << "  " << endl << endl;

        /* Reset component data */
        tmp = Component();
        id.clear();

        cout << endl;
    }

    /* Display bottom guide */
    cout << "     ";
    for (int i = 0; i < width; i++)
    {
        if (i < 10)
        {
            cout << "  " << i << "  ";
        }
        else if (i < 100)
        {
            cout << "  " << i << " ";
        }
        else if (i < 1000)
        {
            cout << " " << i << " ";
        }
        else
        {
            cout << "  " << "?" << "  ";
        }
    }
    cout << endl << endl;
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
        cout << right << setw(10) << COMMAND_NAME[i];
    }
    cout << endl << endl;
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
        cout << right << setw(10) << COMPONENT_NAME[i];
    }
    cout << endl << endl;
}


/* Purpose:  To display a message on the screen and pause the program
 *     Pre:  Message type
 *    Post:  Dislays message text on teh screen and pauses the program
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void displayMessage(MESSAGE_TYPE code)
{
    cout << endl << MESSAGE_TEXT[static_cast<int>(code)] << endl;

    cout << "Press return to continue . . . ";

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

    ss << input;
}


/* Purpose:  To check if stringstream contains data
 *     Pre:  stringstream
 *    Post:  Returns true if stringstream contains data, or else returns false
 *  Author:  Matthew James Harrison
 ******************************************************************************/
bool hasJunk(stringstream &ss)
{
    string data   = "";
    bool   isJunk = false;

    ss >> data;

    if (!data.empty())
    {
        isJunk = true;
    }

    return isJunk;
}


/* Purpose:  To check if an x and y position exists on current layer
 *     Pre:  Current layer exists,
 *           x and y integers
 *    Post:  Returns true if x and y position exists on current layer
 *  Author:  Matthew James Harrison
 ******************************************************************************/
bool isPosition(Layer &layer, const int xPos, const int yPos)
{
    int  currentLayer = 0;
    bool isPosition   = true;
    int  xWidth       = 0;
    int  yHeight      = 0;

    currentLayer = layer.getCurrentLayer();
    xWidth       = layer.get(currentLayer)->getWidth();
    yHeight      = layer.get(currentLayer)->getHeight();

    if (xPos < 0 || xPos > xWidth)
    {
        isPosition = false;
    }
    else if (yPos < 0 || yPos > yHeight)
    {
        isPosition = false;
    }

    return isPosition;
}


/* Purpose:  To load all layers from a file at given path
 *     Pre:  Current layer exists,
 *           Stringstream containing file path
 *    Post:  All layers loaded from file
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void load(Layer &layer, StartingList &startinglist, stringstream &ss)
{
    string path = "";

    ss >> path;

    if (!path.empty())
    {
        if (!hasJunk(ss))
        {
            loadFromFile(path, layer, startinglist);
            displayMessage(MSG_LOAD);
        }
        else
        {
            displayMessage(MSG_INV_LOAD);
        }
    }
    else
    {
        displayMessage(MSG_INV_LOAD);
    }
}


/* Purpose:  To read a command type from the user's input
 *     Pre:  Stringstream containing user input
 *    Post:  Returns command type (ENTRY for invalid input)
 *  Author:  Matthew James Harrison
 ******************************************************************************/
CommandType readCommandType(stringstream &ss)
{
    string      data = "";
    CommandType type  = NONE;

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


/* Purpose:  To read a component type from a string
 *     Pre:  String containing component type name
 *    Post:  Returns component type (EMPTY for invalid input)
 *  Author:  Matthew James Harrison
 ******************************************************************************/
ComponentType readComponentType(string id)
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
ComponentType readComponentType(stringstream &ss)
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


/* Purpose:  To read an integer from the user's input stream
 *     Pre:  Stringstream containing user input
 *    Post:  Returns integer (-1 for invalid input)
 *  Author:  Matthew James Harrison
 ******************************************************************************/
int readNumber(stringstream&ss)
{
    string data   = "";
    int    number = -1;

    ss >> data;

    if (utls::isDigit(data))
    {
        number = stoi(data);
    }

    return number;
}


/* Purpose:  To remove a component according to user input
 *     Pre:  Current layer exists,
 *           stringstream with x position and y position
 *    Post:  Removes component at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void removeComponent(Layer &layer, StartingList &startingList, stringstream &ss)
{
    string    data         = "";
    int       xPos         = -1;
    int       yPos         = -1;

    /* Get command data */
    xPos = readNumber(ss);
    yPos = readNumber(ss);

    /* If no junk data */
    if (!hasJunk(ss))
    {
        /* If type and position are valid */
        if (isPosition(layer, xPos, yPos))
        {
            removeComponent(layer, startingList, xPos, yPos);
        }
        else
        {
            displayMessage(MSG_INV_REMOVE);
        }
    }
    else
    {
        displayMessage(MSG_INV_REMOVE);
    }
}


/* Purpose:  To remove a component from a given x and y position
 *     Pre:  Current layer exists,
 *           Starting list,
 *           Integer x and y coordinates
 *    Post:  Removes component at given position
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void removeComponent(Layer &layer, StartingList &startingList, const int xPos, const int yPos)
{
    int       currentLayer = 0;
    string    id           = "";
    Component tmp;

    currentLayer = layer.getCurrentLayer();
    tmp          = layer.get(currentLayer)->get(xPos, yPos);
    id           = tmp.getID();

    layer.get(currentLayer)->remove(xPos, yPos);

    if (id == COMPONENT_NAME[static_cast<int>(POWER)])
    {
        startingList.remove(currentLayer, xPos, yPos);
    }
}


/* Purpose:  To create a new system according to user specifications
 *     Pre:  Current layer exists,
 *           stringstream with x width and y height
 *    Post:  Creates new system with given width and height
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void resize(Layer &layer, StartingList &startingList, stringstream &ss)
{
    int    currentLayer = 0;
    int    xSizeNew     = 0;
    int    ySizeNew     = 0;

    currentLayer = layer.getCurrentLayer();

    /* Read command data */
    xSizeNew = readNumber(ss);
    ySizeNew = readNumber(ss);

    /* If no junk data */
    if (!hasJunk(ss))
    {
        /* If valid grid size */
        if (xSizeNew > 0 && ySizeNew > 0
            && xSizeNew <= GRID_MAX && ySizeNew <= GRID_MAX)
        {
            for (int i = 0; i < startingList.getSize(); i++)
            {
                StartingPos* pos = startingList.get(i);

                if (pos->mL == currentLayer)
                {
                    if (pos->mX >= xSizeNew || pos->mY >= ySizeNew)
                    {
                        startingList.remove(currentLayer, pos->mX, pos->mY);
                    }
                }
            }

            layer.get(currentLayer)->resize(xSizeNew, ySizeNew);
        }
        else
        {
            displayMessage(MSG_INV_RESIZE);
        }
    }
    else
    {
        displayMessage(MSG_INV_RESIZE);
    }
}


/* Purpose:  To execute the grid and display current layer
 *     Pre:  Current layer exists,
 *           Starting list exists,
 *           stringstream with user input
 *    Post:  Executes the grid and displays current layer
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void run(Layer &layer, StartingList &startingList, stringstream &ss)
{
    /* If no junk data */
    if (!hasJunk(ss))
    {
        /* Save file */
        saveToFile(DATA_PATH, layer);

        /* Execute */
        execute(layer, startingList);

        /* Display */
        utls::clear();
        displayGrid(layer);
        displayMessage(MSG_EXECUTE);

        /* Revert by loading file */
        loadFromFile(DATA_PATH, layer, startingList);
    }
    else
    {
        displayMessage(MSG_INV_COMMAND);
    }
}


/* Purpose:  To save all layers to a file at given path
 *     Pre:  Current layer exists,
 *           Stringstream containing file path
 *    Post:  All layers saved to file
 *  Author:  Matthew James Harrison
 ******************************************************************************/
void save(Layer &layer, stringstream &ss)
{
    string path = "";

    ss >> path;

    if (!path.empty())
    {
        if (!hasJunk(ss))
        {
            saveToFile(path, layer);
            displayMessage(MSG_SAVE);
        }
        else
        {
            displayMessage(MSG_INV_SAVE);
        }
    }
    else
    {
        displayMessage(MSG_INV_SAVE);
    }
}