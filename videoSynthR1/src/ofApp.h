#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void stripePattern();
		void exit();
		
		ofxGuiGroup primGroup;		//declares a newgroup of controls
		ofxFloatSlider shiftY, rotate;
		ofxVec2Slider size;
		ofxColorSlider color;
		ofxToggle filled, type;
		
		ofxGuiGroup globalGroup;
		ofxFloatSlider Scale;
		ofxFloatSlider Rotate;
		ofxFloatSlider Background;
		
		ofxPanel gui;
		ofxIntSlider countx;		
		ofxFloatSlider stepx;
		ofxFloatSlider twistx;
		
		ofxIntSlider countY;
		ofxFloatSlider stepY, twistY, pinchY;
		
		bool showGui;
		
		void matrixPattern();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
