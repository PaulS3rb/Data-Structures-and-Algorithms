#pragma once
#include "SortedMultiMap.h"
class ValueIterator {
    friend class SortedMultiMap;
private:
    const Key& key;
    ValueIterator(const Key &k);
    values *valuecurrent;


public:
    void first();
    void next();
    bool valid() const;
    TValue getCurrent() const;
};



