//
//  MergeSorter.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include "MergeSorter.h"

using namespace me;

void merge(Sorter::Word *result, Sorter::Word *l0, Sorter::Word *l1, Sorter::Word *r0, Sorter::Word *r1)
{
    while ((l0 != l1) || (r0 != r1)) {
        
        if (l0 == l1) {
            *result = *r0; ++r0;
        } else if (r0 == r1) {
            *result = *l0; ++l0;
        } else if (*l0 < *r0) {
            *result = *l0; ++l0;
        } else {
            *result = *r0; ++r0;
        }
        
        ++result;
        
    }
}

void MergeSorter::sort(Word *items, size_t length)
{

    if (length > 1) {

        size_t h = length / 2;
        
        Word *l = new Word[h];
        Word *r = new Word[length-h];
        
        memcpy(l, items, sizeof(Word)*h);
        memcpy(r, items+h, sizeof(Word)*(length-h));
        
        sort(l, h);
        sort(r, length-h);
        
        merge(items, l, l+h, r, r+(length-h));
        
        delete [] l;
        delete [] r;
        
    }
    
}
