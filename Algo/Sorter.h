//
//  Sorter.h
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#ifndef Algo_Sorter_h
#define Algo_Sorter_h

#include <iostream>

namespace me {
    
    class Sorter {
    public:
    
        typedef int Word;
        
        static void printArray(Word *items, size_t length);
        
        virtual Word *createSampleSet(size_t length);
        
        void test(size_t length);
        
        void bench(size_t length, size_t tests);
        
    protected:
        
        virtual void sort(Word *items, size_t length) = 0;
        
        
    };
    
}

#endif
