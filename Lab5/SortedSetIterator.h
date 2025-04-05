#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);
    class Stack
    {
    public:

        TElem *stackElements;
        int poz;
        int cap;
        Stack();
        void push(int index);
        TElem pop();
        TElem top() const;
        bool isEmpty() const;
        void resize();
    };

    int index;
    Stack s;
public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;

};

