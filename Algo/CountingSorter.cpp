//
//  CountingSorter.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/30/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include "CountingSorter.h"

using namespace me;


Sorter::Word *CountingSorter::createSampleSet(size_t length)
{
    Word *result = new Word [ length ];
    for (size_t i = 0; i < length; ++i) {
        result[i] = rand()%1024;
    }
    return result;
}

void CountingSorter::sort(Word *items, size_t length)
{
    size_t c[1024];
    memset(c, 0, sizeof(size_t)*1024);
    
    for (size_t i = 0; i < length; ++i) {
        ++c[items[i]];
    }
    
    Word *result = items;
    for (int i = 0; i < 1024; ++i) {
        for (size_t j = 0; j < c[i]; ++j) {
            *(result++) = i;
        }
    }
}
