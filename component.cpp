#include "component.h"

Component::Component() {
	isCharged = disconected;

	inputEast = true;
	inputNorth = true;
	inputSouth = true;
	inputWest = true;

	outputEast = false;
	outputNorth = false;
	outputSouth = false;
	outputWest = false;

	location.xPos = 0;
	location.yPos = 0;

	ID = "NULL";
}

Component::~Component()
{
}

/* Purpose:  Tell a component to output north
 *     Pre:  A component
 *    Post:  A component that outputs to north, and does not accept input from north
 *  Author:  Peter Belsley
 ******************************************************************************/
void Component::startOutputNorth()
{
	outputNorth = true;
	inputNorth = false;
}

/* Purpose:  Tell a component to output south
 *     Pre:  A component
 *    Post:  A component that outputs to south, and does not accept input from south
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::startOutputSouth()
{
	outputSouth = true;
	inputSouth = false;
}

/* Purpose:  Tell a component to output east
 *     Pre:  A component
 *    Post:  A component that outputs to east, and does not accept input from east
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::startOutputEast()
{
	outputEast = true;
	inputEast = false;
}

/* Purpose:  Tell a component to output west
 *     Pre:  A component
 *    Post:  A component that outputs to west, and does not accept input from west
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::startOutputWest()
{
	outputWest = true;
	inputWest = false;
}

/* Purpose:  Tell a component accept input from the north
 *     Pre:  A component
 *    Post:  A component that accept input from the north, and does not output to north
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::acceptInputNorth()
{
	inputNorth = true;
	outputNorth = false;
}

/* Purpose:  Tell a component accept input from the south
 *     Pre:  A component
 *    Post:  A component that accept input from the north, and does not output to south
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::acceptInputSouth()
{
	inputSouth = true;
	outputSouth = false;
}

/* Purpose:  Tell a component accept input from the east
 *     Pre:  A component
 *    Post:  A component that accept input from the east, and does not output to east
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::acceptInputEast()
{
	inputEast = true;
	outputEast = false;
}

/* Purpose:  Tell a component accept input from the west
 *     Pre:  A component
 *    Post:  A component that accept input from the west, and does not output to west
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::acceptInputWest()
{
	inputWest = true;
	outputWest = true;
}

/* Purpose:  To tell if a compnent is charged (should be used for wires, starts and lights)
 *     Pre:  A component
 *    Post:  Returns weather or not the component is charged, notcharged, or disconected
 *  Author:  Peter Belsley
 ******************************************************************************/

Charge Component::getCharge()
{
	return isCharged;
}

/* Purpose:  To tell if a compnent is outputing charge (should be used for gates)
 *     Pre:  A component
 *    Post:  Returns weather or not the component is outouting charge, notcharged, or is disconected
 *  Author:  Peter Belsley
 ******************************************************************************/
Charge Component::getOutputCharge()
{
	return isCharged;
}

/* Purpose:  To tell a compnent it is charged (Use for all)
 *     Pre:  A component
 *    Post:  The component's charge and output charge is set
 *  Author:  Peter Belsley
 ******************************************************************************/

void Component::setCharged(Charge ch){
	inputCharge = ch;
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