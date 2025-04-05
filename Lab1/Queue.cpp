#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

//Complexity:best=worst=average=Theta(1)
Queue::Queue() {
	//TODO - Implementation
    capacity=4;
    front=-1;
    rear=-1;
    elements=new TElem[capacity];
}
//Complexity:best=worst=average=Theta(n)
void Queue::resizedefault()
{
    //initialises a new array with the new capacity
    TElem *newElems;
    capacity= capacity*2;
    newElems = new TElem[capacity];
    //moves the positions between front and rear to the new array
    for(int i=front;i<=rear;i++)
        newElems[i]=elements[i];
    delete[] elements;
    elements=newElems;
}

//Complexity:best=worst=average=Theta(n)
void Queue::resizeuprearbeforefront() {
    //initialises a new array with the new capacity
    TElem *newElems;
    capacity= capacity*2;
    newElems = new TElem[capacity];
    //moves the elements from the front position to the end of the array in the new array
    for(int i=front;i<capacity/2;i++)
        newElems[i+capacity/2]=elements[i];
    //moves the elements from the start of the array to the rear position in the new array
    for(int i=0;i<=rear;i++)
        newElems[i]=elements[i];

    //sets the new position of front
    front=front+capacity/2;

    delete[] elements;

    elements=newElems;
}

//Complexity:best=worst=Theta(n)
void Queue::resizedowndefault() {
    //initialises a new array with the new capacity
    TElem *newElems;
    capacity=capacity/2;
    newElems=new TElem [capacity];
    //moves the elements to the front of the next array
    for(int i=front;i<=rear;i++)
            newElems[i-front]=elements[i];
    delete[] elements;
    //sets the new positions of front and rear
    rear=rear-front;
    front=0;

    elements=newElems;
}

//Complexity:best=worst=average=Theta(n)
void Queue::resizedownrearbeforefront() {
    int poz,pozrear;
    TElem *newElems;
    capacity=capacity/2;
    newElems=new TElem [capacity];
    //initialises a new array with the new capacity
    for(int i=front;i<capacity*2;i++) {
        //moves the elements after front to the beginning of the array
        newElems[i - front] = elements[i];
        poz=i - front+1;
    }

    for(int i=0;i<=rear;i++) {
        //appends the elements from the beginning to the rear of the previous array
        newElems[poz + i] = elements[i];
        pozrear=poz+i;
    }
    //sets the new positions of front and rear
    front=0;
    rear=pozrear;
    delete []elements;
    elements=newElems;
}

//Complexity:
//best(no resize needed)=Theta(1)
//worst(resize needed)=Theta(n)
//average=Theta(1)
void Queue::push(TElem elem) {
    //TODO - Implementation
    //checks if the list is currently empty
    if(front==-1) {
        front = 0;

    }
    //checks if rear>front or the list is currently empty
    if(rear>=front || rear==-1) {
        //appends an element to the rear
        if (rear < capacity - 1) {
            addelem(elem);

        }
        else {
            //checks if there is available space at the beginning of the arrayt when rear is at the end of it
            if (rear == capacity - 1 && front != 0) {
                rear = 0;
                elements[rear] = elem;
            }
            //checks if the array is full
            if (front == 0 && rear == capacity - 1) {
                //resizes the array and adds an element
                resizedefault();
                addelem(elem);
            }
        }
    }
    else {
        //checks if rear<front
        if (rear < front) {
            //checks if the next element is the front so that it doesn't overwrite it
            if (rear + 1 != front) {
                addelem(elem);
            } else {
                //resizes the array and adds an element
                resizeuprearbeforefront();
                addelem(elem);
            }
        }
    }
}

//Complexity:worst=average=best=Theta(1)
TElem Queue::top() const {

    TElem top;
    if (!isEmpty())
    {
        //returns the top element
        top = elements[front];
        return top;
    }
    else
    {
        throw exception();
    }


}

//Complexity:
// best(no resize needed)=Theta(1)
// worst(resize needed)=Theta(n)
TElem Queue::pop() {
	//TODO - Implementation
	if(!isEmpty())
    {
        //stores the value of the element that needs to be popped
        int val=elements[front];
        //checks if the element is the last remaining in the array
        if(front==rear) {
            front = -1;
            rear=-1;
        }
        else
            //pushes back the front  position
            front++;
        //checks if front is at the end of the array
        if(front==capacity)
            //moves front to the beginning of the array
            front=0;
        if(front<rear)
            //checks if we need to resize down the array
            if(rear-front+1<=capacity/4)
                resizedowndefault();
        if(front>rear)
            //checks if we need to resize down the array
            if(capacity+1-front+rear<=capacity/4)
                resizedownrearbeforefront();
        return val;
    }else
    {
        throw exception();
    }
}

//Complexity: Theta(1)
bool Queue::isEmpty() const {
	//TODO - Implementation
    if (front == -1) {
        return true;
    }
    else {
        return false;
    }
}

//Complexity:worst=average=best=Theta(1)
Queue::~Queue() {
	//TODO - Implementation
    delete[] elements;

}

//Complexity:worst=average=best=Theta(n)
void Queue::print() {
    for(int i=0;i<capacity;i++)
        cout<<elements[i]<<" ";
    cout<<"\n";
}


//Complexity:worst=average=best=Theta(1)
void Queue::addelem(TElem e) {
    //pushes back the rear position and appends an element to it
    rear+=1;
    elements[rear]=e;
}

bool Queue::isequal(Queue q) {
    if(front>rear)
        reorder();
    if(q.front>q.rear)
        q.reorder();
    if (rear-front!=q.rear-q.front)
        return false;



    for (int i = front; i <= rear; i++)
    {
        if (elements[i] != q.elements[i])
            return false;
    }

    return true;


    /*if(rear-front!=q.rear-q.front)
    {
        for(int i=front;i<=rear;i++)
            if(elements[i]!=q.elements[i])
                return false;
        return true;
    }*/

}


void Queue::reorder() {
    int poz,pozrear;
    TElem *newElems;
    newElems=new TElem [capacity];
    //initialises a new array with the new capacity
    for(int i=front;i<capacity;i++) {
        //moves the elements after front to the beginning of the array
        newElems[i - front] = elements[i];
        poz=i - front+1;
    }

    for(int i=0;i<=rear;i++) {
        //appends the elements from the beginning to the rear of the previous array
        newElems[poz + i] = elements[i];
        pozrear=poz+i;
    }
    //sets the new positions of front and rear
    front=0;
    rear=pozrear;
    delete []elements;
    elements=newElems;
}



