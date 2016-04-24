#ifndef EXECUTE_H
#define EXECUTE_H

#include "component.h"
#include "layer.h"
#include "startingPos.h"

void execute(Layer&, StartingList&);
void invokeStart(Layer&, StartingPos*, Component&, Charge);
void invokeLight(Layer&, int, int, int, Charge);

#endif
