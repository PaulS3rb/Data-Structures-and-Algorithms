#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
class ValueIterator;
typedef bool(*Relation)(TKey, TKey);

//ADT SortedMultiMap – repräsentiert mithilfe einer SLL mit eindeutigen Schlüsseln (key)
//und sortiert mithilfe einer Relation auf den Schlüsseln (key). Für jeden Schlüssel
//speichert man eine SLL von Werten (value).

struct values{
    TValue value;
    values *next;
};

struct Key{
    TKey key;
    Key* next;
    values *headvalue;
};
class SortedMultiMap {
    friend class SMMIteator;
    friend class ValueIterator;
private:
    Relation rel;
    Key*head;

    void deleteValues(Key *key);
    void addkey(TKey c,TValue v);
    void addvalue(Key* key,TValue v);
    bool removekey(Key* key,TValue v);
    bool removevalue(Key* key, TValue v);

public:

    // constructor
    SortedMultiMap(Relation r);

    //adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);


    //returns the values belonging to a given key
    vector<TValue> search(TKey c) const;


    Key *searchNode(TKey c) const;
    //removes a key value pair from the sorted multimap
    //returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)
    SMMIterator iterator() const;

    ValueIterator Iterator() const;

    void print();

    // destructor
    ~SortedMultiMap();
};
