//
//  BinaryHeapSorter.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/30/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include "BinaryHeapSorter.h"


using namespace me;

size_t left(size_t index)
{
    return index*2;
}

size_t right(size_t index)
{
    return index*2+1;
}

void maxHeapify(Sorter::Word *items, size_t length, size_t index)
{
    size_t l = left(index);
    size_t r = right(index);
    
    size_t largest = index;
    
    if (l < length && items[l] > items[index]) {
        largest = l;
    }
    
    if (r < length && items[r] > items[largest]) {
        largest = r;
    }
    
    if (largest != index) {
        std::swap(items[index], items[largest]);
        maxHeapify(items, length, largest);
    }
}

void buildMaxHeap(Sorter::Word *items, size_t length)
{
    for (int i = static_cast<int>(length/2); i >= 0; --i) {
        maxHeapify(items, length, i);
    }
    
}

void BinaryHeapSorter::sort(Word *items, size_t length)
{
    buildMaxHeap(items, length);
    
    for (size_t i = length-1; i > 0; --i) {
        std::swap(items[i], items[0]);
        maxHeapify(items, i, 0);
    }
}
