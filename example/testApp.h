#pragma once
#include "ofMain.h"
#include "SimpleButton.h"
#include "ofxOneDollar.h"

class testApp : public ofBaseApp, public SimpleButtonListener{

	public:
		void setup();
		void update();
		void draw();
		void onClick(string sName);
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void createNewGesture();
		void showMessage(string sMessage, int nDelay = 2000);
		
		SimpleButton save_to_file;		
		SimpleButton clear_line;
		SimpleButton create_gesture;
		SimpleButton find;
		SimpleButton load_from_file;
		vector<ofVec2f> line;
		vector<ofVec2f> found_gesture;
		ofxOneDollar dollar;
		ofxGesture* gesture;
		int num_created_gestures;
		
		int mode;
		string message;
		int hide_message_on;
};
