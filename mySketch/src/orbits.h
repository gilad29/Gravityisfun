#pragma once

#include "ofMain.h"

//declerations only

class Planet{
public:
    double xPos;
    double yPos;
    double xVel;
    double yVel;
    double xAcc;
    double yAcc;
    double mass;
    int colorR;
    int colorG;
    int colorB;
    //constructor
    Planet(double xPosition, double yPosition, double xVelocity, double yVelocity, double planetMass, int colorRed, int colorGreen, int colorBlue);
    
    
    void acc();
    void move();
    
};
