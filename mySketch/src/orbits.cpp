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

void Planet::acc(){
    
    xAcc = sin(atan2((400-xPos),(400-yPos))) * 2000/(pow(400-xPos,2) + pow(400 - yPos,2));
    yAcc = cos(atan2((400-xPos),(400-yPos))) * 2000/(pow(400-xPos,2) + pow(400 - yPos,2));
    
    xVel += xAcc;
    yVel += yAcc;
    
}

void Planet::move(){
    xPos += xVel;
    yPos += yVel;
}

Planet::Planet(double xPosition, double yPosition, double xVelocity, double yVelocity, double planetMass, int colorRed, int colorGreen, int colorBlue){
    
    xPos = xPosition;
    yPos = yPosition;
    xVel = xVelocity;
    yVel = yVelocity;
    mass = planetMass;
    colorR = colorRed;
    colorG = colorGreen;
    colorB = colorBlue;
    
}