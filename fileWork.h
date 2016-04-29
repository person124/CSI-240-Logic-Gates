#ifndef FILEWORK_H
#define FILEWORK_H

#include <fstream>
#include <string>

#include "component.h"
#include "header.h"
#include "layer.h"

using namespace std;

string getIDFromInt(int);
int getIntFromID(string);
bool loadFromFile(string, Layer&);
bool saveToFile(string, Layer&);

#endif
