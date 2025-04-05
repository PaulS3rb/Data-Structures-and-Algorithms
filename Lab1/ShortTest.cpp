#include "ShortTest.h"
#include "Queue.h"
#include <assert.h>

void testAll() { 
	Queue q;
	assert(q.isEmpty() == true);
	q.push(5);
	q.push(1);
	q.push(10);
	assert(q.isEmpty() == false);
	assert(q.top() == 5);
	assert(q.pop() == 5);
	assert(q.top() == 1);
	assert(q.pop() == 1);
	assert(q.top() == 10);
	assert(q.pop() == 10);
	assert(q.isEmpty() == true);
    Queue p;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    p.push(0);
    p.push(1);
    p.push(2);
    p.push(3);
    assert(p.isequal(q)==true);
    p.pop();
    assert(p.isequal(q)==false);
    p.push(0);
    assert(p.isequal(q)==false);
    q.pop();
    assert(p.isequal(q)==false);
    q.push(0);
    assert(p.isequal(q)==true);
}