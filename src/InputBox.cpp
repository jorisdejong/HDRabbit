//
//  InputBox.cpp
//  HDRabbit
//
//  Created by Joris de Jong on 9/27/12.
//  Copyright (c) 2012 Hybrid Visuals. All rights reserved.
//

#include <iostream>
#include "InputBox.h"
//#include "Dropdown.h"

InputBox::InputBox()
{
    reset();
    arial.loadFont("ArialBold.ttf", 10);
}

void InputBox::reset()
{
    active = false;
    oscAddress="";
    name="";
    type=0;
    masterFunction = 0;
    toggle=0;
    mode = 1;
    toggleRabbit=false;
}

void InputBox::draw()
{   
    ofSetColor(255, 255, 255);
    if(mode == 0 && name != "")
    {
        arial.drawString(name, 775, 189);
        string displaysMasterF;
        int len = 20;
        if(smasterFunction.length()>len)
            displaysMasterF=smasterFunction.substr(0,len)+"...";
        else
            displaysMasterF=smasterFunction;
        arial.drawString(displaysMasterF, 775, 253);

        arial.drawString(stoggleOSC, 775,340);
    
        //shorten oscAddress to box size
        string displayOscAddress;
        len = 25;
        if(oscAddress.length()>len)
            displayOscAddress="..."+oscAddress.substr(oscAddress.length()-(len-3),len-3);
        else
            displayOscAddress=oscAddress;
        
        if (displayOscAddress=="")
        {
            ofSetColor(255, 128);
            displayOscAddress="TYPE";
        }
            
        arial.drawString(displayOscAddress, 775, 359);

        ofSetColor(255, 255);
        switch(type)
        {
            case 0:
                arial.drawString(stoggle, 775, 448);
                break;
            case 1:
            case 2:
            case 3:
                //color toggle option grey
                ofSetColor(35, 35, 35, 200);
                ofRect(605,400,385,70);
                break;                
            default:
                break;
        }
                

       
    }else if (mode == 1)
    {
        arial.drawString(sresolution, 775, 189);
        arial.drawString(semulatorOne, 775, 253);
        arial.drawString(semulatorTwo, 775, 273);
        arial.drawString(shdcpOutput, 775, 340);
        arial.drawString(shdcpInputOne, 775, 360);
        arial.drawString(shdcpInputTwo, 775, 380);
        arial.drawString(ssourceLoss, 775, 448);
    }
    
    else if (name == "")
    {
        //grey out options
        ofFill();
        ofSetColor(35, 35, 35, 200);
        ofRect(600,206,390,261);
    }
    
    if (mode == 0)
    {
        ofSetColor(255);
        arial.drawString(ofToString(curSkin+1), 644, 150);
    }
  

    
    ofSetColor(255,255);
    arial.drawString(IP,815,739);
    arial.drawString("0.9.1",510,38);
    
}








void InputBox::enterOscAddress()
{
            string tempString = ofSystemTextBoxDialog("Enter OSC address.", oscAddress);
            if (tempString=="" && oldOscAddress=="")
            {
                toggleOSC=false;
            }else
            {
                oscAddress=tempString;
                oldOscAddress=tempString;
            }
}

void InputBox::enterIPAddress()
{
    string tempString = ofSystemTextBoxDialog("Enter IP address.", IP);
    if (tempString!="")
        IP=tempString;
}