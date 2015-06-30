//
//  Sorter.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include <chrono>

#include "Sorter.h"

using namespace me;

void Sorter::printArray(Word *items, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        std::cout << i << "\t:" << items[i] << "\n";
    }
    std::cout << std::endl;
}

Sorter::Word *Sorter::createSampleSet(size_t length)
{
    Word *result = new Word [ length ];
    for (size_t i = 0; i < length; ++i) {
        result[i] = rand();
    }
    return result;
}

void Sorter::test(size_t length)
{
    Word *testSet = createSampleSet(length);
    
    sort(testSet, length);
    
    printArray(testSet, length);
    
    for (size_t i = 1; i < length; ++i) {
        if (testSet[i-1] > testSet[i]) {
            std::cerr << "Element " << i-1 << " is larger than element " << i << ".\n";
            return;
        }
    }
    
    delete [] testSet;
}

void Sorter::bench(size_t length, size_t tests)
{
    auto t0 = std::chrono::steady_clock::now();
    
    for (size_t i = 0; i < tests; ++i) {
        Word *testSet = createSampleSet(length);
        
        sort(testSet, length);
    }

    auto t1 = std::chrono::steady_clock::now();
    
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
    
    std::cout << "Bench: " << tests << " sorts of N=" << length << " in " << dt.count() << "ms." << std::endl;
}
