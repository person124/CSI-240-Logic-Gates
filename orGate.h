//
//  orGate.hpp
//  LogicGates
//
//  Created by Peter Belsley on 4/25/16.
//  Copyright © 2016 Peter Belsley. All rights reserved.
//

#ifndef orGate_hpp
#define orGate_hpp

#include "gate.h"


class orGate : protected Gate {

public:
	orGate();
	Charge getOutputCharge();
};

#endif /* orGate_hpp */
