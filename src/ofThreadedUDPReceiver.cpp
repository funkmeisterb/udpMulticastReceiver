#include "ofThreadedUDPReceiver.h"

#define _OFX_UDP_BUFFERED_WRITES

void ofThreadedUDPReceiver::setup(std::string sAddress, int nPort) {
	bRecording = false;
	bWaitingForFirstMessage = false;
	udpConnection.Create();
	char* pChars = &sAddress[0];
	udpConnection.BindMcast(pChars, nPort);
}

void ofThreadedUDPReceiver::threadedFunction() {
	while (isThreadRunning()) {
		char udpMessage[1000];
		udpConnection.Receive(udpMessage, 1000);
		string message = udpMessage;
		if (!message.empty()) {
			mutexLastMessage.lock();
			sLastMessage = message;
			mutexLastMessage.unlock();
		}
	}
}

const string ofThreadedUDPReceiver::getLastMessage() {
	mutexLastMessage.lock();
	string sCopy = sLastMessage;
	mutexLastMessage.unlock();
	return sCopy;
}