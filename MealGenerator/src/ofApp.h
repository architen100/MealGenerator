#pragma once

#include "ofMain.h"
#include "library.hpp"
#include <vector>
#include "ofxGui.h"
class ofApp : public ofBaseApp{
    
private:
    Library library_;

	public:
		void setup();
		void update();
		void draw();

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
        std::vector<Recipes> Parser();
        std::vector<Recipes> to_return_;
    void playPressed();
    void stopPressed();
    ofxPanel gui;
    ofxButton stop;
    ofxButton play;
		
};
