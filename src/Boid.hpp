//
//  Boid.hpp
//  191003_Murmuration
//
//  Created by Gejin Zhu on 10/2/19.
//

#ifndef Boid_hpp
#define Boid_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Boid_hpp */

class Boid {
public:
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f force;
    ofVec2f cp;
    
    
    float drag;
    float d;
    float maxspeed;
    float maxforce;
    float deiredseperation;
    
    bool isAttracting = true;
    
    
    
    
    void setup();
    void reset();
    void update();
    void draw();
    void draw(ofImage image);
    void toggleMode();
    void borders();
    void play();
    
    //
    void run(vector<Boid> boids){
         bool isAttracting = true;
    };
    ofSoundPlayer beat;
    ofSoundPlayer water;
    ofSoundPlayer her;
    ofSoundPlayer bird;
    
    
};
