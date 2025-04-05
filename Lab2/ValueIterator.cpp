#include "ValueIterator.h"
#include <iostream>
#include <exception>

//Theta(1)
ValueIterator::ValueIterator(const Key &k) : key(k) {
    first();
}

//Theta(1)
void ValueIterator::first() {
    valuecurrent=key.headvalue;
}

//Theta(1)
void ValueIterator::next() {
    if(!valid())
        throw out_of_range("Invalid value node");

    valuecurrent=valuecurrent->next;
}

//Theta(1)
bool ValueIterator::valid() const{
    return valuecurrent!= nullptr;
}

//Theta(1)
TValue ValueIterator::getCurrent() const{
    if(!valid())
        throw out_of_range("Invalid value node");

    return valuecurrent->value;
}


