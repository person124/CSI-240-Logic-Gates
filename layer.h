#ifndef LAYER_H
#define LAYER_H

#include "stddef.h"
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
            Node(Grid& g)
            {
                *mData = g;
                mNext = NULL;
            }
        };
        Node* mHead;
        Node* mTail;
        int mCount;
    public:
        Layer();
        ~Layer();
        void add(int, Grid&);
        Grid* get(int);
        void push(Grid&);
        void pop();
        void enqueue(Grid&);
        void remove(int);
};

#endif
