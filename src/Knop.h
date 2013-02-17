//
//  Button.h
//  HDRabbit
//
//  Created by Joris de Jong on 12/19/12.
//  Copyright (c) 2012 Hybrid Visuals. All rights reserved.
//

#include "ofMain.h"

#ifndef HDRabbit_Button_h
#define HDRabbit_Button_h

class Knop
{
public:
    
    //vars
    int x;
    int y;
    int w;
    int h;
    
    //constructor
    Knop(int x_, int y_, int w_, int h_)
    {
        x=x_;
        y=y_;
        w=w_;
        h=h_;
        
    }
    
    //meth
    void draw();
    bool mouseOver(int x, int y);
    
};


#endif
