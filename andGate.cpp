//
//  andGate.cpp
//  LogicGates
//
//  Created by Peter Belsley on 4/25/16.
//  Copyright © 2016 Peter Belsley. All rights reserved.
//

#include "andGate.h"
AndGate::AndGate(){
	outputEast = true;
	inputNorth = true;
	inputSouth = true;
	ID = "ANDGATE";
}

Charge AndGate::getOutputCharge(){
	if (input2 == charged && input1 == charged) {
		return charged;
	} else {
		return noCharge;
	}

}
