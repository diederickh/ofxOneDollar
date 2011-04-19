#pragma once
#include "ofMain.h"
class SimpleButtonListener {
public:
	virtual void onClick(string sName) = 0;
};

class SimpleButton {
public:
	SimpleButton();
	void mouseMoved(ofMouseEventArgs& rArgs);
	void mousePressed(ofMouseEventArgs& rArgs);
	void mouseReleased(ofMouseEventArgs& rArgs);
	void setup(SimpleButtonListener* pListener, string sName, string sTitle, int nX, int nY);
	void draw();
	
	SimpleButtonListener* listener;
	string name;
	string title;
	bool mouse_over;
	bool mouse_down;
	int x;
	int y;
	int w; 
	int h;
};
