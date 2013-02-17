//
//  Element.h
//  HDRabbit
//
//  Created by Joris de Jong on 9/27/12.
//  Copyright (c) 2012 Hybrid Visuals. All rights reserved.
//

#include "ofMain.h"

#ifndef HDRabbit_element_h
#define HDRabbit_element_h


class Element
{
public:
    
    //variables
    string name;
    string *oscAddress;
    int type;
    
    bool *toggle;
    bool *toggleOSC;
    bool *toggleRabbit;
    
    int x,y,w,h;
    
    bool selected;
    
    int *masterFunction;
    
    int numberOfSkins;
    
    ofImage smallButton;
    ofImage bigButton;
    ofImage crossFader;
    ofImage masterFader;
    ofImage cutButton;
    ofImage rotary;
    
    
    
    //constructor
    Element(string name_, int type_, int x_, int y_, int w_, int h_);
    
    //destructor
    ~Element();

    
    //methods
    void draw();
    bool mouseOver(int mx, int my);
    
    
};
#endif
