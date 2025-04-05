#include "Bag.h"

class BagIterator
{
	//DO NOT CHANGE THIS PART
	friend class Bag;
	
private:
	const Bag& bag;
	//TODO  - Representation


	BagIterator(const Bag& c);
public:
    int index;
    int size;
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};
