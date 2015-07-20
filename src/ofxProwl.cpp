//
//  ofxProwl.cpp
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 19/7/15.
//
//

#include "ofxProwl.h"

ofxProwl::ofxProwl(){

	useHttps = true;
	fm.setVerbose(false);
	ofAddListener(fm.formResponseEvent, this, &ofxProwl::newResponse);

}


void ofxProwl::newResponse(HttpFormResponse &response){
	Response r;
	r.ok = response.ok;
	r.httpStatus = response.status;
	r.status = response.reasonForStatus;
	r.requestID = response.identifier;
	r.content = response.responseBody;
	ofNotifyEvent(eventResponse, r, this);
}


void ofxProwl::sendNotification(const string & apiKey,
								const string & application,	//max 256
								const string & title,			//max 255
								const string & description,	//max 10000
								const string & requestID,
								const string & priority, // [-2 .. 2]
								const string & URL){

	HttpForm f = HttpForm( string(useHttps?"https":"http") + "://api.prowlapp.com/publicapi/add" );
	f.addFormField("apikey", apiKey);
	f.addFormField("event", title);
	f.addFormField("description", description);
	f.addFormField("application", "ofxProwl");
	if(priority.size()) f.addFormField("priority", priority);
	if(URL.size()) f.addFormField("url", URL);

	fm.submitForm(f, false, requestID);

}