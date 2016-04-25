//
//  light.cpp
//  LogicGates
//
//  Created by Peter Belsley on 4/25/16.
//  Copyright © 2016 Peter Belsley. All rights reserved.
//

#include "light.h"

Light::Light(){
	
	ID = "LIGHT";
	inputEast = true;
	inputNorth = true;
	inputSouth = true;
	inputWest = true;

	outputEast = true;
	outputNorth = true;
	outputSouth = true;
	outputWest = true;
}