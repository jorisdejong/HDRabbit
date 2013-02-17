//
//  Button.cpp
//  HDRabbit
//
//  Created by Joris de Jong on 12/19/12.
//  Copyright (c) 2012 Hybrid Visuals. All rights reserved.
//

#include <iostream>
#include "Knop.h"

void Knop::draw()
{
    ofSetColor(255,255,0,128);
    ofRect(x, y, w, h);
}

bool Knop::mouseOver(int mx, int my)
{
    if(mx >= x && mx <= x+w && my >= y && my < y + h)
    {
        return true;
    }else
    {
        return false;
    }

}

