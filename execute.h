#ifndef EXECUTE_H
#define EXECUTE_H

#include <string>

#include "component.h"
#include "layer.h"
#include "startingPos.h"

void execute(Layer&, StartingList&);
void invokeStart(Layer&, StartingPos*, Component&, Charge);
void invokeLight(Layer&, int, int, int, Charge);
void invokeNot(Layer&, int, int, int, Charge);
void invokeWire(Layer&, int, int, int, Charge);
bool isGate(string);
void poke(Layer&, int, int, int, Charge);
void pokeLoc(Layer&, int, int, int, Charge, char);
bool wireCheck(Charge, Charge);

#endif
