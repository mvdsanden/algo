//
//  BinaryHeapSorter.h
//  Algo
//
//  Created by Marten van de Sanden on 6/30/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#ifndef __Algo__BinaryHeapSorter__
#define __Algo__BinaryHeapSorter__

#include "Sorter.h"

namespace me {
    
    class BinaryHeapSorter : public Sorter {
    public:
    
        virtual void sort(Word *items, size_t length);
        
    };
    
}

#endif /* defined(__Algo__BinaryHeapSorter__) */
