/* Filename:      header.h
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
#include "fileWork.h"
#include "startingPos.h"


using namespace std;


const int    GRID_MAX  = 255;
const string DATA_PATH = "data.txt";


/* COMMAND PARSING SYSTEM
 ******************************************************************************/
enum CommandType
{
    ADD,
    REMOVE,
    UP,
    DOWN,
    RUN,
    RESIZE,
    CLEAR,
    SAVE,
    LOAD,
    QUIT,

    NONE
};

const int COMMAND_SIZE = 10;

const string COMMAND_NAME[COMMAND_SIZE]
{
    "ADD",
    "REMOVE",
    "UP",
    "DOWN",
    "RUN",
    "RESIZE",
    "CLEAR",
    "SAVE",
    "LOAD",
    "QUIT"
};


/* COMPONENT PARSING SYSTEM
 ******************************************************************************/
enum ComponentType
{
    POWER,
    WIRE,
    LIGHT,
    AND,
    NAND,
    OR,
    NOR,
    XOR,
    XNOR,
    NOT,
    VERT,

    EMPTY
};

const int    COMPONENT_SIZE = 11;

const string COMPONENT_NAME[COMPONENT_SIZE]
{
    "POWER",
    "WIRE",
    "LIGHT",
    "AND",
    "NAND",
    "OR",
    "NOR",
    "XOR",
    "XNOR",
    "NOT",
    "VERT"
};

const string COMPONENT_OFF[COMPONENT_SIZE + 1]
{
    " |P| ",
    "  +  ",
    " |.| ",
    " and ",
    " nand",
    "  or ",
    " nor ",
    " xor ",
    " xnor",
    " not ",
    " [+] ",

    "  -  "
};

const string COMPONENT_ON[COMPONENT_SIZE + 1]
{
    " |P| ",
    "  *  ",
    " |!| ",
    " AND ",
    " NAND",
    "  OR ",
    " NOR ",
    " XOR ",
    " XNOR",
    " NOT ",
    " [*] ",

    "  -  "
};


/* MESSAGE PARSING SYSTEM
 ******************************************************************************/
enum MESSAGE_TYPE
{
    MSG_INV_COMMAND,
    MSG_INV_ADD,
    MSG_INV_REMOVE,
    MSG_INV_LAYER,
    MSG_INV_RESIZE,
    MSG_INV_QUIT,
    MSG_INV_SAVE,
    MSG_INV_LOAD,
    MSG_SHUTDOWN,
    MSG_EXECUTE,
    MSG_SAVE,
    MSG_LOAD
};

const int MESSAGE_SIZE = 12;

const string MESSAGE_TEXT[MESSAGE_SIZE]
{
    "WARNING: Unrecognized command.",
    "WARNING: Failed to add component. Format: ADD <TYPE> <x> <y>",
    "WARNING: Failed to remove component. Format: REMOVE <x> <y>",
    "WARNING: Failed to change layers. Format: DOWN <z> | UP <z>",
    "WARNING: Failed to resize. Format: RESIZE <x> <y>",
    "WARNING: Failed to setup. Format: SETUP <x> <y>",
    "WARNING: Failed to save file. Format: SAVE <path>",
    "WARNING: Failed to load file. Format: LOAD <path>",
    "Preparing to terminate. Goodbye!",
    "Execute complete.",
    "Save complete.",
    "Load complete."
};


/* FRONT-END FUNCTIONS
 ******************************************************************************/
void addComponent(Layer &layer, StartingList &startingList, stringstream &ss);
void addComponent(Layer &layer, StartingList &startingList, const ComponentType type, const int xPos, const int yPos);
void changeLayer(Layer &layer, stringstream &ss, CommandType direction);
void clear(Layer &layer, StartingList &startingList, stringstream &ss);
void displayGrid(Layer &layer);
void displayCommands();
void displayComponents();
void displayMessage(MESSAGE_TYPE code);
void getInput(stringstream &ss);
bool hasJunk(stringstream &ss);
bool isPosition(Layer &layer, const int x, const int y);
void load(Layer &layer, StartingList &startinglist, stringstream &ss);
CommandType readCommandType(stringstream &ss);
ComponentType readComponentType(string id);
ComponentType readComponentType(stringstream &ss);
int readNumber(stringstream&ss);
void removeComponent(Layer &layer, StartingList &startingList, stringstream &ss);
void removeComponent(Layer &layer, StartingList &startingList, const int xPos, const int yPos);
void resize(Layer &layer, StartingList &startingList, stringstream &ss);
void run(Layer &layer, StartingList &startingList, stringstream &ss);
void save(Layer &layer, stringstream &ss);

#endif