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
#include "power.h"
#include "wire.h"
#include "light.h"
#include "execute.h"
#include "startingPos.h"

using namespace std;

const int    COMMAND_SIZE = 7;
const string COMMAND_NAME[COMMAND_SIZE]
{
    "ADD",
    "REMOVE",
    "UP",
    "DOWN",
    "RUN",
    "SETUP",
    "QUIT"
};
enum CommandType
{
    ADD,
    REMOVE,
    UP,
    DOWN,
    RUN,
    SETUP,
    QUIT,

    ENTRY
};

const int    COMPONENT_SIZE = 4;
const string COMPONENT_NAME[COMPONENT_SIZE]
{
    "POWER",
    "WIRE",
    "WIRE V",
    "LIGHT",
};
enum ComponentType
{
    /* Valid as input */
    POWER,
    WIRE,
    WIRE_V,
    LIGHT,

    /* Invalid as input */
    EMPTY
};
const string COMPONENT_OFF[COMPONENT_SIZE + 1]
{
    /* Valid as input */
    " P ",
    " + ",
    "[+]",
    " . ",

    /* Invalid as input */
    "   "
};
const string COMPONENT_ON[COMPONENT_SIZE + 1]
{
    /* Valid as input */
    " P ",
    " * ",
    "[*]",
    " ! ",

    /* Invalid as input */
    "   "
};

const int MESSAGE_SIZE = 7;
const string MESSAGE_TEXT[MESSAGE_SIZE]
{
    "WARNING: Unrecognized command.",
    "WARNING: Failed to add component.\nFormat: ADD <TYPE> <x> <y>",
    "WARNING: Failed to remove component.\nFormat: REMOVE <x> <y>",
    "WARNING: Failed to move up layers.\nFormat: UP <z>",
    "WARNING: Failed to move down layers.\nFormat: DOWN <z>",
    "WARNING: Failed to run.\nFormat: RUN",
    "WARNING: Failed to setup.\nFormat: SETUP <x> <y>"
};
enum MESSAGE_TYPE
{
    MSG_INV_CMD,
    MSG_INV_ADD,
    MSG_INV_REMOVE,
    MSG_INV_UP,
    MSG_INV_DOWN,
    MSG_INV_RUN,
    MSG_INV_SETUP,
    MSG_INV_QUIT
};

void addComponent(Layer &layer, stringstream &ss);
void displayGrid(Layer &layer);
void displayCommands();
void displayComponents();
void displayMessage(MESSAGE_TYPE code);
CommandType getCommandType(stringstream &ss);
ComponentType getComponentType(stringstream &ss);
void getInput(stringstream &ss);
void layerUp(Layer &layer, stringstream &ss);
void layerDown(Layer &layer, stringstream &ss);
void removeComponent(Layer &layer, stringstream &ss);
void setup(Layer &layer, stringstream &ss);

#endif