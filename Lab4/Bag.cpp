#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {

    capacity=11;
    elements=new TElem[capacity];
    for(int i=0;i<capacity;i++)
    {
        elements[i]=NULL_TELEM;
    }
}

void Bag::print() const {

    for(int i=0;i<capacity;i++)
    {
        if(elements[i]!=NULL_TELEM)
        {
            cout<<i<<":"<<elements[i]<<"\n";
        }
    }
}

int Bag::hashfunc1(TElem e) const {
    return abs(e) % capacity;
}

int Bag::hashfunc2(TElem e) const {
    return 1 + (abs(e) %(capacity-1));
}

int Bag::hashfunc(TElem e, int i) const {
    return (hashfunc1(e) + i * hashfunc2(e)) % capacity;
}
/*
 * bestcase=Theta(1)
 * worstcase=Theta(n)
 * average=Theta(1)
 */
void Bag::add(TElem elem) {
    int i=0;

    if(size()==capacity)
        resizeup();

    //calculates position of element
    int position = hashfunc(elem,i);


    //if position is already occupied, increase "i" and hash for the element again
    while(elements[position] != NULL_TELEM && i<capacity &&elements[position]!=-111112)
    {
        i++;
        position= hashfunc(elem,i);
    }

    elements[position]= elem;

}

/*
 * best case=Theta(1)
 * worst case=Theta(n)
 * average case=Theta(1)
 */
bool Bag::remove(TElem elem) {
    int i=0;
    int position= hashfunc(elem,i);

    while(i<capacity && elements[position]!=elem && elements[position]!=NULL_TELEM)
    {
        i++;
        position = hashfunc(elem,i);
    }

    if(elements[position]==elem && i<capacity)
    {
        elements[position]=-111112;

        return true;
    }
    return false;

}
/*
 * best case=Theta(1)
 * worst case=Theta(n)
 * average case=Theta(1)
 */
bool Bag::search(TElem elem) const {
        int i=0;
        int position = hashfunc(elem,i);

        while(i<capacity && elements[position]!=elem && elements[position]!=NULL_TELEM)
        {
            i++;
            position = hashfunc(elem,i);

        }

        if(i<capacity && elements[position]==elem)
        {
            return true;
        }

	return false;
}

/*
 * best case=Theta(1)
 * worst case=Theta(n)
 * average case=Theta(1)
 */
int Bag::nrOccurrences(TElem elem) const {

    int ct=0;

    int i=0;
    int position = hashfunc(elem,i);

    if(elements[position]==elem)
        ct++;

    while(i<capacity  && elements[position]!=NULL_TELEM)
    {
        i++;
        position = hashfunc(elem,i);
        if(elements[position]==elem)
            ct++;
    }

    return ct;


}

/*
 * best case = worst case = average case = Theta(n)
 */
int Bag::size() const {

    int size=0;
	for(int i=0;i<capacity;i++)
    {
        if(elements[i]!=NULL_TELEM &&elements[i]!=-111112)
        {
            size++;
        }
    }
    return size;
}


bool Bag::isEmpty() const {

	return size()==0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] elements;
}

void Bag::resizeup() {
    int oldcapacity=capacity;
    capacity=capacity*2+1;
    capacity=searchprime(capacity);
    TElem *newelements=new TElem [capacity];
    for(int i=0;i<capacity;i++)
    {
        newelements[i]=NULL_TELEM;
    }


    for(int i=0;i<oldcapacity;i++)
    {
        if(elements[i]!=NULL_TELEM && elements[i]!=-111112)
        {
            int k=0;
            int position = hashfunc(elements[i],k);

            while(newelements[position]!=NULL_TELEM)
            {
                k++;
                position = hashfunc(elements[i],k);
            }
            newelements[position]=elements[i];
        }
    }
    delete[] elements;
    elements=newelements;

}


bool Bag::isprime(int e) const {

    for(int d=3;d*d<e;d=d+2)
    {
        if(e%d==0)
            return false;
    }
    return true;


}

int Bag::searchprime(int e) const {
    while(!isprime(e))
    {
        e=e+2;
    }
    return e;
}

bool Bag::operator==(const Bag &bag) {

    for(int i=0;i<capacity;i++)
    {
        if (elements[i] != NULL_TELEM && elements[i] != -111112)
        {
            if(nrOccurrences(elements[i])!= bag.nrOccurrences(elements[i]))
                return false;
        }
    }
    return true;
}






