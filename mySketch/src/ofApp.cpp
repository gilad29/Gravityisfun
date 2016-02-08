#include "ofApp.h"
#include <math.h>

double xPos;
double yPos;
double xVel;
double yVel;

double xAcc;
double yAcc;
double mass;

ofPolyline line;


vector<float> pointsX;
vector<float> pointsY;
vector<ofPoint> points;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(100);
    xPos = 400;
    yPos = 700;
    
    xVel = 1.3;
    yVel = 0;
    //mass = pow(sqrt(pow(xVel,2)+pow(yVel,2)),2)/(yPos - 400);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    xAcc = sin(atan2((400-xPos),(400-yPos))) * 2000/(pow(400-xPos,2) + pow(400 - yPos,2));
    yAcc = cos(atan2((400-xPos),(400-yPos))) * 2000/(pow(400-xPos,2) + pow(400 - yPos,2));
    
    xVel += xAcc;
    yVel += yAcc;
    
    xPos += xVel;
    yPos += yVel;
    
    line.addVertex(xPos, yPos);
    //pointsX.push_back(xPos);
    //pointsY.push_back(yPos);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString(ofGetFrameRate(),50,10);
    ofDrawBitmapString(yAcc, 50, 50);
    ofDrawBitmapString(xAcc, 50, 100);
    
    ofSetColor(255,255,0);
    ofDrawCircle(400, 400, 20);
    
    ofSetColor(0,0,255);
    ofDrawCircle(xPos, yPos, 5);
    line.draw();
    
    
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
