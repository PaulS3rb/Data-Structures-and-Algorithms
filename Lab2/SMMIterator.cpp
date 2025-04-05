#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){\
    first();
}


//complexity:Theta(1)
void SMMIterator::first(){
   keycurrent=map.head;
    if(valid())
        valuecurrent=keycurrent->headvalue;
}


//complexity:Theta(1)
void SMMIterator::next(){
    if(!valid())
        throw out_of_range("Invalid Node");

    valuecurrent=valuecurrent->next;

    if(valuecurrent== nullptr)
    {
        keycurrent=keycurrent->next;
        if(valid())
            valuecurrent=keycurrent->headvalue;
    }

}


//complexity:Theta(1)
bool SMMIterator::valid() const{

    return keycurrent!= nullptr;
}


//complexity:Theta(1)
TElem SMMIterator::getCurrent() const{
    if(!valid())
        throw out_of_range("Invalid Node");


    return{keycurrent->key,valuecurrent->value};

}


