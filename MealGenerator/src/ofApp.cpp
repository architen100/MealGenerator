#include "ofApp.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <json/json.h>
#include "ofxJSON.h"

//----------------------------------------------------------------------
void ofApp::setup(){
    
    // Parsing the json
    std::vector<Recipes> recipes = Parser();
    Library library = Library(recipes);
    library_ = library;
    
    for (int p = 0; p < 7; p++) {
        recipe_add.push_back(std::vector<string> {});
    }
    
    gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT );

    day_scroll_ = new ofxDatGuiScrollView("Menu", 8);
    
    day_scroll_ -> setPosition(ofGetScreenWidth()/2 - day_scroll_-> getWidth() - 50, ofGetScreenHeight()/2 - day_scroll_-> getHeight()/2);
    
    gui -> setTheme(new ofxDatGuiThemeAutumn);
    
    
    // Adding Buttons to gui
    main_label = gui -> addLabel("Click Option");
    main_b_ = gui -> addButton("main");
    break_b_ = gui -> addButton("breakfast");
    easy_b_ = gui -> addButton("easy");
    hard_b_ = gui -> addButton("hard");
    input = gui -> addTextInput("ingredient", "");
    day_label = gui -> addLabel("Choose Day");
    dropdown = gui -> addDropdown("Days", options);
    done_btn = gui -> addButton("Finish Adding");
    clear_b = gui -> addButton("Clear Day");
    grocery_b = gui -> addButton("Grocery");

    // Function when button is clicked
    gui -> onButtonEvent(this, &ofApp::onButtonEvent);
    gui -> onTextInputEvent(this, &ofApp::onTextInputEvent);
    
    // Creating my ScrollMenu to hold my recipes
    scroll = new ofxDatGuiScrollView("Recipes", 8);
    g_scroll = new ofxDatGuiScrollView("Grocery", 8);
    g_scroll -> setPosition(ofGetScreenWidth()/2 - g_scroll -> getWidth() - 50, 0);
    
    g_scroll -> setBackgroundColor(ofColor(0xB5BCB2));
    
    scroll -> onScrollViewEvent(this, &ofApp::onScrollViewEvent);
    
    // Action for Dropdown menu
    dropdown -> onDropdownEvent(this, &ofApp::onDropdownEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    scroll -> update();
    g_scroll -> update();
    day_scroll_ -> update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor(0xB5BCB2));
    scroll -> draw();
    day_scroll_ -> draw();
    g_scroll -> draw();
}

//-------------------------------------------------------------
void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e) {
    
    day_scroll_ -> clear();
    
    int num = e.child;
    
    day_ = num;
    
    for (int i = 0; i < recipe_add[day_].size(); i++) {
        day_scroll_ -> add(recipe_add[day_][i]);
    }
}

// ---------------------------------------------------------------
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e) {
    std::vector<Recipes> recipes = library_.FilterIngredients(e.text);
    scroll -> clear();
    ShowRecipes(recipes);
}

//--------------------------------------------------------------
void ofApp::onScrollViewEvent(ofxDatGuiScrollViewEvent e){
    recipe_add[day_].push_back(e.target -> getLabel());
}

//---------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target->getLabel() == "main") {
        std::vector<Recipes> r = PressedMain();
        scroll -> clear();
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "breakfast") {
        std::vector<Recipes> r = PressedBreakfast();
        scroll -> clear();
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "easy") {
        std::vector<Recipes> r = PressedEasy();
        scroll -> clear();
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "hard") {
        std::vector<Recipes> r = PressedHard();
        scroll -> clear();
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "Finish Adding") {
        day_scroll_ -> clear();
        for (int i = 0; i < recipe_add[day_].size(); i++) {
            day_scroll_ -> add(recipe_add[day_][i]);
        }
    }
    
    if (e.target -> getLabel() == "Grocery") {
        grocery_list = library_.GetGroceryList(recipe_add, library_);
        g_scroll -> setTheme(new ofxDatGuiThemeAutumn);
        for (int i = 0; i < grocery_list.size(); i++) {
            g_scroll -> add(grocery_list[i]);
        }
    }
    if (e.target -> getLabel() == "Clear Day") {
        recipe_add[day_].clear();
        day_scroll_ -> clear();
    }
}

//---------------------------------------------------------------
std::vector<Recipes> ofApp::PressedBreakfast() {
    std::vector<Recipes> to_return = library_.FilterType("breakfast");
    return to_return;
}

//----------------------------------------------------------------
std::vector<Recipes> ofApp::PressedMain() {
    std::vector<Recipes> to_return = library_.FilterType("main");
    return to_return;
}

// ---------------------------------------------------------------
std::vector<Recipes> ofApp::PressedHard() {
    std::vector<Recipes> to_return = library_.FilterDifficulty("hard");
    return to_return;
}

// ---------------------------------------------------------------
std::vector<Recipes> ofApp::PressedEasy() {
    std::vector<Recipes> to_return = library_.FilterDifficulty("easy");
    return to_return;
}

//--------------------------------------------------------------
void ofApp::ShowRecipes(std::vector<Recipes> r) {
    for (int i = 0; i < r.size(); i++) {
        scroll -> add(r[i].GetName());
    }
}

