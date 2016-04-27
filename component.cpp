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