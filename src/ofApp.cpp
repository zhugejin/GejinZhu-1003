#include "ofApp.h"

ofImage bird3;



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    // load image
    image.load("bird3.png");
    // load sound
    beat.load("sounds/beat.mp3");
    water.load("sounds/water.mp3");
    her.load("sounds/her.mp3");
    bird.load("sounds/bird.mp3");
    water.setVolume(0.4);
    bird.setVolume(1);
    her.setVolume(2);
    beat.setVolume(0.2);
   
    //sound image
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++){
        fftSmooth[i] = 0;
    }
   bands = 64;
    
    
    
    
    // boid setup
    int numBoids = 20;
    
    for (int i = 0; i < numBoids; i++)
    {
        Boid newBoid;
        newBoid.reset();
        Boids.push_back(newBoid);
    }
}
//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    for (int i = 0; i < Boids.size(); i++)
    {
        Boids[i].update();
    }
    //
    px += vx;
    py += vy;
    //horizon:
    if (px < 512){
        px = 512;
        her.play();
    } else if (px > ofGetWidth()){
        px = ofGetWidth();
        
        bird.play();
    }
    // vertical:
    if (py < 384 ){
        py = 384;
        
        water.play();
        
    } else if (py > ofGetHeight()){
        py = ofGetHeight();
        
        beat.play();
    }
    // (3) slow down velocity:
    vx     *= 0.996f;
    vy     *= 0.996f;
   

// soundupdate
float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++){
        fftSmooth[i] *= 0.9f;
        if (fftSmooth[i] < value[i]){
            fftSmooth[i] = value[i];
        }

    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
     //set boid
     ofPopMatrix();
    for (int i = 0; i < Boids.size(); i++)
    {
        Boids[i].draw(image);
        //Boids[i].play();
    }
    //sound wayes polyline
    ofSetColor(255);
    ofNoFill();
    for(int i = 0; i < Boids.size(); i++){
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150));
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
    
    for (int i = 0; i < Boids.size(); i++)
    {
        Boids[i].toggleMode();
    }
    // add into vx and vy a small amount of the change in mouse:
    vx += (x - prevx) / 20.0f;
    vy += (y - prevy) / 20.0f;
    // store the previous mouse position:
    prevx = x;
    prevy = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    prevx = x;
    prevy = y;
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
