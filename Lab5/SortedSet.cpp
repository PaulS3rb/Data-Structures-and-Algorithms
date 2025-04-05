#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>
using namespace std;
SortedSet::SortedSet(Relation r) {
    firstEmpty=0;
    nrElems=0;
    capacity=10;
    parent=new int[capacity];
    left=new int[capacity];
    right=new int[capacity];
    elements= new TElem [capacity];
    root=0;
    parent[root]=-1;
    for(int i=0;i<capacity;i++)
    {
        parent[i]=-1;
        left[i]=-1;
        right[i]=-1;

    }
    rel=r;
}

void SortedSet::resize() {
    TElem *newelements=new TElem [capacity*2];
    int *newparent=new TElem [capacity*2];
    int *newleft=new TElem [capacity*2];
    int *newright=new TElem [capacity*2];
    for(int i=0;i<capacity;i++)
    {
        newelements[i]=elements[i];
        newparent[i]=parent[i];
        newleft[i]=left[i];
        newright[i]=right[i];
    }

    for(int i=capacity;i<capacity*2;i++)
    {
        newparent[i] = -1;
        newleft[i] = -1;
        newright[i] = -1;
    }
    delete []elements;
    delete []parent;
    delete []left;
    delete []right;
    elements=newelements;
    parent=newparent;
    left=newleft;
    right=newright;
    firstEmpty=capacity;
    capacity=capacity*2;
}


bool SortedSet::add(TComp elem) {


    if(isEmpty())
    {   root=0;
        elements[root]=elem;
        nrElems++;
        firstEmpty=1;
        return true;
    }

    if(size()==capacity)
    {
        resize();
    }


    return addrec(elem,root);

}

bool SortedSet::addrec(TComp elem, int poz) {


    if(elem==elements[poz])
        return false;

    if(rel(elem,elements[poz]))
    {
        if(left[poz]==-1)
        {
            left[poz]=firstEmpty;
            elements[firstEmpty]=elem;
            parent[firstEmpty]=poz;
            nrElems++;
            search_firstEmpty();
            return true;
        }
        else
        {
            return addrec(elem,left[poz]);
        }
    }

    if(!rel(elem,elements[poz]))
    {
        if(right[poz]==-1)
        {
            nrElems++;
            right[poz]=firstEmpty;
            elements[firstEmpty]=elem;
            parent[firstEmpty]=poz;
            search_firstEmpty();
            return true;
        }
        else
        {
            return addrec(elem,right[poz]);
        }
    }

}

void SortedSet::search_firstEmpty() {
    for(int i=0;i<capacity;i++)
    {
        if(parent[i]==-1 && left[i]==-1 && right[i]==-1)
        {
            firstEmpty=i;
            break;
        }
    }
}

bool SortedSet::remove(TComp elem) {
    if(isEmpty())
    {
        return false;
    }
	return removerec(elem,root,"root");
}

bool SortedSet::removerec(TComp elem, int poz, string direction) {

    if(elements[poz]==elem)
    {
        if(left[poz]==-1 && right[poz]==-1)
        {
            //temporary, can compare current poz with firstEmpty for theta(1)
            if(direction=="root")
            {
                root=poz;
            }
            if(direction=="left")
            {
                left[parent[poz]]=-1;
            }
            if(direction=="right")
            {
                right[parent[poz]]=-1;
            }
            remove_value(poz);
            search_firstEmpty();
            nrElems--;
            return true;
        }
        else if(left[poz]==-1)
        {
            if(direction=="root")
            {
                root=right[poz];
            }
            if(direction=="left")
            {
                left[parent[poz]]=right[poz];
            }
            if(direction=="right")
            {
                right[parent[poz]] = right[poz];
            }

            parent[right[poz]]=parent[poz];
            remove_value(poz);
            search_firstEmpty();
            nrElems--;
            return true;
        }
        else if(right[poz]==-1)
        {
            if(direction=="root")
            {
                root=left[poz];
            }
            if(direction=="left")
            {
                left[parent[poz]]=left[poz];
            }
            if(direction=="right")
            {
                right[parent[poz]]=left[poz];
            }
            parent[left[poz]]=parent[poz];
            remove_value(poz);
            search_firstEmpty();
            nrElems--;
            return true;
        }
        else{
            int min_poz = find_minimum(right[poz]);
            if(direction=="root")
            {
                root=min_poz;
            }
            if(direction=="left")
            {
                left[parent[poz]]=min_poz;
            }
            if(direction=="right")
            {
                right[parent[poz]]=min_poz;
            }
            left[min_poz]=left[poz];
            parent[left[poz]]=min_poz;
            if(left[parent[min_poz]==min_poz])
            {
                left[parent[min_poz]]=-1;

            }
            if(right[parent[min_poz]==min_poz])
            {
                right[parent[min_poz]]=-1;
            }

            search_firstEmpty();
            nrElems--;
            return true;
        }
    }
    if(rel(elem,elements[poz]))
    {
        if(left[poz]==-1)
        {
            return false;
        }
        return removerec(elem,left[poz],"left");
    }

    if(!rel(elem,elements[poz]))
    {
        if(right[poz]==-1)
        {
            return false;
        }
        return removerec(elem,right[poz],"right");
    }
}


int SortedSet::find_minimum(int poz) {
    if(left[poz]==-1)
        return poz;
    else
    {
        return find_minimum(left[poz]);
    }
    
}


bool SortedSet::search(TComp elem) const {
    if(isEmpty())
    {
        return false;
    }
    return searchrec(elem,root);

}

bool SortedSet::searchrec(TElem elem, int poz) const {
    if(elem==elements[poz])
    {
        return true;
    }

    if(rel(elem,elements[poz]))
    {
        if(left[poz]==-1)
        {
            return false;
        }
        return searchrec(elem,left[poz]);
    }

    if(!rel(elem,elements[poz]))
    {
        if(right[poz]==-1)
        {
            return false;
        }
        return searchrec(elem,right[poz]);
    }
}


int SortedSet::size() const {
	return nrElems;
}



bool SortedSet::isEmpty() const {
	return size()==0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	delete[] elements;
    delete[] parent;
    delete[] left;
    delete[] right;
}

void SortedSet::remove_value(int poz) {
    parent[poz]=-1;
    left[poz]=-1;
    right[poz]=-1;
}












