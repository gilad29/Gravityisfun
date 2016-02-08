#include "ofApp.h"
#include "orbits.h"
#include <stdio.h>
#include <math.h>
#include <vector>


//initialize vector
std::vector<Planet> planets;


//--------------------------------------------------------------
void ofApp::setup(){
    
    //makes planet (xPos, yPos, xVel, yVel, mass, red, green, blue)
    Planet earth(400,700, 1.4, 0, 10, 255, 0, 0);
    Planet mars(500, 700, 2, 0, 10, 0, 255, 0);
    Planet mars2(400, 100, 2, 0, 10, 0, 0, 255);
    
    
    
    planets.push_back(earth);
    planets.push_back(mars);
    planets.push_back(mars2);
    
    ofSetFrameRate(100);

}

//--------------------------------------------------------------
void ofApp::update(){
 
    //accelerate and move planets
    for(int i = 0; i < planets.size(); i++)
    {
        planets[i].acc();
        planets[i].move();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw framerate
    ofDrawBitmapString(ofGetFrameRate(),50,10);
    //draw planets
    for(int i = 0; i < planets.size(); i++)
    {
        ofSetColor(planets[i].colorR,planets[i].colorG,planets[i].colorB);
        ofDrawCircle(planets[i].xPos, planets[i].yPos, 5);
        
    }
    
    //draw Sun
    ofSetColor(255,255,0);
    ofDrawCircle(400, 400, 20);
    
    
    
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
