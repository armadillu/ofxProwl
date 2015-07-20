//
//  ofxProwl.h
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 19/7/15.
//
//

#ifndef __ofxProwl__ofxProwl__
#define __ofxProwl__ofxProwl__

#include "ofMain.h"
#include "HttpFormManager.h"

class ofxProwl{

public:

	struct Response{
		string content;
		string status;
		string requestID;
		bool ok;
		int httpStatus;
	};

	ofxProwl();

	//http://www.prowlapp.com/api.php#add
	void sendNotification(const string & apiKey,
						  const string & application,	//max 256
						  const string & title,			//max 255
						  const string & description,	//max 10000
						  const string & requestID, //will be given back in the response
						  const string & priority = "", // [-2 .. 2]
						  const string & URL = "" //notification will show as a link
						  );

	void setUseHttps(bool https){useHttps = https;}


	ofEvent<Response> eventResponse;

protected:

	void newResponse(HttpFormResponse &response);

	HttpFormManager fm;
	bool useHttps;
};

#endif /* defined(__ofxProwl__ofxProwl__) */
