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
Layer loadFromFile(string);
bool saveToFile(string, Layer&);

#endif
