#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    bool debug = true;
    ofSetFrameRate(60);
    
    ofSetDataPathRoot("../Resources/");
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
        
    
    numberOfSkins = 5;
    curSkin = 0;
    
    numberOfElements=22;
    e = new Element*[numberOfElements];
    
    //create the elements
    //user buttons
    e[0] = new Element("User Button 1",0,440,79,28,26);  //name, type, x, y, x2, y2
    e[1] = new Element("User Button 2",0,440,111,28,26);
    e[2] = new Element("User Button 3",0,440,159,28,26);
    e[3] = new Element("User Button 4",0,440,191,28,26);
    e[4] = new Element("User Button 5",0,440,239,28,26);
    e[5] = new Element("User Button 6",0,440,271,28,26);
    
    //rotaries
    e[6] = new Element("Rotary 1",1,185,493,48,48);
    e[7] = new Element("Rotary 2",1,272,485,48,48);
    e[8] = new Element("Rotary 3",1,360,493,48,48);
    
    //cut buttons
    e[9] = new Element("Cut Button 1",0,80,637,60,46);
    e[10] = new Element("Cut Button 2",0,451,637,60,46);

    //crossfader
    e[11] = new Element("Cross Fader",2,230,609,131,101);
    
    //masterfader
    e[12] = new Element("Master Fader",3,494,77,51,142);
    
    //keyer buttons
    e[13] = new Element("Center Button 1",0,219,404,48,50);
    e[14] = new Element("Center Button 2",0,272,404,48,50);
    e[15] = new Element("Center Button 3",0,325,404,48,50);
    
    //leftovers
    e[16] = new Element("Effect Button 1",0,52,416,28,26);
    e[17] = new Element("Effect Button 2",0,157,416,28,26);
    e[18] = new Element("Effect Button 3",0,231,350,28,26);
    e[19] = new Element("Effect Button 4",0,336,350,28,26);
    e[20] = new Element("Effect Button 5",0,408,416,28,26);
    e[21] = new Element("Effect Button 6",0,513,416,28,26);
    


    ib = new InputBox();
    d = new Dropdown();
    
    layout.loadImage("Layout.jpg");

    sys.loadImage("TabSystem.jpg");
    one.loadImage("Tab1.jpg");
    two.loadImage("Tab2.jpg");
    three.loadImage("Tab3.jpg");
    four.loadImage("Tab4.jpg");
    tabSkin.loadImage("SkinTabContent.jpg");
    tabSystem.loadImage("SystemTabContent.jpg");
    LCD.loadImage("System.jpg");
    
    //check for previous existing file
    ofBuffer buffer = ofBufferFromFile("previous.txt");
    if(buffer.size()) 
    {
        string tempfile = buffer.getNextLine();
        
        curList.open(tempfile);
        if (!curList.exists()) //if we can't find the previous file, open the default
        {
            tempfile="RabbitDefaults.csv";
            curList.open(tempfile);
            savePrevious(tempfile); //and write it to the file
        }
        
        vector<string> data = getDataFromFile(tempfile); 
        readCsvString(data);
    }
    
    //create the buttons
    numberOfButtons=19;
    b = new Knop*[numberOfButtons];
    
    b[0]=new Knop(770,238,210,20);//open rabbit list or open emulator one list
    b[1]=new Knop(770,174,210,20);//open element list or open resolution list
    b[2]=new Knop(770,437,210,20); //toggle or source loss list
    b[3]=new Knop(677,93,54,21); //skin 1
    b[4]=new Knop(762,93,54,21); //skin 2
    b[5]=new Knop(847,93,54,21); //skin 3
    b[6]=new Knop(922,93,54,21); //skin 4
    b[7]=new Knop(592,93,54,21); //system
    b[8]=new Knop(24,15,64,20); //save local CSV
    b[9]=new Knop(105,15,50,20); //load local CSV
    b[10]=new Knop(945,615,55,20); //save remote CSV
    b[11]=new Knop(885,615,50,20); //load remote CSV
    b[12]=new Knop(170,15,80,20); //reset
    //b[13]=new Knop(780,730,150,10); //IP
    b[13]=new Knop(780,640,150,10); //IP
    b[14]=new Knop(773,348,200,20); //change OSC
    b[15]=new Knop(770,260,210,20);//open emulator two list
    b[16]=new Knop(770,328,210,20);//dhcp output
    b[17]=new Knop(770,348,210,20);//dhcp input 1
    b[18]=new Knop(770,368,210,20);//dhcp input 2
    
    ib->mode=1;    
}
//--------------------------------------------------------------
void testApp::exit()
{
    //clean up
    
    for(int i=0;i<numberOfElements;i++)
    {
        delete e[i];
    }
    delete[] e;
    
    for(int i=0;i<numberOfButtons;i++)
    {
        delete b[i];
    }
    delete[] b;
    
}

