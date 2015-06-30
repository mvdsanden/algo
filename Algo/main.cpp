//
//  main.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include <iostream>

#include "LibCSorter.h"
#include "MergeSorter.h"
#include "QuickSorter.h"
#include "BinaryHeapSorter.h"
#include "CountingSorter.h"
#include "RadixSorter.h"

int main(int argc, const char * argv[]) {

    size_t length = 21;
    
    std::cout << "LibCSort:\n";
    me::LibCSorter s0; s0.test(length);
    
    std::cout << "MergeSort:\n";
    me::MergeSorter s1; s1.test(length);

    std::cout << "QuickSort:\n";
    me::QuickSorter s2; s2.test(length);

    std::cout << "BinaryHeapSort:\n";
    me::BinaryHeapSorter s3; s3.test(length);

    std::cout << "CountingSort:\n";
    me::CountingSorter s4; s4.test(length);

    std::cout << "RadixSort:\n";
    me::RadixSorter s5; s5.test(length);
    
    s0.bench(10000000, 1);
    s1.bench(10000000, 1);
    s2.bench(10000000, 1);
    s3.bench(10000000, 1);
    s4.bench(10000000, 1);
    s5.bench(10000000, 1);
    
    return 0;
}
