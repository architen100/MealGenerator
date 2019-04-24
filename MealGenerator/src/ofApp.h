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
        std::vector<Recipes> Parser();
        std::vector<Recipes> to_return_;
        std::vector<string> recipe_add;
    std::vector<string> grocery_list;
    
    // Functions/Variables For Project
        ofxDatGui* gui;
        ofxDatGuiTheme* theme_;
    
    // Buttons for Main Dropdown
        ofxDatGuiButton* main_b_;
        ofxDatGuiButton* break_b_;
        ofxDatGuiButton* easy_b_;
        ofxDatGuiButton* hard_b_;
        ofxDatGuiDropdown* dropdown;
    
    // Functions to set position of drop down menus
        void SetPositionOfDrop(); 
    
    // Functions For Buttons on Dropdown
        void onButtonEvent(ofxDatGuiButtonEvent e);
        std::vector<Recipes> PressedMain();
        std::vector<Recipes> PressedBreakfast();
        std::vector<Recipes> PressedHard();
        std::vector<Recipes> PressedEasy();
    
    // Function for dropdown
        void onDropdownEvent(ofxDatGuiDropdownEvent e);
        void SetVisibility(int num);
    
    // Main Recipe Scroll
        ofxDatGuiScrollView* scroll;
        void onScrollViewEvent(ofxDatGuiScrollViewEvent e);
        ofxDatGuiButton* addItem;
        void onAddNewItemButtonClick(ofxDatGuiButtonEvent e);
        void ShowRecipes(std::vector<Recipes> r);
    
    // Dropdown for Each Day
        ofxDatGuiDropdown* m_drop;
        ofxDatGuiDropdown* t_drop;
        ofxDatGuiDropdown* w_drop;
        ofxDatGuiDropdown* r_drop;
        ofxDatGuiDropdown* f_drop;
        ofxDatGuiDropdown* s_drop;
        ofxDatGuiDropdown* ss_drop;
        ofxDatGuiDropdown* g_drop;

    
    // Function to add Recipe to scroll day
        void AddRecipe(int num);
        ofxDatGuiButton* done_btn;
    void AddIngredients(std::vector<string> s); 
    
        int day;
};
