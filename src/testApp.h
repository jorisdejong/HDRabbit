#pragma once

#include "ofMain.h"
#include "Element.h"
#include "InputBox.h"
#include "Knop.h"
#include "Dropdown.h"
#include "ofxNetwork.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    bool debug;
    
    ofFile curList; //filename of the list that is currently in use
    void savePrevious(string filename); //method for saving the last used filename
    
    //csv and data methods
    string getSaveFileName();
    void saveToDisk(string filename);
    void loadFromFile();
    string createCsvString();
    void readCsvString(vector<string> message);
    vector <string> getDataFromFile(string filename);
    void copyElementDataToInterface();
    void copyInterfaceDateToElement();
    void loadFromDevice();
    void saveToDevice();
    void resetToDefault();


    

    //elements that make up the physical interface
    int numberOfElements;
    Element** e;
    
    //interface for changing values
    InputBox *ib;
    Dropdown *d;
    
    //application buttons
    int numberOfButtons;
    Knop** b;
    void buttonAction(int i);
    
    bool system;
    
    //skin vars
    int numberOfSkins;
    int curSkin;
    
    //images
    ofImage layout;

    ofImage LCD;
    ofImage tabSystem;
    ofImage tabSkin;
    ofImage sys;
    ofImage one;
    ofImage two;
    ofImage three;
    ofImage four;
    
    
    
    //tcp stuff
    ofxTCPClient tcpClient;
    string sentMessage; 
    vector <string> receivedMessage;
    bool weConnected;
    
    ofVec2f mousePos;
    bool slidering;

};
