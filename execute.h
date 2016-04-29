#ifndef EXECUTE_H
#define EXECUTE_H

#include <string>

#include "component.h"
#include "layer.h"
#include "startingPos.h"

void execute(Layer&, StartingList&);
void invokeGate(Layer&, int, int, int, bool, char);
void invokeLight(Layer&, int, int, int, bool);
void invokeNot(Layer&, int, int, int, bool);
void invokeWire(Layer&, int, int, int, bool);
bool isGate(string);
void poke(Layer&, int, int, int, bool);
void pokeLoc(Layer&, int, int, int, bool, char);
bool wireCheck(bool, bool);

#endif
