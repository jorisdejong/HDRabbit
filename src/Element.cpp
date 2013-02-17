//
//  Element.cpp
//  HDRabbit
//
//  Created by Joris de Jong on 9/27/12.
//  Copyright (c) 2012 Hybrid Visuals. All rights reserved.
//

#include <iostream>
#include "Element.h"
#include "testApp.h"

Element::Element(string name_, int type_, int x_, int y_, int w_, int h_)
{
    numberOfSkins = 5;
    oscAddress = new string[numberOfSkins];
    toggle = new bool[numberOfSkins];
    masterFunction = new int[numberOfSkins];
    toggleRabbit = new bool[numberOfSkins];
    toggleOSC = new bool[numberOfSkins];
    
    for (int i = 0; i < numberOfSkins; i++)
    {
        oscAddress[i]= "";
        toggle[i] = false;
        masterFunction[i] = 0;
        toggleOSC[i]=false;
        toggleRabbit[i]=false;
    }
    
    name = name_;
    type = type_;
    
    x=x_;
    y=y_;
    w=w_;
    h=h_;
    
    selected = false;
    
    smallButton.loadImage("SmallButton.jpg");
    bigButton.loadImage("BigButton.jpg");
    cutButton.loadImage("CutButton.jpg");
    masterFader.loadImage("MasterFader.jpg");
    crossFader.loadImage("CrossFader.jpg");
    rotary.loadImage("Rotary.jpg");
    
   
}

Element::~Element()
{
    delete[] oscAddress;
    delete[] toggle;
    delete[] toggleOSC;
    delete[] toggleRabbit;
}

void Element::draw()
{
    if(selected)
    {
        ofSetColor(255,255);
        switch(type)
        {
            case 0:
                if(w==28&&h==26)
                    smallButton.draw(x,y,w,h);
                if(w==60&&h==46)
                    cutButton.draw(x,y,w,h);
                if(w==48&&h==50)
                    bigButton.draw(x,y,w,h);
                break;
            case 1:
                rotary.draw(x,y,w,h);
                break;
            case 2:
                crossFader.draw(x,y,w,h);
                break;
            case 3:
                masterFader.draw(x,y,w,h);
                break;
                
        }
        
        /**
         this just doesn't look pretty
        ofNoFill();
        ofSetLineWidth(2);
        ofSetColor(240,146,0,210);
        ofBezier(x+w,y+h/2,x+w+100,y+h/2,592-100,185,592,185);
         **/
    }

}

bool Element::mouseOver(int mx, int my)
{
    if(mx >= x && mx <= x+w && my >= y && my < y+h)
    {
        return true;
    }
    
    return false;

}