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
        recipe_add_.push_back(std::vector<string> {});
    }
    
    gui_ = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT );

    day_scroll_ = new ofxDatGuiScrollView("Menu", 8);
    
    day_scroll_ -> setPosition(ofGetScreenWidth()/2 - day_scroll_ -> getWidth() - 350, 500);
    
    gui_ -> setTheme(new ofxDatGuiThemeAutumn);
    
    
    // Adding Buttons to gui
    main_label_ = gui_ -> addLabel("Click Option");
    main_b_ = gui_ -> addButton("main");
    break_b_ = gui_ -> addButton("breakfast");
    easy_b_ = gui_ -> addButton("easy");
    hard_b_ = gui_ -> addButton("hard");
    input_ = gui_ -> addTextInput("ingredient", "");
    day_label_ = gui_ -> addLabel("Choose Day");
    dropdown_ = gui_ -> addDropdown("Days", options_);
    done_btn_ = gui_ -> addButton("Finish Adding");
    clear_b_ = gui_ -> addButton("Clear Day");
    grocery_b_ = gui_ -> addButton("Grocery");

    // Function when button is clicked
    gui_ -> onButtonEvent(this, &ofApp::onButtonEvent);
    gui_ -> onTextInputEvent(this, &ofApp::onTextInputEvent);
    
    // Creating my ScrollMenu to hold my recipes
    scroll = new ofxDatGuiScrollView("Recipes", 8);
    g_scroll = new ofxDatGuiScrollView("Grocery", 8);
    g_scroll -> setPosition(ofGetScreenWidth()/2 - g_scroll-> getWidth() + 300 , 500);
    
    g_scroll -> setBackgroundColor(ofColor(0xB5BCB2));
    
    scroll -> onScrollViewEvent(this, &ofApp::onScrollViewEvent);
    
    // Action for Dropdown menu
    dropdown_ -> onDropdownEvent(this, &ofApp::onDropdownEvent);
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
    
    for (int i = 0; i < recipe_add_[day_].size(); i++) {
        day_scroll_ -> add(recipe_add_[day_][i]);
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
    recipe_add_[day_].push_back(e.target -> getLabel());
}

//---------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target->getLabel() == "main") {
        std::vector<Recipes> r = PressedMain();
        scroll -> clear();
        scroll -> add("Available Recipes");
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "breakfast") {
        std::vector<Recipes> r = PressedBreakfast();
        scroll -> clear();
        scroll -> add("Available Recipes");
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "easy") {
        std::vector<Recipes> r = PressedEasy();
        scroll -> clear();
        scroll -> add("Available Recipes");
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "hard") {
        std::vector<Recipes> r = PressedHard();
        scroll -> clear();
        scroll -> add("Available Recipes");
        ShowRecipes(r);
    }
    if (e.target -> getLabel() == "Finish Adding") {
        day_scroll_ -> clear();
        day_scroll_ -> add("Menu For Day");
        for (int i = 0; i < recipe_add_[day_].size(); i++) {
            day_scroll_ -> add(recipe_add_[day_][i]);
        }
    }
    
    if (e.target -> getLabel() == "Grocery") {
        grocery_list_ = library_.GetGroceryList(recipe_add_, library_);
        g_scroll -> add("Grocery List");
        g_scroll -> setTheme(new ofxDatGuiThemeAutumn);
        for (int i = 0; i < grocery_list_.size(); i++) {
            g_scroll -> add(grocery_list_[i]);
        }
    }
    if (e.target -> getLabel() == "Clear Day") {
        recipe_add_[day_].clear();
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

