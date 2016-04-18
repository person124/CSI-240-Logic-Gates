#include "grid.h"

int main()
{
    Grid* g = new Grid();
    delete g;
}

Grid::Grid(int w, int h)
{
    mWidth = w;
    mHeight = h;

    mGrid = new Component*[mWidth];
    for (int i = 0; i < mWidth; i++)
        mGrid[i] = new Component[mHeight];
}

Grid::~Grid()
{
    for (int i = 0; i < mWidth; i++)
        delete[] mGrid[i];
    delete mGrid;
}

Component& Grid::get(int x, int y)
{
    if (x < 0 || y < 0 || x >= mWidth || y >= mHeight)
        return Component(); //Need a Null Component
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

bool Grid::remove(int x, int y)
{
    if (x < 0 || y < 0 || x >= mWidth || x >= mHeight)
        return false;
    mGrid[x][y] = Component(); //Null Component
    return true;
}

void Grid::resize(int newW, int newH)
{
    if (mWidth != newW)
    {
        if (mWidth < newW)
        {
            Component** temp = new Component*[newW];
            for (int i = 0; i < mWidth; i++)
                temp[i] = mGrid[i];
            for (int i = 0; i < newW - mWidth; i++)
                temp[i] = new Component[newH];
            mWidth = newW;
            mGrid = temp;
        }
        else
        {
            Component** temp = new Component*[newW];
            for (int i = 0; i < newW; i++)
                temp[i] = mGrid[i];
            for (int i = newW + 1; i < mWidth; i++)
                delete[] mGrid[i];
            mWidth = newW;
            mGrid = temp;
        }
    }

    if (mHeight != newH)
    {
        if (mHeight < newH)
        {
            for (int i = 0; i < mHeight; i++)
            {
                Component* temp = new Component[newH];
                for (int j = 0; j < mHeight; j++)
                    temp[j] = mGrid[i][j];
                mGrid[i] = temp;
            }
        }
        else
        {
            for (int i = 0; i < mHeight; i++)
            {
                Component* temp = new Component[newH];
                for (int j = 0; j < newH; j++)
                    temp[j] = mGrid[i][j];
                for (int j = newH + 1; j < mHeight; j++)
                    delete [] mGrid[i];
                mGrid[i] = temp;
            }
        }
        mHeight = newH;
    }
}

bool Grid::set(int x, int y, Component c)
{
    if (x < 0 || y < 0 || x >= mWidth || y >= mHeight)
        return false;
    mGrid[x][y] = c;
    return true;
}
