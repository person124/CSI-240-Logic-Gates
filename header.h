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
#include "start.h"
#include "wire.h"
#include "light.h"

using namespace std;

const int    COMMAND_SIZE = 7;
const string COMMAND_NAME[COMMAND_SIZE]
{
    "ADD",
    "REMOVE",
    "UP",
    "DOWN",
    "RUN",
    "CLEAR",
    "QUIT"
};
enum CommandType
{
    /* Valid as input */
    ADD,
    REMOVE,
    UP,
    DOWN,
    RUN,
    CLEAR,
    QUIT,

    /* Invalid as input */
    NONE
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

struct Command
{
    CommandType   mType;
    ComponentType mComponent;
    int           mParameter1;
    int           mParameter2;

    Command()
    {
        mType       = NONE;
        mComponent  = EMPTY;
        mParameter1 = -1;
        mParameter2 = -1;
    }
};

void addComponent(const Command command);
void displayGrid();
void displayCommands();
void displayComponents();
void layerUp(const Command command, const int &layer);
void layerDown(const Command command, const int &layer);
void removeComponent(const Command command);

Command     getCommand();
CommandType getCommandType(stringstream &ss);
int         getPosition(stringstream &ss, const int bound);

#endif