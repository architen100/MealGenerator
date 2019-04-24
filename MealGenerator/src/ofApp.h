#pragma once

#include "ofMain.h"
#include "library.hpp"
#include <vector>
#include "ofxGui.h"
#include "ofxDatGui.h"

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
    
    // Functions/Variables For Project
    ofxDatGui* gui;
    ofxDatGuiTheme* theme_; 
    
    // Buttons for Main Dropdown
    ofxDatGuiButton* main_b_;
    ofxDatGuiButton* break_b_;
    ofxDatGuiButton* easy_b_;
    ofxDatGuiButton* hard_b_;
    ofxDatGuiDropdown* dropdown;
    
    // Functions For Buttons on Dropdown
    void onButtonEvent(ofxDatGuiButtonEvent e);
    std::vector<Recipes> PressedMain();
    std::vector<Recipes> PressedBreakfast();
    std::vector<Recipes> PressedHard();
    std::vector<Recipes> PressedEasy();
    
    // Scroll
    ofxDatGuiScrollView* scroll;
    void onScrollViewEvent(ofxDatGuiScrollViewEvent e);
    ofxDatGuiButton* addItem;
    void onAddNewItemButtonClick(ofxDatGuiButtonEvent e);
    void ShowRecipes(std::vector<Recipes> r);

};
