//
//  QuickSorter.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include "QuickSorter.h"

using namespace me;

size_t partition(Sorter::Word *items, size_t length, Sorter::Word pivot)
{
    size_t i = 0;
    
    for (size_t j = 0; j < length; ++j) {
        if (items[j] <= pivot) {
            std::swap(items[i], items[j]);
            ++i;
        }
    }
    
    return i;
    
    /*
    size_t i = 0;
    
    //std::cout << "Pivot value: " << pivot << ".\n";
    
    while (i < length) {
        if (items[i] <= pivot) {
            ++i;
            std::swap(items[i], items[--length]);
        } else {
            ++i;
        }
    }
    
    return i;
     */
}

void QuickSorter::sort(Word *items, size_t length)
{
    //std::cout << "Length: " << length << ".\n";
    
    if (length <= 1) {
        return;
    }
    
    size_t piv = rand() % length;
    
    //std::cout << "Pivot index: " << piv << ".\n";
    
    std::swap(items[piv], items[length-1]);
    
    size_t p = partition(items, length-1, items[length-1]);
    
    //std::cout << "P=" << p << ".\n";
    
    //std::cout << "Pivot: " << p << " of " << length << ".\n";
    
    std::swap(items[p], items[length-1]);
    
    sort(items, p);
    sort(items + p + 1, length - p - 1);
}
