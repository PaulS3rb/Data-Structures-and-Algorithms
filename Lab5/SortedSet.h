#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111
#include <string>
using namespace std;
class SortedSetIterator;



/*
 * ADT SortedSet – repräsentiert mithilfe eines BST mit einer verketteten Repräsentierung
auf Arrays
 */
class SortedSet {
	friend class SortedSetIterator;
public:
    TElem *elements;
    int* parent;
    int* left;
    int* right;
    int root;
    int capacity;
    int firstEmpty;
    int nrElems;
    Relation rel;


public:
	//constructor
	SortedSet(Relation r);

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TComp e);

    bool addrec(TComp e, int poz);

    void resize();

    void search_firstEmpty();
	
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	bool remove(TComp e);

    bool removerec(TComp e,int poz,string direction);
	//checks if an element is in the sorted set

    void remove_value(int poz);

    int find_minimum(int poz);
	bool search(TElem elem) const;

    bool searchrec(TElem elem, int poz) const;


	//returns the number of elements from the sorted set
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;

	// destructor
	~SortedSet();




};
