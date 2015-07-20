#include "ofApp.h"
#include "ofxSimpleHttp.h"


void ofApp::setup(){

	ofBackground(22);

	//create a SSL context to be able to use https requests
	ofxSimpleHttp::createSslContext();

	//if you dont want the ofxSimpleHttps dependency, you can also set ofxProwl
	//to use http instead of https like this:
	prowl.setUseHttps(true);
	//https requests wont work unless you create a valid SSL context

	//add a listener to the ofxProwl responses
	ofAddListener(prowl.eventResponse, this, &ofApp::onProwlResponse);
}


void ofApp::exit(){

	//close the context b4 cosing the app or we will crash on exit
	ofxSimpleHttp::destroySslContext();
}


void ofApp::keyPressed(int key){

	//send a Prowl notification
	prowl.sendNotification("332c105bbefe4914c9a14bba4162b9430f1de1b5",
						   "ofxProwl Addons",
						   "Test Notification",
						   "notification description",
						   "myRequestID", //to match request to response - optional
						   "2", //priority [-2 .. 2] - optional
						   "https://github.com/armadillu/ofxProwl" //link - optional
						   );
}


//get Prowl notification responses
void ofApp::onProwlResponse(ofxProwl::Response & r){
	ofLogNotice() << r.content;
}