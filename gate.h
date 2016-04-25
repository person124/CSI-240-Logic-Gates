//
//  gate.hpp
//  LogicGates
//
//  Created by Peter Belsley on 4/25/16.
//  Copyright © 2016 Peter Belsley. All rights reserved.
//

#ifndef gate_h
#define gate_h

#include "component.h"

class Gate : protected Component {
protected:
	Charge input1, input2;

public:
	void setInput1(Charge);
	void setInput2(Charge);
	Charge getOutputCharge();
};

#endif /* gate_h */
