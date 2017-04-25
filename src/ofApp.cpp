#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	loadSettings();
	threadUDP.setup(settings.sAddress, settings.nPort);
	threadUDP.startThread();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::black);
	ofSetColor(ofColor::yellow);
	ofDrawBitmapString("UDP multicast receiver, on port " + ofToString(settings.nPort), 20, 20);
	ofDrawBitmapString("Last UDP multicast message:", 20, 60);
	ofDrawBitmapString(threadUDP.getLastMessage(), 20, 80);
}

//--------------------------------------------------------------
void ofApp::exit() {
	saveSettings();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::loadSettings() {
	ofxXmlSettings s;
	s.loadFile("settings.xml");
	settings.nPort = s.getValue("settings:port", 13003);
	settings.sAddress = s.getValue("settings:address", "224.1.1.1");
}

void ofApp::saveSettings() {
	ofxXmlSettings s;
	s.setValue("settings:port", settings.nPort);
	s.setValue("settings:address", settings.sAddress);
	s.saveFile("settings.xml"); //puts settings.xml file in the bin/data folder
}
