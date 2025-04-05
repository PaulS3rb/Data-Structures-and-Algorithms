#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

/**
 * complexity:Theta(1)
 */
SortedMultiMap::SortedMultiMap(Relation r) {
    rel=r;
    head= nullptr;
}

/**
 * best case:Theta(1):add a key on the first position or add a value on the second position of the first key
 * worst case:Theta(smm):add a value to the last key
 * average case:O(smm)
 */
void SortedMultiMap::add(TKey c, TValue v) {
    Key *aux= searchNode(c);

    if(aux!= nullptr)
    {
        addvalue(aux,v);
    }
    else
    {
        addkey(c,v);
    }
}

/**
 * best case: Theta(1): we add a key on the first position
 * worst case: Theta(n): we add a key on the last position
 * average case:O(n)
 */
void SortedMultiMap::addkey(TKey c, TValue v) {
    if(head== nullptr)
        head=new Key(c, nullptr,new values{v, nullptr});
    else {
        Key *aux = head;
        if (rel(c, aux->key))//c is smaller than all the elements of the key list
        {
            Key *newkey = new Key{c, head, new values{v, nullptr}};
            head = newkey;
        } else {
            while (aux->next != nullptr && rel(aux->next->key, c)) {
                aux = aux->next;
            }
            Key *newkey = new Key{c, aux->next, new values{v, nullptr}};
            aux->next = newkey;
        }
    }

}

/**
 * best case:Theta(1):we add a value to the first key on the second position
 * worst case:Theta(smm):we add a value to the last key
 * average case:O(smm)
 */
void SortedMultiMap::addvalue(Key* key,TValue v) {

    values *valuenode=key->headvalue;
    while(valuenode->next!= nullptr)
    {
        valuenode=valuenode->next;
    }
    auto *newvalue=new values{v,valuenode->next};
    valuenode->next=newvalue;

}

/**
 * best case:Theta(1):the value of the key we are searching for is lower than the value of the first key
 * worst case:Theta(n):
 * average case:O(n)
 */
vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue>valuesvector;

    Key *aux= searchNode(c);
    if(aux== nullptr)
    {
        return valuesvector;
    }

    values *valuenode=aux->headvalue;
    while(valuenode!= nullptr)
    {
        valuesvector.push_back(valuenode->value);
        valuenode=valuenode->next;
    }

    return valuesvector;
}


/**
 * best case:Theta(1) :multimap is empty or element has a lower value than all the key elements
 * worst case:Theta(n) :element is bigger than all the elements in the array
 * average case:O(n)
 */
Key *SortedMultiMap::searchNode(TKey c) const{
    Key *aux=head;

    while(aux!=nullptr && rel(aux->key,c))
    {
        if(aux->key==c)
            return aux;
        else
            aux=aux->next;
    }

    return nullptr;
}

/**
 * best case:Theta(1):we remove first node or the first value of the first node or the node we are searching for has a lower value
 * than the value of the first node
 * worst case:Theta(smm):we need to remove from the last node the last value
 * average case:O(smm)
 */
bool SortedMultiMap::remove(TKey c, TValue v) {

    Key*aux= searchNode(c);
    if(aux== nullptr)
        return false;

    if(search(c).size()==1)
    {
        if(removekey(aux,v))
            return true;
    }
    else
    {

        if(removevalue(aux,v))
            return true;
    }
    return false;

}
/**
 * best case:Theta(1):value isn't in the values list or we need to remove the first key
 * worst case:Theta(n):we need to remove the last key
 * average case:O(n)
 */
bool SortedMultiMap::removekey(Key *key,TValue v) {
    values *valuenode=key->headvalue;
    if(valuenode->value==v) {
        key->headvalue->next = nullptr;
        delete valuenode;
        Key *prev = nullptr;
        Key *curr = head;
        while (curr != nullptr)
        {
            if(curr->key==key->key)
                break;
            prev=curr;
            curr=curr->next;
        }
        if(curr== nullptr)
            return false;

        if(prev==nullptr)
            head=curr->next;
        else
            prev->next=curr->next;

        delete curr;
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * best case:Theta(1):first value of a key is removed
 * worst case: Theta(smm):last value of key is removed
 * average case: O(smm)
 */
bool SortedMultiMap::removevalue(Key *key, TValue v) {
    values *prev= nullptr;
    values *curr=key->headvalue;
    while(curr!= nullptr)
    {
        if(curr->value==v)
            break;
        prev=curr;
        curr=curr->next;
    }
    if(curr== nullptr)
        return false;

    if(prev== nullptr)
        key->headvalue=curr->next;
    else
        prev->next=curr->next;
    delete curr;
    return true;

}


//complexity:Theta(smm)
int SortedMultiMap::size() const {
    Key *aux=head;
    int ct=0;

    while(aux!= nullptr && aux->headvalue!= nullptr)
    {
        values *valuenode = aux->headvalue;

        while (valuenode != nullptr) {
            ct++;
            valuenode = valuenode->next;
        }
        aux=aux->next;
    }
    return ct;
}

/**
 * complexity:Theta(1)
 */
bool SortedMultiMap::isEmpty() const {
    return head== nullptr;
}
/**
 * complexity:Theta(1)
 */
SMMIterator SortedMultiMap::iterator() const {
    return SMMIterator(*this);
}

ValueIterator SortedMultiMap::Iterator() const {
    return ValueIterator(*this);
}

void SortedMultiMap::print() {


    if(head== nullptr) {
        cout << "Multimap is empty";
        return;
    }
    Key*aux=head;
    while(aux!= nullptr)
    {
        values*valuenode=aux->headvalue;
        cout<<aux->key<<":";
        while(valuenode!= nullptr)
        {
            cout<<valuenode->value<<" ";
            valuenode=valuenode->next;
        }
        cout<<"\n";
        aux=aux->next;
    }

}

/**
 * Complexity:Theta(smm)
 */
SortedMultiMap::~SortedMultiMap() {
    while(head!= nullptr)
    {
        Key *aux=head;
        head=head->next;
        deleteValues(aux);
        delete aux;
    }
}

/**
 * Complexity:Theta(smm)
 */
void SortedMultiMap::deleteValues(Key *key) {
    values *valuenode=key->headvalue;
    while(valuenode!= nullptr)
    {
        values *aux=valuenode;
        valuenode=valuenode->next;
        delete aux;
    }
}









