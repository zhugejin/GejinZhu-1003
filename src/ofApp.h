#pragma once

#include "ofMain.h"
#include "Boid.hpp"

class ofApp : public ofBaseApp{

	public:
        ofVec2f position;
        void setup();
		void update();
		void draw();
        void render();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage image;
    ofSoundPlayer beat;
    ofSoundPlayer water;
    ofSoundPlayer her;
    ofSoundPlayer bird;
    float * fftSmooth;
    int bands;
    vector<Boid> Boids;
    
    // we will bounce a circle using these variables:
    float px = 300;
    float py = 300;
    float vx = 0;
    float vy = 0;
    float prevx, prevy;
   
    
};
