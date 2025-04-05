#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{

    first();

}


void SortedSetIterator::first() {
    index=0;
    s.poz=0;
    if (multime.size() != 0)
    {
        if(s.poz==s.cap-1)
        {
            s.resize();
        }
        index = multime.root;
        s.push(index);
        while (multime.left[index] !=-1)
        {
            if(s.poz==s.cap-1)
            {
                s.resize();
            }
            index=multime.left[index];
            s.push(index);
        }
        if(!s.isEmpty())
        {
            index=s.top();
        }
        else
        {
            index=-1;
        }

    }
    else
    {
        index=-1;
    }
}


void SortedSetIterator::next() {

    if(!valid())
    {
        throw std::exception();
    }

    index=s.pop();

    if(multime.right[index]!=-1)
    {
        if(s.poz==s.cap-1)
        {
            s.resize();
        }
        index=multime.right[index];
        s.push(index);


        while(multime.left[index]!=-1)
        {
            if(s.poz==s.cap-1)
            {
                s.resize();
            }
            index=multime.left[index];
            s.push(index);

        }

    }
    if(!s.isEmpty())
    {
        index=s.top();
    }
    else
    {
        index=-1;
    }

}


TElem SortedSetIterator::getCurrent()
{
    if(!valid())
        throw exception();
	return multime.elements[s.top()];
}

bool SortedSetIterator::valid() const {

    return index>=0 ;
}


SortedSetIterator::Stack::Stack() {
    cap=10;
    stackElements=new TElem [10];
    poz=0;
}

void SortedSetIterator::Stack::push(int index) {
    stackElements[poz]=index;
    poz++;
}

TElem SortedSetIterator::Stack::pop() {
    poz--;
    return stackElements[poz];
}

TElem SortedSetIterator::Stack::top() const {
    return stackElements[poz-1];
}

bool SortedSetIterator::Stack::isEmpty() const {
    return poz==0;
}

void SortedSetIterator::Stack::resize() {
    int *newstackElements=new int[cap*2];
    for(int i=0;i<cap;i++)
    {
        newstackElements[i]=stackElements[i];
    }
    cap=cap*2;
    delete[] stackElements;
    stackElements=newstackElements;
}
