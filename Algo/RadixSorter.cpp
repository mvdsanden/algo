//
//  RadixSorter.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/30/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include "RadixSorter.h"

using namespace me;


void RadixSorter::sort(Word *items, size_t length)
{
    Word *zero = new Word [ length ];
    Word *one = new Word [ length ];

    size_t bits = sizeof(Word) * 8;

    for (size_t i = 0; i < bits; ++i) {
        Word mask = 1 << i;
        
        Word *z = zero;
        Word *o = one;
        
        for (size_t j = 0; j < length; ++j) {
            if (items[j] & mask) {
                *(o++) = items[j];
            } else {
                *(z++) = items[j];
            }
        }
        
        Word *r = items;
        
        for (Word *j = zero; j != z; ++j) {
            *(r++) = *j;
        }
        
        for (Word *j = one; j != o; ++j) {
            *(r++) = *j;
        }
    }
    
    delete [] zero;
    delete [] one;
}
