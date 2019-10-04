//
//  Boid.cpp
//  191003_Murmuration
//
//  Created by Gejin Zhu on 10/2/19.
//

#include "Boid.hpp"
#include "ofMain.h"

void Boid::reset(){
    position.x = ofRandomWidth();
    position.y = ofRandomHeight();
    
    velocity.x = ofRandom(-5,5);
    velocity.y = ofRandom(-5,5);
    acceleration.x = ofRandom(0.03);
    
    drag = ofRandom(0.90,0.99);
    force = ofPoint(0,0.03);
}

void Boid::update(){
    if (isAttracting)
    {
        ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());
        
        force = attractPoint - position;
        force.normalize();
        
        velocity *= drag;
        velocity += force * 0.6;
        
        position += velocity;
    
        }
        
        position += velocity;
    
}
//
void Boid::draw(ofImage image) {
    
    ofPushMatrix();
    ofTranslate(position);
    ofPushMatrix();
    image.draw(position.x,position.y,3.0);
    ofPopMatrix();
    }

void Boid::borders(){
    if (position.x < -drag) position.x = 2+drag;
    if (position.y < -drag) position.y = 2+drag;
    if (position.x > 2+drag) position.x = -drag;
    if (position.y > 2+drag) position.y = -drag;
}
void Boid::toggleMode()
{
    isAttracting = !isAttracting;
    reset();
}
//
    void Boid::play(){
        ////soundplay
        beat.load("sounds/beat.mp3");
        water.load("sounds/water.mp3");
        her.load("sounds/her.mp3");
        bird.load("sounds/bird.mp3");
       
       
    
}

