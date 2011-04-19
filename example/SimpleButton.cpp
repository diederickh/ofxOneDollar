#include "SimpleButton.h"
SimpleButton::SimpleButton() 
:mouse_over(false)
,mouse_down(false)
,x(0)
,y(0)
,w(230)
,h(30)
,listener(NULL)
{
}

void SimpleButton::setup(SimpleButtonListener* pListener, string sName, string sTitle,int nX, int nY) {
	x = nX;
	y = nY;
	name = sName;
	title = sTitle;
	listener = pListener;
	ofAddListener(ofEvents.mouseMoved,		this, &SimpleButton::mouseMoved);
	ofAddListener(ofEvents.mousePressed,	this, &SimpleButton::mousePressed);
	ofAddListener(ofEvents.mouseReleased,	this, &SimpleButton::mouseReleased);
}


void SimpleButton::mouseMoved(ofMouseEventArgs& rArgs) {
	if( (rArgs.x >= x) && (rArgs.x < x+w) && (rArgs.y >= y) && (rArgs.y <= (y+h)) ) {
		mouse_over = true;
	} 
	else {
		mouse_over = false;
	}
}

void SimpleButton::mousePressed(ofMouseEventArgs& rArgs) {
	if( (rArgs.x >= x) && (rArgs.x < x+w) && (rArgs.y >= y) && (rArgs.y <= (y+h)) ) {
		mouse_down = true;
	}
	else {
		mouse_down = false;
	}
}

void SimpleButton::mouseReleased(ofMouseEventArgs& rArgs) {
	if( (rArgs.x >= x) && (rArgs.x < x+w) && (rArgs.y >= y) && (rArgs.y <= (y+h)) ) {
		listener->onClick(name);		
	}
	mouse_down = false;	
}

void SimpleButton::draw() {
	if(mouse_over && !mouse_down) {
		glColor3f(1.0, 1.0, 0.0);
	}
	else if(mouse_down) {
		glColor3f(0.0, 0.5, 0.3);
	}
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	ofRect(x, y, w, h);
	glColor3f(0,0,0);
	ofDrawBitmapString(title, x+15,y+18);
	glColor3f(1,1,1);
}


