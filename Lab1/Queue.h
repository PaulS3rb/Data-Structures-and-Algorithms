#pragma once
#include <vector>
#include <iostream>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

class Queue
{
private:
    //ADT Queue - repräsentiert mithilfe eines zirkulären dynamischen Arrays von Elementen
	//TODO - Representation
    int capacity;
    int front;
    int rear;
    TElem *elements;
    public:
	Queue();

    //adds an elements to the queue
    //complexity:Theta(1)
    void addelem(TElem e);
	//pushes an element to the end of the queue
	void push(TElem e);

	//returns the element from the front of the queue
	//throws exception if the queue is empty
    TElem top() const;

	//removes and returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem pop();

	//checks if the queue is empty
    bool isEmpty() const;

    void resizedefault();

    void resizeuprearbeforefront();

    void resizedowndefault();

    void resizedownrearbeforefront();
    void print();
	// destructor
	~Queue();

    bool isequal(Queue q);

    void reorder();
};
