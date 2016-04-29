#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "Utilities.h"

#include "grid.h"
#include "layer.h"
#include "component.h"
#include "execute.h"
#include "startingPos.h"

using namespace std;

/* COMMAND
 ******************************************************************************/
const int    COMMAND_SIZE = 7;
const string COMMAND_NAME[COMMAND_SIZE]
{
    "ADD",
    "REMOVE",
    "UP",
    "DOWN",
    "RUN",
    "RESIZE",
    "QUIT"
};
enum CommandType
{
    ADD,
    REMOVE,
    UP,
    DOWN,
    RUN,
    RESIZE,
    QUIT,

    NONE
};

/* COMPONENT
 ******************************************************************************/
const int    COMPONENT_SIZE = 3;
const string COMPONENT_NAME[COMPONENT_SIZE]
{
    "POWER",
    "WIRE",
    "LIGHT",
};
enum ComponentType
{
    /* Valid as input */
    POWER,
    WIRE,
    LIGHT,

    /* Invalid as input */
    EMPTY
};

const string COMPONENT_OFF[COMPONENT_SIZE + 1]
{
    /* Valid as input */
    " P ",
    " + ",
    " . ",

    /* Invalid as input */
    " - "
};
const string COMPONENT_ON[COMPONENT_SIZE + 1]
{
    /* Valid as input */
    " P ",
    " * ",
    " ! ",

    /* Invalid as input */
    " - "
};

/* MESSAGE
 ******************************************************************************/
const int MESSAGE_SIZE = 8;
const string MESSAGE_TEXT[MESSAGE_SIZE]
{
    "WARNING: Unrecognized command.",
    "WARNING: Failed to add component. Format: ADD <TYPE> <x> <y>",
    "WARNING: Failed to remove component. Format: REMOVE <x> <y>",
    "WARNING: Failed to change layers. Format: DOWN <z> | UP <z>",
    "WARNING: Failed to resize. Format: RESIZE <x> <y>",
    "WARNING: Failed to setup. Format: SETUP <x> <y>",
    "Preparing to terminate. Goodbye!",
    "Execute complete."
};
enum MESSAGE_TYPE
{
    MSG_INV_COMMAND,
    MSG_INV_ADD,
    MSG_INV_REMOVE,
    MSG_INV_LAYER,
    MSG_INV_RESIZE,
    MSG_INV_QUIT,
    MSG_SHUTDOWN,
    MSG_EXECUTE
};

/* FUNCTIONS
 ******************************************************************************/
void addComponent(Layer &layer, StartingList &startingList, stringstream &ss);
void changeLayer(Layer &layer, stringstream &ss, CommandType direction);
void displayGrid(Layer &layer);
void displayCommands();
void displayComponents();
void displayMessage(MESSAGE_TYPE code);
void getInput(stringstream &ss);
bool hasJunk(stringstream &ss);
bool isPosition(Layer &layer, const int x, const int y);
CommandType readCommandType(stringstream &ss);
ComponentType readComponentType(string id);
ComponentType readComponentType(stringstream &ss);
int  readNumber(stringstream&ss);
void removeComponent(Layer &layer, StartingList &startingList, stringstream &ss);
void resize(Layer &layer, StartingList &startingList, stringstream &ss);

#endif