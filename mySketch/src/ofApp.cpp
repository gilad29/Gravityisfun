#include "ofApp.h"
#include "orbits.h"
#include "sun.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

//initialize vector
std::vector<Planet> planets;
std::vector<Sun> suns;
std::vector<int> indexes;

vector<int> collisionCheck(vector<Planet> planets, vector<Sun> suns, int index);


//--------------------------------------------------------------
void ofApp::setup(){
    
     ofBackground(0,0,0);
    
    //makes planet (xPos, yPos, xVel, yVel, mass, red, green, blue)
    Planet earth(700,400, 0, 1.5, 10, 5, 255, 0, 0);
    planets.push_back(earth);
    earth.~Planet();
    
    Planet mars(500, 200, 2, 0, 10, 5, 0, 255, 0);
    planets.push_back(mars);
    mars.~Planet();
    
    Planet mars2(400, 100, 2, 0, 10, 5, 0, 0, 255);
    planets.push_back(mars2);
    mars2.~Planet();
    
    //make sun (x, y, mass, radius)
    Sun sunOne(400, 400, 1000, 20);
    suns.push_back(sunOne);
    sunOne.~Sun();

}

//--------------------------------------------------------------
void ofApp::update(){
 
    //accelerate and move planets
    for(int i = 0; i < planets.size(); i++) //This should be a function, send it sun vector and planet vector
    {
        indexes = collisionCheck(planets, suns, i);
        if(indexes.size() != 0){
            for(int z = 0; z < indexes.size(); z++){
                planets.erase(planets.begin()+(indexes[z]));
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
        ofDrawCircle(planets[i].xPos, planets[i].yPos, planets[i].radius);
        
    }
    
    //draw Suns
    ofSetColor(255,255,0);
    for(int i = 0; i < suns.size(); i++)
    {
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

vector<int> collisionCheck(vector<Planet> planets, vector<Sun> suns, int index){
   
    
    vector<int> spots;
    bool destroyed = false;
    
    for(int o = 0; o < planets.size(); o++){
        if(o != index){
            if(sqrt(pow(planets[index].xPos-planets[o].xPos,2) + pow(planets[index].yPos - planets[o].yPos,2)
                ) < (planets[index].radius + planets[o].radius)){
               
                //planets.erase(planets.begin()+index);
                spots.push_back(index);
                destroyed = true;
                if(index > o){
                    //planets.erase(planets.begin()+o);
                    spots.push_back(o);
                }
                else if(index < o){
                    //planets.erase(planets.begin()+(o-1));
                    spots.push_back((o-1));
                }
            }
        }
    }
    for(int o = 0; o < suns.size(); o++){
        if(sqrt(pow(planets[index].xPos-suns[o].xPos,2) + pow(planets[index].yPos - suns[o].yPos,2)) < (planets[index].radius + suns[o].radius)){
                //planets.erase(planets.begin()+index);
                if(destroyed== false){
                    spots.push_back(index);
                }
            }
        }
    return spots;

}
