#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    index=0;
    size=c.size();
    first();
}

void BagIterator::first() {
    index=0;
    while (bag.elements[index] == NULL_TELEM || bag.elements[index] == -111112)
        index++;
}

void BagIterator::next() {
    if(!valid())
        throw exception();
    index++;
    if(index<bag.capacity) {

        while (bag.elements[index] == NULL_TELEM || bag.elements[index] == -111112)
            index++;

    }


}



bool BagIterator::valid() const {
    if(bag.size()==0)
    {
        return false;
    }
    if(index<bag.capacity)
        return true;

    return false;


}



TElem BagIterator::getCurrent() {


    if(valid()) {
    return bag.elements[index];
    }
    else throw exception();
}
