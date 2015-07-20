#pragma once

#include "ofMain.h"
#include "ofxProwl.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update(){};
		void draw(){};
		void exit();
		
		void keyPressed(int key);

		ofxProwl prowl;

	void onProwlResponse(ofxProwl::Response & r);
};
