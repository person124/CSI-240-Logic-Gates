#ifndef LAYER_H
#define LAYER_H

#include "grid.h"

class Layer
{
    private:
        struct Node
        {
            Grid* mData;
            Node* mNext;
            Node()
            {
                mData = NULL;
                mNext = NULL;
            }
            Node(Grid* g)
            {
                mData = g;
                mNext = NULL;
            }
        };
        Node* mHead;
        Node* mTail;
        int mCount, mCurrent;
    public:
        Layer();
        ~Layer();
        void add(int, Grid*);
        void dequeue();
        Grid* get(int);
		int getCount();
		int getCurrentLayer();
        void push(Grid*);
        void pop();
        void enqueue(Grid*);
        void remove(int);
};

Grid* operator++(Layer&);
Grid* operator--(Layer&);

#endif
