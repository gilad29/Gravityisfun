//
//  orbits.cpp
//  mySketch
//
//  Created by Mitchell on 2/5/16.
//
//

#include "orbits.h"
#include "ofMain.h"
#include "ofApp.h"

//implementations of class functions and constructor

void Planet::acc(vector<Planet> planets, int num){
    
    for(int i = 0; i < planets.size(); i++ ){
        
        if(i != num){
            xAcc = sin(atan2((planets[i].xPos-xPos),(planets[i].yPos-yPos))) * 50/(pow(planets[i].xPos-xPos,2) + pow(planets[i].yPos - yPos,2));
            yAcc = cos(atan2((planets[i].xPos-xPos),(planets[i].yPos-yPos))) * 50/(pow(planets[i].xPos-xPos,2) + pow(planets[i].yPos - yPos,2));
            
            xVel += xAcc;
            yVel += yAcc;
        }
        
    }
    
    //2000 should be G*mass1*mass2  //400 is sun location so it needs to be other object
    xAcc = sin(atan2((400-xPos),(400-yPos))) * 2000/(pow(400-xPos,2) + pow(400 - yPos,2));
    yAcc = cos(atan2((400-xPos),(400-yPos))) * 2000/(pow(400-xPos,2) + pow(400 - yPos,2));
    
    xVel += xAcc;
    yVel += yAcc;
    
}

void Planet::move(){
    xPos += xVel;
    yPos += yVel;
}


Planet::~Planet(){
    
}


Planet::Planet(double xPosition, double yPosition, double xVelocity, double yVelocity, double planetMass, double planetRadius, int colorRed, int colorGreen, int colorBlue){
    
    xPos = xPosition;
    yPos = yPosition;
    xVel = xVelocity;
    yVel = yVelocity;
    mass = planetMass;
    radius = planetRadius;
    colorR = colorRed;
    colorG = colorGreen;
    colorB = colorBlue;
    
}