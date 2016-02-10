#include "ofApp.h"
#include "orbits.h"
#include "sun.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

//planet to sun collioion
//planet radius
//make collision thing a function

//initialize vector
std::vector<Planet> planets;
std::vector<Sun> suns;


//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(0,0,0);
    //makes planet (xPos, yPos, xVel, yVel, mass, red, green, blue)
    Planet earth(700,400, 0, 1.5, 10, 255, 0, 0);
    planets.push_back(earth);
    earth.~Planet();
    
    Planet mars(500, 200, 2, 0, 10, 0, 255, 0);
    planets.push_back(mars);
    mars.~Planet();
    
    Planet mars2(400, 100, 2, 0, 10, 0, 0, 255);
    planets.push_back(mars2);
    mars2.~Planet();
    
    Sun sunOne(400, 400, 1000, 20);
    suns.push_back(sunOne);
    sunOne.~Sun();
    
    
    
    
    //ofSetFrameRate(100);

}

//--------------------------------------------------------------
void ofApp::update(){
 
    //accelerate and move planets
    for(int i = 0; i < planets.size(); i++) //This should be a function, send it sun vector and planet vector
    {
        for(int o = 0; o < planets.size(); o++){
            if(o != i){
                if(sqrt(pow(planets[i].xPos-planets[o].xPos,2) + pow(planets[i].yPos - planets[o].yPos,2)) < 10){
                    planets.erase(planets.begin()+i);
                    if(i > o){
                       planets.erase(planets.begin()+o);
                    }
                    else if(i < o){
                        planets.erase(planets.begin()+(o-1));
                    }
                    
                }
            }
        }
        planets[i].acc(planets,i);
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
    for(int i = 0; i < suns.size(); i++)
    {
        //ofSetColor(suns[i].colorR,suns[i].colorG,planets[i].colorB);
        ofDrawCircle(suns[i].xPos, suns[i].yPos, suns[i].radius);
        
    }
    
    
    
    
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
