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

using namespace std;

const int    COMMAND_SIZE = 7;
const string COMMAND_NAME[COMMAND_SIZE]
{
    "ADD",
    "REMOVE",
    "UP",
    "DOWN",
    "RUN",
    "NEW",
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
    NEW,
    QUIT,

    /* Invalid as input */
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

void addComponent(Layer &layer, stringstream &ss);
void displayGrid(Layer &layer);
void displayCommands();
void displayComponents();
void layerUp(Layer &layer, stringstream &ss);
void layerDown(Layer &layer, stringstream &ss);
void removeComponent(Layer &layer, stringstream &ss);

void getInput(stringstream &ss);

CommandType   getCommandType(stringstream &ss);
ComponentType getComponentType(stringstream &ss);
CommandType   setup(Layer &layer, stringstream &ss);

#endif