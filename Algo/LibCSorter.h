//
//  LibCSorter.h
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#ifndef __Algo__LibCSorter__
#define __Algo__LibCSorter__

#include "Sorter.h"

namespace me {
    
    class LibCSorter : public Sorter {
    public:
    
        virtual void sort(Word *items, size_t length);
        
    };
    
}

#endif /* defined(__Algo__LibCSorter__) */
