//
//  Dropdown.h
//  HDRabbit
//
//  Created by Joris de Jong on 2/6/13.
//  Copyright (c) 2013 Hybrid Visuals. All rights reserved.
//

#include "ofMain.h"

#ifndef HDRabbit_Dropdown_h
#define HDRabbit_Dropdown_h

class Dropdown
{
public:
    //vars
    int x;
    int y;
    float cw;
    float ch;
    float cwv;
    float chv;
    int tw;
    int th;
    
    bool active;
    
    int mode;
    
    vector <string> functionList;
    vector <string> functionAssignList;
    vector <string> buttonList;
    vector <string> rotaryList;
    vector <string> cFaderList;
    vector <string> mFaderList;
    vector <string> resList;
    vector <string> resData;
    string *toggleList;
    string *elementList;
    string *onOffList;
    string *emuList;
    string *sourceList;
    
    int *availableOption;
    int optionLength;
    string *activeList;
    int activeOption;
        
    int sliderLength;
    int sliderWidth;
    int sliderY;
    int maxedOptionLength;
    bool slidering;
    int offset;
    
    //constructor
    Dropdown();

    //meth
    void update();
    void draw();
    void set(int x_, int y_);
    void populateList();
    string getFunctionName(int i);
    
    ofTrueTypeFont arial;
};


#endif
