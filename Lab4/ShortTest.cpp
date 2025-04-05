#include "ShortTest.h"
#include <assert.h>
#include "Bag.h"
#include "BagIterator.h"


void testAll() { 
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0); 
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
    assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);

    BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}

    Bag m;
    Bag n;
    for(int i=0;i<5;i++)
    {
        m.add(i);
        n.add(i);
    }

    assert((m==n)== true);
    Bag o;
    Bag p;
    for(int i=0;i<5;i++)
    {
        o.add(i);
    }
    for(int i=4;i>=0;i--)
    {
        p.add(i);
    }

    assert((o==p)==true);


    Bag x;

    for(int i=0;i<20;i++)
    {
        x.add(i);
    }
    for(int i=5;i<20;i++)
    {
        x.remove(i);
    }
    x.add(17);
    Bag y;
    for(int i=0;i<5;i++)
    {
        y.add(i);
    }
    y.add(17);
    assert((y==x)== true);

}
