//
//  QuickSorter.h
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#ifndef __Algo__QuickSorter__
#define __Algo__QuickSorter__

#include "Sorter.h"

namespace me {
    
    class QuickSorter : public Sorter {
    public:
    
        virtual void sort(Word *items, size_t length);
        
    };
    
}

#endif /* defined(__Algo__QuickSorter__) */
