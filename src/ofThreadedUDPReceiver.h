#pragma once
#include "ofThread.h"
#include "ofxUDPManager.h"
#include "ofUtils.h"

class ofThreadedUDPReceiver : public ofThread
{
public:
	void setup(std::string sAddress, int nPort);
	const ofxUDPManager& getUDPConnection() const { return udpConnection; }
	const string getLastMessage();

private:
	void threadedFunction();

	ofxUDPManager			udpConnection;
	bool					bRecording;
	bool					bWaitingForFirstMessage;
	ofFile					fileRecording;
	uint64_t				timeStartRecordingMicroSeconds;
	uint64_t				timeFirstMessageReceivedMicroSeconds;

	ofMutex					mutexLastMessage;
	string					sLastMessage;
};

