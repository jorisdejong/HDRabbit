//
//  Dropdown.cpp
//  HDRabbit
//
//  Created by Joris de Jong on 2/6/13.
//  Copyright (c) 2013 Hybrid Visuals. All rights reserved.
//

#include <iostream>

#include "Dropdown.h"


Dropdown::Dropdown()
{
    tw=190;
    active = false;
    mode=0;
    
    toggleList = new string[2];
    toggleList[0] = "MOMENTARY";
    toggleList[1] = "TOGGLE";
    
    elementList = new string[23];
    elementList[0] = "User Button 1";
    elementList[1] = "User Button 2";
    elementList[2] = "User Button 3";
    elementList[3] = "User Button 4";
    elementList[4] = "User Button 5";
    elementList[5] = "User Button 6";
    elementList[6] = "Rotary 1";
    elementList[7] = "Rotary 2";
    elementList[8] = "Rotary 3";    
    elementList[9] = "Cut Button 1";
    elementList[10] = "Cut Button 2";
    elementList[11] = "Crossfader";
    elementList[12] = "Master Fader";
    elementList[13] = "Center Button 1";
    elementList[14] = "Center Button 2";
    elementList[15] = "Center Button 3";
    elementList[16] = "Effect Button 1";
    elementList[17] = "Effect Button 2";
    elementList[18] = "Effect Button 3";
    elementList[19] = "Effect Button 4";
    elementList[20] = "Effect Button 5";
    elementList[21] = "Effect Button 6";
    elementList[22] = "# DESELECT #";
    
    onOffList = new string[2];
    onOffList[0] = "# OFF #";
    onOffList[1] = "# ON #";
    
    emuList = new string [2];
    emuList[0] = "HDMI";
    emuList[1] = "DVI";
    
    sourceList = new string [3];
    sourceList[0] = "FREEZE IMAGE";
    sourceList[1] = "GO TO BLUE";
    sourceList[2] = "GO TO BLACK";
    
    populateList();
    
    arial.loadFont("ArialBold.ttf", 10);
        
}

void Dropdown::update()
{
    //if we're too long, limit the length and create a slider
    float maxLen = 20;
    if(optionLength>maxLen)
    {
        maxedOptionLength = maxLen;
        sliderLength = (maxLen/optionLength)*maxLen*20;
        sliderWidth = 10;
        

    }
    else
    {
        maxedOptionLength = optionLength;
        sliderLength=0;
        sliderWidth = 0;
    }
    th = maxedOptionLength * 20;
        

    //method for bouncy resize
    if(cw!=tw)
        cw=tw;

    if(ch!=th)
    {
        float cha = ofClamp(th-ch,-2,2);
        chv += cha;
        chv = ofClamp(chv, -20, 20);
        chv *= 0.9;
        if(chv<0.2&&chv>-0.2)
            chv=0;
        ch += chv;
        if(ch<0)
            ch=2;
    }
    
    //limit slider position
    sliderY=ofClamp(sliderY, 0, th-sliderLength);
    
    //calculate offset for showing options based on slider location
    if(sliderLength>0)
        offset = float(sliderY)/((float)th-(float)sliderLength) * (optionLength-maxLen);
    else
        offset = 0 ;
    }


void Dropdown::draw()
{

    ofNoFill();
    ofSetColor(240,146,0,250);
    ofRectRounded(x+tw-cw, y, cw, ch+1,3);
    ofFill();
    ofSetColor(91,88,84,225);
    ofRectRounded(x+tw-cw, y, cw, ch,3);
    
    
    
    for(int i = 0; i < maxedOptionLength; i++)
    {
        if(ofGetMouseX()>x && ofGetMouseX()<x+tw-sliderWidth && ofGetMouseY()>y+i*20 && ofGetMouseY()<y+(i+1)*20 && !slidering)
        {
                ofSetColor(240,146,0,210);
                ofRect(x+tw-cw,y+i*20,cw-sliderWidth,20);
                ofSetColor(255);
                activeOption = i+offset;
        }else
        {
            ofSetColor(180);
        }
        if(13+i*20<ch)
        {
            string displayName;
            string actualName = activeList[i+offset];
            int len = 20;
            if(actualName.length()>len)
                displayName=actualName.substr(0,len)+"...";
            else
                displayName=actualName;
            

            arial.drawString(displayName, x+5, y+13+i*20);
        }
    }
    
    if(sliderLength>0)
    {
        ofSetColor(15,15,15,128);
        ofRect(x+cw-sliderWidth,y,sliderWidth,th);
        ofSetColor(210,210,210,255);
        ofRect(x+cw-sliderWidth,y+sliderY,sliderWidth,sliderLength);
        
    }
}

void Dropdown::set(int x_, int y_)
{
    //reset slider values to 0
    offset = 0;
    sliderY = 0;
    
    x=x_;
    y=y_;
    cw=1;
    ch=1;
    chv = 0;
    
}

string Dropdown::getFunctionName(int i)
{
    return functionList[i];
}

void Dropdown::populateList()
{
    switch(mode)
    {
        
            
        case 0: //button
            optionLength=buttonList.size();
            //availableOption = new int[optionLength];
            break;
        case 1: //rotary
            optionLength=rotaryList.size();
            break;
        case 2: //crossfader
            optionLength=cFaderList.size();
            break;
        case 3: //masterfader
            optionLength=mFaderList.size();
            break;
        case 4: //button toggle
        case 5: //osc toggle
        case 6: //HDCP M toggle
        case 7: //HDCP A toggle
        case 8: //HDCP B toggle
        case 11: 
        case 12: //emulator thingies
            optionLength=2;
            break;
        case 9: //element list
            optionLength = 23;
            break;
        case 10: //resolution list
            optionLength=resList.size();
            break;
        case 13: //source loss list
            optionLength=3;
            break;            
            
    }

    
    activeList = new string[optionLength];
    
    switch(mode)
    {
        case 0:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=buttonList[i];
            }
            break;
            
        case 1:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=rotaryList[i];
            }
            break;
            
        case 2:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=cFaderList[i];
            }
            break;
            
        case 3:
            
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=mFaderList[i];
            }
            break;
            
        case 4:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=toggleList[i];
            }
            break;
            
        case 5:
        case 6:
        case 7:
        case 8:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=onOffList[i];
            }
            break;
            
        case 9:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=elementList[i];
            }
            break;
            
        case 10:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=resList[i];
            }
            break;
            
        case 11:
        case 12:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=emuList[i];
            }
            break;
        case 13:
            for(int i = 0; i < optionLength; i++)
            {
                activeList[i]=sourceList[i];
            }
            break;
    }

    
}