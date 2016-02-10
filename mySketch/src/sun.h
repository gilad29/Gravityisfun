#pragma once

#include "ofMain.h"
#include "ofApp.h"

class Sun{
public:
    double xPos;
    double yPos;
    double mass;
    double radius;
    Sun(double xPosition, double yPosition, double sunMass, double sunRadius);
    ~Sun();
};