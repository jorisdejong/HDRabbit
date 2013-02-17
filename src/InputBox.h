//
//  InputBox.h
//  HDRabbit
//
//  Created by Joris de Jong on 9/27/12.
//  Copyright (c) 2012 Hybrid Visuals. All rights reserved.
//
#include "ofMain.h"

#ifndef HDRabbit_InputBox_h
#define HDRabbit_InputBox_h

class InputBox
{
public:
    
    //variables
    int preset;
    
    string oscAddress;
    string oldOscAddress; //used to make an accidental uncheck easier

    string smasterFunction;
    string sresolution;
    string semulatorOne;
    string semulatorTwo;
    string shdcpOutput;
    string shdcpInputOne;
    string shdcpInputTwo;
    string ssourceLoss;
    
    string IP;
    
    string stoggleOSC;
    string stoggle;
    
    int masterFunction;
    int resolution;
    int emulatorOne;
    int emulatorTwo;
    int hdcpOutput;
    int hdcpInputOne;
    int hdcpInputTwo;
    int sourceLoss;
    
    string name;
    int type;
    
    bool toggle;
    bool toggleOSC;
    bool toggleRabbit;
    
    bool active;
    int mode;
    
    int x;
    int y;
    int w;
    int h;
    
    int curSkin;
    
     
    //constructor
    InputBox();
    
    

    
    //methods
    void draw();
    void reset();
    
    void enterOscAddress();
    void enterIPAddress();
    
    ofTrueTypeFont arial;
    //no DMX in this version
    //int dmxAddress;
    //string dmxAddressString;
    
};

#endif
