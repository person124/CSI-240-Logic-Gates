#ifndef GRID_H
#define GRID_H

#include "component.h"

class Grid
{
    public:
        Grid(int w = 10, int h = 10);
        ~Grid();
        Component get(int, int);
		int getWidth();
		int getHeight();
        bool remove(int, int);
        void resize(int, int);
        bool set(int, int, Component);
    private:
        Component** mGrid;
        int mWidth, mHeight;
};

#endif
