//
//  LibCSorter.cpp
//  Algo
//
//  Created by Marten van de Sanden on 6/29/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#include "LibCSorter.h"

using namespace me;

void LibCSorter::sort(Word *items, size_t length)
{
    std::sort(items, items+length);
}
