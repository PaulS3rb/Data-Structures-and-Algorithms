#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART

/*
 * ADT Bag – repräsentiert mithilfe einer Hashtabelle mit offener Adressierung, mit
doppeltem Hashing, wo die Elemente gespeichert sind. Falls ein Element mehrmals
vorkommt, dann wird es mehrmals in der Hashtabelle gespeichert.
 */
typedef int TElem;
#define NULL_TELEM -111111

class BagIterator; 
class Bag {

private:
	//TODO - Representation

    int hashfunc1(TElem e) const;
    int hashfunc2(TElem e) const;
    int hashfunc(TElem e,int i) const;
    bool isprime(int e) const;
    int searchprime(int e) const;
    void resizeup();



	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
    int capacity;
    TElem *elements;
	Bag();

    bool operator == (const Bag &bag);

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

    void print() const;
	//destructor
	~Bag();
};