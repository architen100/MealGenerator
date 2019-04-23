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
    
    std::cout << to_return_.size();
    
    return to_return_;
}
//--------------------------------------------------------------
void ofApp::setup(){
    std::cout << "hello";
    std::vector<Recipes> recipes = ofApp::Parser();
    Library library = Library(recipes);
    std::vector<Recipes> new_recipes = library.FilterDifficulty("easy");
    std::cout << "this is filter size" << new_recipes.size() << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
