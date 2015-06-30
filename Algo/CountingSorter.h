//
//  CountingSorter.h
//  Algo
//
//  Created by Marten van de Sanden on 6/30/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#ifndef __Algo__CountingSorter__
#define __Algo__CountingSorter__

#include "Sorter.h"

namespace me {
    
    class CountingSorter : public Sorter {
    public:
        
        virtual Word *createSampleSet(size_t length);
        
        virtual void sort(Word *items, size_t length);
        
    };
    
}

#endif /* defined(__Algo__CountingSorter__) */
