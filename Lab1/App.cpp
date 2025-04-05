#include "Queue.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>

using namespace std;

int main() {

	testAll();
	testAllExtended();

	cout << "Test end" << endl;

    /*Queue p;
    Queue q;
    for(int i=0;i<4;i++) {
        p.push(i);
        q.push(i);
    }
    p.push(4);
    p.reorder();
    p.print();
    p.push(5);
    p.print();
    q.push(4);
    cout<<p.isequal(q);


*/
    Queue a;
    a.push(0);
    a.push(1);
    a.push(2);
    a.pop();
    a.reorder();
    a.print();

}