//--------------------------------------------------------------
void testApp::update()
{
    ib->curSkin = curSkin;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //draw background
    ofSetColor(255,255,255);
    layout.draw(0,0,1024,768);
    
    for(int i = 0; i < numberOfElements; i++)
    {
        e[i]->draw();
    }
    
    if(ofGetFrameNum()>0) //for some reason i had to wait a bit to draw the interface?
    {
        ofSetColor(255,255);
        if(ib->mode == 0)
        {
            switch(curSkin)
            {
                case 0:
                    tabSkin.draw(596,122,400,476);
                    one.draw(583,88,427,35);
                    break;
                case 1:
                    tabSkin.draw(596,122,400,476);
                    two.draw(583,88,427,35);
                    break;
                case 2:
                    tabSkin.draw(596,122,400,476);
                    three.draw(583,88,427,35);
                    break;
                case 3:
                    tabSkin.draw(596,122,400,476);
                    four.draw(583,88,427,35);
                    break;
                case 4:
                    break;

            }
        }
        
        
        
        if(ib->mode == 1)
        {
            tabSystem.draw(596,122,400,476);
            sys.draw(583,88,427,35);
            LCD.draw(128,80,229,55);
            LCD.draw(128,240,229,55);
        }
        
        
        ofSetColor(255,255);
        ib->draw();
        
        if(d->active)
        {
            
            d->update();
            d->draw();
        }
        

        
        //for debugging
//        for(int i = 0; i < numberOfButtons; i++)
//            b[i]->draw();
        
        b[13]->draw();

        
    }
    


//        int x = ofGetMouseX();
//        int y = ofGetMouseY();
//        ofSetColor(255);
//        ofLine(x,y-5,x,y+5);
//        ofLine(x-5,y,x+5,y);


    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    //debug for mouse positions
       // ofLog(OF_LOG_NOTICE, "%i", x);
       // ofLog(OF_LOG_NOTICE, "%i", y);


}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    if(d->slidering)
    {
        d->sliderY -= mousePos.y - y;
        mousePos.set(x,y);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    //if we pressed a button, and we were in a dropdown menu
    if(d->active && x > d->x && x < d->x + d->cw - d->sliderWidth && y > d->y && y < d->y + d->th)
    {
        //read back the chosen property depending on which menu we were in
        switch(d->mode)
        {
            case 0:
            case 1:
            case 2:
            case 3:
                for (int i = 0; i < d->functionList.size(); i++)
                {
                    if(d->activeList[d->activeOption] == d->functionList[i])
                    {
                        ib->masterFunction = i;
                    }
                    //else
                        //we're fucked and crashing
                }
                ib->smasterFunction=d->functionList[ib->masterFunction];
                break;
            case 4:
                ib->toggle=d->activeOption;
                ib->stoggle=d->toggleList[ib->toggle];
                break;
            case 5:
                ib->toggleOSC=d->activeOption;
                                
                if(ib->toggleOSC)
                {
                    if(ib->oldOscAddress=="")
                    {
                        ib->enterOscAddress();
                        ib->oldOscAddress=ib->oscAddress;
                    }
                    else
                        ib->oscAddress=ib->oldOscAddress;
                }
                else
                    ib->oscAddress="";
                
                ib->stoggleOSC = d->onOffList[ib->toggleOSC];
                break;
            case 9:
                ib->active = true;
                for(int i = 0; i < numberOfElements; i++)
                {
                    if(i == d->activeOption)
                        e[i]->selected = true;
                    else
                        e[i]->selected = false;
                    copyElementDataToInterface();
                }
                if(d->activeOption==22)
                {
                    ib->reset();
                    ib->mode=3;
                }
                break;
            case 10:
                ib->resolution = d->activeOption;
                ib->sresolution = d->resList[d->activeOption];
                break;
            case 11:
                ib->emulatorOne = d->activeOption;
                ib->semulatorOne = d->emuList[d->activeOption]; 
                break;
            case 12:
                ib->emulatorTwo = d->activeOption;
                ib->semulatorTwo = d->emuList[d->activeOption];  
                break;
            case 6:
                ib->hdcpOutput = d->activeOption;
                ib->shdcpOutput = d->onOffList[d->activeOption];
                break;
            case 7:
                ib->hdcpInputOne = d->activeOption;
                ib->shdcpInputOne = d->onOffList[d->activeOption];
                break;
            case 8:
                ib->hdcpInputTwo = d->activeOption;
                ib->shdcpInputTwo = d->onOffList[d->activeOption];
                break;
            case 13:
                ib->sourceLoss = d->activeOption;
                ib->ssourceLoss = d->sourceList[d->activeOption];
                break;
                
                

        }
        
        //copy it back to the element
        copyInterfaceDateToElement();
        d->active = false;
        return; //so we don't press another button underneath
        
    }
    
    //if we were in a dropdown but on a slider
    if(d->active && x > d->x + d->cw - d->sliderWidth && x < d->x + d->cw && y > d->y && y < d->y + d->th)
    {  
        mousePos.set(x,y);
        d->slidering = true;    
        return;
    }
        
    
    //if we were in a dropdown but not over it, just close it
    d->active = false;
    
    //then check if we were over an element
    for(int i = 0; i < numberOfElements; i++)
    {
        if (e[i]->mouseOver(x,y)) //check if we've clicked a controller
        {
            ib->mode = 0;
            ib->active = true;
            e[i]->selected = true; //set the controller to selected
            
            for(int j = 0; j < numberOfElements; j++) //deselect all the other controllers
            {
                if(i!=j)
                {
                    e[j]->selected = false; 
                }
            }
            
            //copy the relevant info into the inputBox
            
            copyElementDataToInterface();
            
            return;
        }  
        
        
        
    }
    
    //then check if we clicked a button
    for(int i = 0; i < numberOfButtons; i++)
    {
        if(b[i]->mouseOver(x,y)) //check if we've clicked a button
        {
            buttonAction(i); //do the action associated with that button
            
            //copy back all the info to the currently selected element
            //todo? maybe I should build in a 'has changed' check, but it's not really necessarry
            copyInterfaceDateToElement();
            
        }
    }
        
            
    //if we haven't pressed anything, deselect and reset the ib, this should only happen on the left side of the interface, otherwise it's a missclick
    if(x < 578)
    {
        ib->reset();
        for(int j = 0; j < numberOfElements; j++) 
        {
            e[j]->selected = false;
            
        }
    }    
    
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

    if(d->active && x > d->x + d->cw - d->sliderWidth && x < d->x + d->cw )
    {
        if((y > d->y + d->sliderY + d->sliderLength && y < d->y + d->th) || (y > d->y && y < d->y + d->sliderY))    
            d->sliderY += y - (d->y +  d->sliderLength);
    }
    d->slidering = false;

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::copyInterfaceDateToElement()
{
    for(int i = 0; i < numberOfElements; i++)
    {
        if(e[i]->selected)
            
        {
            ib->draw(); //force one execution of draw to update the masterfunction before it gets written back
            
            e[i]->oscAddress[curSkin] = ib->oscAddress;
            e[i]->masterFunction[curSkin] = ib->masterFunction;
            e[i]->toggle[curSkin] = ib->toggle;
            e[i]->toggleOSC[curSkin] = ib->toggleOSC;
            
        }
    }
    
}

//--------------------------------------------------------------
void testApp::copyElementDataToInterface()
{
    ib->mode=0;
    ib->active = false;
    for(int i = 0; i < numberOfElements; i++)
    {
        if(e[i]->selected)
        {
            
            ib->oscAddress = e[i]->oscAddress[curSkin];
            ib->oldOscAddress = e[i]->oscAddress[curSkin];
            ib->name = e[i]->name;
            ib->type = e[i]->type;
            ib->masterFunction = e[i]->masterFunction[curSkin];
            ib->smasterFunction = d->functionList[ib->masterFunction];
            ib->toggle = e[i]->toggle[curSkin];
            ib->toggleOSC = e[i]->toggleOSC[curSkin];
            ib->stoggleOSC = d->onOffList[ib->toggleOSC];
            ib->stoggle = d->toggleList[ib->toggle];
            ib->active = true;

    
        }
    }
}

//--------------------------------------------------------------
string testApp::getSaveFileName()
{
    //jump through hoops to create and save a file 
    string previousFile = curList.getFileName();
    ofFileDialogResult saveFileName;
    
    if(previousFile == "OnRabbit.csv" || previousFile == "RabbitDefaults.csv")
        saveFileName = ofSystemSaveDialog("", "");    
    else
         saveFileName = ofSystemSaveDialog(previousFile, "");
    
    return saveFileName.getPath();    
}

//--------------------------------------------------------------
void testApp::saveToDisk(string saveFileName)
{
    if(saveFileName=="")
        return;
    
    ofFile tempFile = saveFileName;
    if(!tempFile.exists())
    {
        tempFile.create();
    }
    
    if(!tempFile.canWrite())
    {
        ofSystemAlertDialog(ofToString(tempFile)+ " can not be written");
        return;
    }
    
    ofBuffer csvData = createCsvString();
    bool fileWritten = ofBufferToFile(saveFileName, csvData);
    if(fileWritten)
        ofLog(OF_LOG_NOTICE, saveFileName+" saved");
    
    curList.open(saveFileName);
    savePrevious(saveFileName);

}

//--------------------------------------------------------------
void testApp::loadFromFile()
{
    ofFileDialogResult loadFileName = ofSystemLoadDialog("", FALSE);
    string filename = loadFileName.getName();
    string filepath = loadFileName.getPath();
    if(filename!="")
    {        
        curList.open(filepath);
        vector<string> data = getDataFromFile(filepath);        
        readCsvString(data);
        copyElementDataToInterface();
        
    }else
    {
        //ofSystemAlertDialog("No file was selected!"); //come on dude, you get this!
    }
    
    savePrevious(loadFileName.getPath());
    
}

//--------------------------------------------------------------
string testApp::createCsvString()
{
    copyInterfaceDateToElement();
    string tempString;
    
    tempString+="1,IP,"+ib->IP+",\n";
    
    for(int i = 1; i< d->functionList.size();i++)  //1 because of the #OFF#
    {
        tempString+=ofToString(i)+",C,"+d->functionAssignList[i-1]+","+d->functionList[i]+",\n";
    }
    for(int i = 0; i < d->resList.size(); i++)
    {
        tempString+=ofToString(i+1)+",R,"+d->resList[i]+","+d->resData[i]+",\n";
    }
    for(int i = 0; i < numberOfElements; i++)
    {
        tempString+=ofToString(i+1);
        tempString+=",B,";
        tempString+=ofToString(e[i]->type);
        tempString+=",";
        for (int j = 0; j < numberOfSkins; j++)
        {
            tempString+=e[i]->oscAddress[j];
            tempString+=",";
        }
        for (int j = 0; j < numberOfSkins; j++)
        {
            tempString+=ofToString(e[i]->masterFunction[j]);
            tempString+=",";
        }
        for (int j = 0; j < numberOfSkins; j++)
        {
            tempString+=ofToString(e[i]->toggle[j]);
            tempString+=",";
        }
        tempString+="\n";
        
    }
    
    //write resolution
    tempString+="1,T,00,41,083,";
    tempString+=ofToString(ofToHex(ib->resolution+1),6,' ');
    tempString+=",\n";
    //write emulator
    tempString+="2,T,10,41,243,"+ofToString(ib->emulatorOne+5)+",\n";
    tempString+="3,T,11,41,243,"+ofToString(ib->emulatorTwo+5)+",\n";
    //write HDCP
    tempString+="4,T,00,41,233,"+ofToString(ib->hdcpOutput)+",\n";
    tempString+="5,T,10,41,238,"+ofToString(ib->hdcpInputOne)+",\n";
    tempString+="6,T,11,41,238,"+ofToString(ib->hdcpInputTwo)+",\n";
    //write source loss
    tempString+="7,T,10,41,0A3,"+ofToString(ib->sourceLoss+1)+",\n";
    tempString+="8,T,11,41,0A3,"+ofToString(ib->sourceLoss+1)+",\n";
    
    return tempString;
}

//--------------------------------------------------------------
void testApp::readCsvString(vector<string> message)
{
    int rLen = 0;
    d->resList.clear();
    d->resData.clear();
    int bLen = 0;
    d->buttonList.clear();
    int tLen = 0;
    int cLen = 0;
    d->functionList.clear();
    d->buttonList.clear();
    d->rotaryList.clear();
    d->cFaderList.clear();
    d->mFaderList.clear();
    
    
    d->functionList.push_back("# OFF #");
    d->buttonList.push_back("# OFF #");
    d->rotaryList.push_back("# OFF #");
    d->mFaderList.push_back("# OFF #");
    d->cFaderList.push_back("# OFF #");

    
    for(int i = 0; i < message.size(); i++)
        
    {
        
        vector<string> tempData = ofSplitString(message[i], ",");
        if(tempData.size()>2)
        {
            //read the IP
            if(tempData[1]=="IP")
                ib->IP=tempData[2];
            
            //read the rabbit function list
            if(tempData[1]=="C")
            {
                cLen++;
                                
                if(tempData.size()>3)
                {
                    d->functionAssignList.push_back(tempData[2]);
                    d->functionList.push_back(tempData[3]);
                    switch(ofToInt(tempData[2]))
                    {
                        
                        case 0:
                            d->buttonList.push_back(tempData[3]);
                            break;
                        case 1:
                            d->rotaryList.push_back(tempData[3]);
                            break;
                        case 2:
                            d->cFaderList.push_back(tempData[3]);
                            break;
                        case 3:
                            d->mFaderList.push_back(tempData[3]);
                    }
                }
                else
                {
                    ofSystemAlertDialog("Uh-oh! Something went wrong during reading of that file.");
                    return;
                }

                
                
            }
            //read the resolution list
            if(tempData[1]=="R")
            {
                rLen++;
                if(tempData.size()>3)
                    d->resList.push_back(tempData[2]);
                else
                {
                    ofSystemAlertDialog("Uh-oh! Something went wrong during reading of that file.");
                    return;
                }
                if(tempData.size()>5)
                {
                    string tempString = tempData[3]+","+tempData[4];
                    d->resData.push_back(tempString);
                }
                else
                {
                    ofSystemAlertDialog("Uh-oh! Something went wrong during reading of that file.");
                    return;
                }
            } 
            
            //read the system functionality
            if(tempData[1]=="T")
            {
                tLen++;
                switch(ofToInt(tempData[0]))
                {
                    case 1:
                        ib->resolution = ofToInt(tempData[5]);
                        if(d->resList.size()>0)
                            ib->sresolution = d->resList[ib->resolution];
                        break;
                    case 2:
                        ib->emulatorOne = ofToInt(tempData[5])-5;
                        ib->semulatorOne = d->emuList[ib->emulatorOne];
                        break;
                    case 3:
                        ib->emulatorTwo = ofToInt(tempData[5])-5;
                        ib->semulatorTwo = d->emuList[ib->emulatorTwo];
                        break;
                    case 4:
                        ib->hdcpOutput = ofToInt(tempData[5]);
                        ib->shdcpOutput = d->onOffList[ib->hdcpOutput];
                        break;
                    case 5:
                        ib->hdcpInputOne = ofToInt(tempData[5]);
                        ib->shdcpInputOne = d->onOffList[ib->hdcpInputOne];
                        break;
                    case 6:
                        ib->hdcpInputTwo = ofToInt(tempData[5]);
                        ib->shdcpInputTwo = d->onOffList[ib->hdcpInputTwo];
                        break;
                    case 7:
                        ib->sourceLoss = ofToInt(tempData[5])-1;
                        ib->ssourceLoss = d->sourceList[ib->sourceLoss];
                        break;
                }
            }
            
            //read in the element data
            if(tempData[1]=="B")
            {
                e[bLen]->type = ofToInt(tempData[2]);
                for (int j = 0; j < numberOfSkins; j++)
                {
                    e[bLen]->oscAddress[j]=tempData[3+j];
                    if(tempData[3+j]=="")
                        e[bLen]->toggleOSC[j] = false;
                    else
                        e[bLen]->toggleOSC[j] = true;
                    e[bLen]->masterFunction[j]=ofToInt(tempData[3+j+numberOfSkins]);
                    e[bLen]->toggle[j]=ofToInt(tempData[3+j+numberOfSkins+numberOfSkins]);
                }
                bLen++;
            }
        }
        
    }    
    copyElementDataToInterface();

}

//--------------------------------------------------------------
void testApp::savePrevious(string filename)
{
    //save into previous.txt
    ofBuffer buffer = filename;
    bool fileWritten = ofBufferToFile("previous.txt", buffer);
    if(fileWritten)
        ofLog(OF_LOG_NOTICE, ofToString(buffer)+" written to previous.txt");
}

//--------------------------------------------------------------
void testApp::loadFromDevice()
{
    //close any previous connections
    tcpClient.close();
    
    //make new connection
    weConnected = tcpClient.setup(ib->IP, 4322);
    tcpClient.setMessageDelimiter("\n");
    tcpClient.setVerbose(true);
    
    //clear the previous messages
    receivedMessage.clear();
    
    if(!tcpClient.isConnected())
    {
        weConnected=false;
        ofSystemAlertDialog("Uh-oh! Could not connect to the Rabbit!!! Make sure it's connected and has enough carrots.");
        return;
    }
    

    while(tcpClient.isConnected())
    {
        string s = tcpClient.receive();
        
        if( s.length() > 0 ){
            receivedMessage.push_back(s);
        }
    }

    readCsvString(receivedMessage);        
        
    tcpClient.close();
    
    saveToDisk("OnRabbit.csv");
    ofSystemAlertDialog("Data retrieved from the Rabbit!");

    
}

//--------------------------------------------------------------
void testApp::saveToDevice()
{
    weConnected = tcpClient.setup(ib->IP, 4321);
    tcpClient.setMessageDelimiter("\n");
    tcpClient.setVerbose(true);
    
    if(!tcpClient.isConnected())
    {
        weConnected=false;
        ofSystemAlertDialog("Uh-oh! Could not connect to the Rabbit!!! Try giving it some carrots.");
        return;
    }
    
    while(tcpClient.isConnected())
    {

        if(tcpClient.send(createCsvString()))
        {
            ofSystemAlertDialog("Yes! Upload successful!!!");
        }else
        {
            ofSystemAlertDialog("Whoops. Upload failed...");
        }
        
        tcpClient.close();
    }
    
    
    tcpClient.close();
    saveToDisk("OnRabbit.csv");

}

//--------------------------------------------------------------
vector <string> testApp::getDataFromFile(string filename)
{
    ofLog(OF_LOG_NOTICE, filename);
    ofBuffer buffer = ofBufferFromFile(filename);
    vector<string> data;
    if(buffer.size()) 
    {
        while(buffer.isLastLine() == false) 
        {
            data.push_back(buffer.getNextLine());
        }
    }
    return data;
}

//--------------------------------------------------------------
void testApp::resetToDefault()
{
    curList.open("RabbitDefaults.csv");
    vector<string> data = getDataFromFile("RabbitDefaults.csv");
    readCsvString(data);
    copyElementDataToInterface();
    
    savePrevious("RabbitDefaults.csv");
}

//--------------------------------------------------------------
void testApp::buttonAction(int i)
{
    int butt = i;
    
    switch(butt)
    {
        case 0:
            d->set(770,242);
            if(ib->mode == 0 && ib->active)
                d->mode = ib->type; //rabbitfunction is populated based on ib->type
            else if(ib-> mode == 1)
                d->mode = 11; //display emulator 1
            else
                break;
            d->populateList();
            d->active=true;  
            break;
            
        case 1: 
            d->set(770,178);
            if(ib->mode == 0 || ib -> mode == 3)
                d->mode = 9; //change active element
            else
                d->mode = 10; //output resolution list

            d->populateList();
            d->active=true; 
            break;
        
        case 2:   
            d->set(770,440);
            if(ib->type==0 && ib->mode == 0 && ib->active)
            {
                d->mode = 4; //toggle
            } else if(ib->mode == 1)
            {
                d->mode = 13; //on source loss
            } else
                break;
            d->populateList();
            d->active=true;
            break;
            
        case 3:
        case 4:
        case 5:
        case 6:
            curSkin = butt-3;
            ib->mode=0;
            copyElementDataToInterface();
            break;
        
        case 7:
            ib->reset();
            ib->mode=1;
            
            for(int i = 0; i < numberOfElements; i++)
            {
                e[i]->selected = false;
            }
            break;
            
        case 8:
            saveToDisk(getSaveFileName());
            break;
            
        case 9:
            loadFromFile();
            break;
            
        case 10:
            saveToDevice(); //nooooooo!
            break;
            
        case 11:
            loadFromDevice();
            break;
            
        case 12:
            resetToDefault();
            break;
            
        //IP                   
        case 13: 
            ib->enterIPAddress();
            break;
        
        //enter OSC bar    
        case 14:
            if(ib->mode == 0 && ib->active)
            {
                ib->enterOscAddress();
                if(ib->oscAddress!="")
                {
                    ib->toggleOSC = true;
                    ib->stoggleOSC = d->onOffList[ib->toggleOSC];
                }
                else
                {
                    ib->toggleOSC = false;
                    ib->stoggleOSC = d->onOffList[ib->toggleOSC];
                }
                    
            
                
            }
            break;
        
        //display emulator two   
        case 15:
            
            if(ib->mode == 1)  
            {
                d->set(770,264);
                d->mode = 12; //display emulator 2
                d->populateList();
                d->active=true; 
            }
            break;
            
        case 16:
            d->set(770,330);
            if(ib->mode == 0 && ib->active)
                d->mode = 5; //toggle osc
            else if(ib->mode == 1)
                d->mode = 6; //output hdcp
            else
                break;
            d->populateList();
            d->active=true;  
            break; 
        case 17:
            if(ib->mode == 1)
            {
                d->set(770,350);
                d->mode = 7; //input 01 hdcp
                d->populateList();
                d->active=true;  
            }
            break; 
        case 18:
            if(ib->mode == 1)
            {
                d->set(770,370);
                d->mode = 8; //input 02 hdcp
                d->populateList();
                d->active=true;  
            }
            break;                
            
        default:
            break;
            
    }

}