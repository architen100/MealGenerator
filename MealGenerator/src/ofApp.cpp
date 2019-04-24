#include "ofApp.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <json/json.h>
#include "ofxJSON.h"

//----------------------------------

// code derived from https://stackoverflow.com/questions/46203948/reading-array-of-the-json-in-jsoncpp?fbclid=IwAR2_ysL6noXrM6GfDO-zXr5TRqJbhR8q1R_N3q_bMK6WyF9x9bEsNp-5xsc
std::vector<Recipes> ofApp::Parser() {
    
    ofxJSONElement recipe_f;
    std::vector<Recipes> recipes;
    
    recipe_f.open("/Users/archi/Downloads/recipe.json");
    
    if (!recipe_f) {
        std::cout << "can't open file";
        return recipes;
    }
    
    // Parsing the Recipe Root
    Json::Reader reader;
    Json::Value root;
    
    reader.parse(recipe_f.getRawString(), root, false);
    
    auto entries = root["recipes"];
    
    for (int i = 0; i < entries.size(); i++) {
        
        std::vector<Ingredients> to_add;
        
        std::string name = entries[i]["name"].asString();
        std::string diff = entries[i]["difficulty"].asString();
        std::string type = entries[i]["type"].asString();
        
        // Second Parser to parse through ingredients array
        Json::Value data = entries[i]["ingredients"];
        
        for (int j = 0; j < data.size(); j++) {
            std::string name = data[j]["name"].asString();
            //std::cout << name << std::endl;
            std::string units = data[j]["unit"].asString();
            //std::cout << units << std::endl;
            int amount = data[j]["amount"].asInt();
            //std::cout << amount << std::endl;
            Ingredients add = Ingredients(name, amount, units);
            to_add.push_back(add);
        }

        Recipes add = Recipes(name, type, diff, to_add);
        recipes.push_back(add);

        to_add.clear();
    }
    to_return_ = recipes;
    
    return to_return_;
}
//--------------------------------------------------------------
void ofApp::setup(){
    
    // Parsing the json
    std::vector<Recipes> recipes = ofApp::Parser();
    Library library = Library(recipes);
    library_ = library;
    
    
    vector<string> options = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    
    
    // Adding Buttons to gui
    main_b_ = gui -> addButton("main");
    break_b_ = gui -> addButton("breakfast");
    easy_b_ = gui -> addButton("easy");
    hard_b_ = gui -> addButton("hard");
    dropdown = gui -> addDropdown("Days", options);

    // Function when button is clicked
    main_b_ -> onButtonEvent(this, &ofApp::onButtonEvent);
    break_b_ -> onButtonEvent(this, &ofApp::onButtonEvent);
    hard_b_ -> onButtonEvent(this, &ofApp::onButtonEvent);
    easy_b_ -> onButtonEvent(this, &ofApp::onButtonEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//---------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target->getLabel() == "main") {
        PressedMain();
    }
    if (e.target -> getLabel() == "breakfast") {
        PressedBreakfast();
    }
    if (e.target -> getLabel() == "easy") {
        PressedEasy();
    }
    if (e.target -> getLabel() == "hard") {
        PressedHard();
    }
}

//---------------------------------------------------------------
void ofApp::PressedBreakfast() {
    std::vector<Recipes> to_return = library_.FilterType("breakfast");
    for (int i = 0; i < to_return.size(); i++) {
        std::cout << to_return[i].GetName() << std::endl;
    }
}

//----------------------------------------------------------------
void ofApp::PressedMain() {
    std::vector<Recipes> to_return = library_.FilterType("main");
    
    for (int i = 0; i < to_return.size(); i++) {
        std::cout << to_return[i].GetName() << std::endl;
    }
}

// ---------------------------------------------------------------
void ofApp::PressedHard() {
    std::vector<Recipes> to_return = library_.FilterDifficulty("hard");
    
    for (int i = 0; i < to_return.size(); i++) {
        std::cout << to_return[i].GetName() << std::endl;
    }
}

// ---------------------------------------------------------------
void ofApp::PressedEasy() {
    std::vector<Recipes> to_return = library_.FilterDifficulty("easy");
    
    for (int i = 0; i < to_return.size(); i++) {
        std::cout << to_return[i].GetName() << std::endl;
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
