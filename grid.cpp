/* Filename:      grid.cpp
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

#include "grid.h"

Grid::Grid(int w, int h)
{
    mWidth = w;
    mHeight = h;
    nullComp = Component();

    mGrid = new Component*[mWidth];
    for (int i = 0; i < mWidth; i++)
    {
        mGrid[i] = new Component[mHeight];
        for (int j = 0; j < mHeight; j++)
            mGrid[i][j] = Component();
    }
}

Grid::~Grid()
{
    for (int i = 0; i < mWidth; i++)
        delete[] mGrid[i];
    delete mGrid;
}

/* Purpose: Gets the component at a specified location
 *     Pre: None
 *    Post: None
 *  Author: Calum M. Phillips
 */
Component& Grid::get(int x, int y)
{
    if (x < 0 || y < 0 || x >= mWidth || y >= mHeight)
        return nullComp;
    return mGrid[x][y];
}

int Grid::getWidth()
{
    return mWidth;
}

int Grid::getHeight()
{
    return mHeight;
}

/* Purpose: Clears the component at the specified location
 *     Pre: None
 *    Post: Sets the data at the location to the empty component, and returns true if successful
 *  Author: Calum M. Phillips
 */
bool Grid::remove(int x, int y)
{
    if (x < 0 || y < 0 || x >= mWidth || x >= mHeight)
        return false;
    mGrid[x][y] = Component();
    return true;
}

/* Purpose: Resizes the grid to the new dimensions
 *     Pre: None
 *    Post: Any excess data is removed, and new slots are filled with the empty component
 *  Author: Calum M. Phillips
 */
void Grid::resize(int newW, int newH)
{
    if (mWidth != newW)
    {
        if (mWidth < newW)
        {
            Component** temp = new Component*[newW];
            for (int i = 0; i < mWidth; i++)
                temp[i] = mGrid[i];
            for (int i = mWidth; i < newW; i++)
            {
                temp[i] = new Component[mHeight];
                for (int j = 0; j < mHeight; j++)
                    temp[i][j] = Component();
            }
            mWidth = newW;
            mGrid = temp;
        }
        else
        {
            Component** temp = new Component*[newW];
            for (int i = 0; i < newW; i++)
                temp[i] = mGrid[i];
            for (int i = newW; i < mWidth; i++)
                delete[] mGrid[i];
            mWidth = newW;
            mGrid = temp;
        }
    }

    if (mHeight != newH)
    {
        if (mHeight < newH)
        {
            for (int i = 0; i < mWidth; i++)
            {
                Component* temp = new Component[newH];
                for (int j = 0; j < mHeight; j++)
                    temp[j] = mGrid[i][j];
                for (int j = mHeight; j < newH; j++)
                    temp[j] = Component();
                mGrid[i] = temp;
            }
        }
        else
        {
            for (int i = 0; i < mWidth; i++)
            {
                Component* temp = new Component[newH];
                for (int j = 0; j < newH; j++)
                    temp[j] = mGrid[i][j];
                for (int j = newH; j < mHeight; j++)
                    delete &mGrid[i][j];
                mGrid[i] = temp;
            }
        }
        mHeight = newH;
    }
}

/* Purpose: Sets the component at the specified location to the specified value.
 *     Pre: None
 *    Post: Sets the data, and returns true if the data was set.
 *  Author: Calum M. Phillips
 */
bool Grid::set(int x, int y, Component c)
{
    if (x < 0 || y < 0 || x >= mWidth || y >= mHeight)
        return false;
    mGrid[x][y] = c;
    return true;
}
