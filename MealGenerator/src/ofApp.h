#pragma once

#include "ofMain.h"
#include "Parser.hpp"
#include <vector>
#include "ofxGui.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{
    
private:
    Library library_;
    int day_;

	public:
        void setup();
		void update();
		void draw();
    
        // Global Variables
        std::vector<std::vector<string>> recipe_add_;
        std::vector<Recipes> to_return_;
        std::vector<string> grocery_list_;
        vector<string> options_ = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Grocery List"};
    
        ofxDatGuiScrollView* day_scroll_;
    
    // Functions/Variables For Project
        ofxDatGui* gui_;
        ofxDatGuiLabel* main_label_;
        ofxDatGuiLabel* day_label_;
        ofxDatGuiTheme* theme_;
        ofxDatGuiScrollView* scroll;
        ofxDatGuiScrollView* g_scroll;
    
    // Buttons for Main Dropdown
        ofxDatGuiButton* main_b_;
        ofxDatGuiButton* break_b_;
        ofxDatGuiButton* easy_b_;
        ofxDatGuiButton* hard_b_;
        ofxDatGuiButton* clear_b_;
        ofxDatGuiButton* done_btn_;
        ofxDatGuiButton* grocery_b_;
    
        ofxDatGuiDropdown* dropdown_;
        ofxDatGuiTextInput* input_;
    
    // Functions For Buttons
        void onButtonEvent(ofxDatGuiButtonEvent e);
        std::vector<Recipes> PressedMain();
        std::vector<Recipes> PressedBreakfast();
        std::vector<Recipes> PressedHard();
        std::vector<Recipes> PressedEasy();
    
    // Function for dropdown
        void onDropdownEvent(ofxDatGuiDropdownEvent e);
    
    // Function for text input
        void onTextInputEvent(ofxDatGuiTextInputEvent e);
    
    // Main Recipe Scroll
        void onScrollViewEvent(ofxDatGuiScrollViewEvent e);
        void ShowRecipes(std::vector<Recipes> r);
    
    // Function to add ingredients for grocery
        void AddIngredients();
};
