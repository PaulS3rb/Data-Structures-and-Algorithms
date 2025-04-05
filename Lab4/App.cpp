#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {

    Bag b;
    for(int i=0;i<13;i++)
        b.add(i);

    Bag c;
    for(int i=0;i<5;i++)
        c.add(i);

    if(b==c)
    {
        cout<<"egal";
    }
    else
    {
        cout<<"nu e egal";
    }

    cout<<"\n";


    testAll();
	cout << "Short tests over" << endl;
	testAllExtended();

	cout << "All test over" << endl;


}