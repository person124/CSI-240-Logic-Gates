/* Filename:      component.cpp
 * File author:   Peter Belsley
 * Project Team:  Peter Belsley, Matthew Harrison, Calum Phillips
 * Class:         CSI-240-04
 * Assignment:    Final Project: Logic Gate
 * Date Assigned: April 18, 2016
 * Due Date:      April 29, 2016, at 11:59 pm
 *
 * Description:
 *   A program that simulates logic gates within a grid system.
 *
 * Certification of Authenticity:
 *   I certify that this is entirely my own work, except where I have given
 *   fully documented references to the work of others. I understand the
 *   definition and consequences of plagiarism and acknowledge that the assessor
 *   of this assignment may, for the purpose of assessing this assignment:
 *     -  Reproduce this assignment and provide a copy to another member of
 *        academic staff; and/or
 *     -  Communicate a copy of this assignment to a plagiarism checking
 *        service (which may then retain a copy of this assignment on its
 *        database for the purpose of future plagiarism checking)
 ******************************************************************************/

#include "component.h"

Component::Component() {
	isCharged = false;

	ID = "NULL";
}

Component::Component(string aString){
	ID = aString;
	isCharged = false;
}

Component::~Component()
{
}

/* Purpose:  To set a component to a string
 *     Pre:  A component and a string
 *    Post:  sets the ID string to the received string
 *  Author:  Peter Belsley
 ******************************************************************************/
void Component::operator=(const string &aString){
	ID = aString;
}

/* Purpose:  To tell if a compnent is charged (should be used for wires, starts and lights)
 *     Pre:  A component
 *    Post:  Returns weather or not the component is charged, notcharged, or disconected
 *  Author:  Peter Belsley
 ******************************************************************************/

bool Component::getCharge()
{
	return isCharged;
}

/* Purpose:  To tell a compnent it is charged (Use for all)
 *     Pre:  A component
 *    Post:  The component's charge and output charge is set
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::setCharged(bool ch){
	isCharged = ch;
}

/* Purpose:  To get the component type
 *     Pre:  A component
 *    Post:  the components id
 *  Author:  Peter Belsley
 ******************************************************************************/

string Component::getID(){
	return ID;
}

/* Purpose:  To get the output of a Gate
 *     Pre:  Gate operation in caps (AND, OR, XOR) and the inputs as bools
 *    Post:  the returned boolean of that logic operation
 *  Author:  Peter Belsley (With minor changes by Calum Phillips)
 ******************************************************************************/

bool getGateOutput(string type, bool i1, bool i2){
	if (type == "AND") {
		return i1 && i2;
	} else if (type == "OR") {
		return i1 || i2;
	} else if (type == "XOR") {
		return (i1 || i2) && !(i1 && i2);
	} else if (type == "NOR") {
		return !(i1 || i2);
	} else if (type == "XNOR") {
		return i1 == i2;
	} else if (type == "NAND"){
		return !(i1 && i2);
	}
	return false;
}
