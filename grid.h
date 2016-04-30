/* Filename:      grid.h
 * File author:   Calum Phillips
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

#ifndef GRID_H
#define GRID_H

#include "component.h"

class Grid
{
    public:
        Grid(int w = 10, int h = 10);
        ~Grid();
        Component& get(int, int);
		int getWidth();
		int getHeight();
        bool remove(int, int);
        void resize(int, int);
        bool set(int, int, Component);
    private:
        Component** mGrid;
        int mWidth, mHeight;
        Component nullComp;
};

#endif
