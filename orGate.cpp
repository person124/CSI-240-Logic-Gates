//
//  orGate.cpp
//  LogicGates
//
//  Created by Peter Belsley on 4/25/16.
//  Copyright © 2016 Peter Belsley. All rights reserved.
//

#include "orGate.h"

orGate::orGate(){
	inputEast = true;
	outputWest = true;
}

Charge Gate::getOutputCharge() {
	if (input1 == charged || input2 == charged) {
		return charged;
	} else {
		return noCharge;
	}
}