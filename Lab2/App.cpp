#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>
#include <assert.h>

bool relation2(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}


int main(){

    testAll();
    testAllExtended();
    //testnewiterator();
    std::cout<<"Finished SMM Tests!"<<std::endl;
    system("pause");
}
