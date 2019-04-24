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
    
    
    vector<string> options = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Grocery List"};
    
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    
    gui -> setTheme(new ofxDatGuiThemeAutumn);
    
    
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
    
    // Creating my ScrollMenu to hold my recipes
    scroll = new ofxDatGuiScrollView("Recipes", 8);
    scroll -> onScrollViewEvent(this, &ofApp::onScrollViewEvent);
    
    // Action for Dropdown menu
    dropdown -> onDropdownEvent(this, &ofApp::onDropdownEvent);
    
    // Initialzing gui menu for days
//    m_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//    t_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//    w_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//    r_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//    f_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//    s_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//    ss_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//    g_g = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
//
    m_drop = new ofxDatGuiDropdown("Monday", {});
    t_drop = new ofxDatGuiDropdown("Tuesday", {});
    w_drop = new ofxDatGuiDropdown("Wednesday", {});
    r_drop = new ofxDatGuiDropdown("Thursday", {});
    f_drop = new ofxDatGuiDropdown("Friday", {});
    s_drop = new ofxDatGuiDropdown("Saturday", {});
    ss_drop = new ofxDatGuiDropdown("Sunday", {});
    g_drop = new ofxDatGuiDropdown("Grocery", {});
    
    
    //Set Visibility to False
    //SetVisibility(10);
    
    // Setting Position for Scrolls for Menus
    m_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    t_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    w_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    r_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    f_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    s_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    ss_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    g_drop->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    
//    //Create a button add items
//    addItem = new ofxDatGuiButton("click to add item");
//    addItem->onButtonEvent(this, &ofApp::onAddNewItemButtonClick);
}

//--------------------------------------------------------------
void ofApp::update(){
    //addItem -> update();
    scroll -> update();
    m_drop -> update();
    t_drop -> update();
    w_drop -> update();
    r_drop -> update();
    f_drop -> update();
    s_drop -> update();
    ss_drop -> update();
    g_drop -> update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //addItem -> draw();
    scroll -> draw();
    m_drop -> draw();
    t_drop -> draw();
    w_drop -> draw();
    r_drop -> draw();
    f_drop -> draw();
    s_drop -> draw();
    ss_drop -> draw();
    g_drop -> draw();
    
}

//--------------------------------------------------------------
//void ofApp::onAddNewItemButtonClick(ofxDatGuiButtonEvent e)
//{
//    scroll-> add("item " + ofToString(scroll -> getNumItems() + 1));
//    addItem->setLabel("click to add item - " + ofToString(scroll->getNumItems()) + " items");
//}

//-------------------------------------------------------------
void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e) {
    int num = e.child;
    
    for (int i = 0; i < to_add.size(); i++) {
        std::cout << to_add[i] << std::endl;
    }
    
    std::cout << "this is num " << num << std::endl;
    
    if (num == 0) {
        m_drop = new ofxDatGuiDropdown("Monday", to_add);
        m_drop -> setVisible(true);
        std::cout << "m" << std::endl;
        SetVisibility(num);
    }
    if (num == 1) {
        t_drop = new ofxDatGuiDropdown("Tuesday", to_add);
        t_drop -> setVisible(true);
        std::cout << "t" << std::endl;
        SetVisibility(num);
    }
    if (num == 2) {
        w_drop = new ofxDatGuiDropdown("Wednesday", to_add);
        w_drop -> setVisible(true);
        std::cout << "w" << std::endl;
        SetVisibility(num);

    }
    if (num == 3) {
        r_drop = new ofxDatGuiDropdown("Thursday", to_add);
        r_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 4) {
        f_drop = new ofxDatGuiDropdown("Friday", to_add);
        f_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 5) {
        s_drop = new ofxDatGuiDropdown("Saturday", to_add);
        s_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 6) {
        ss_drop = new ofxDatGuiDropdown("Sunday", to_add);
        ss_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 7) {
        g_drop = new ofxDatGuiDropdown("Grocery", to_add);
        g_drop -> setVisible(true);
        SetVisibility(num);
    }
}

//--------------------------------------------------------------
void ofApp::SetVisibility(int num) {
    if (num != 0) {
        m_drop -> setVisible(false);
    }
    if (num != 1) {
        t_drop -> setVisible(false);
    }
    if (num != 2) {
        w_drop -> setVisible(false);
    }
    if (num != 3) {
         r_drop -> setVisible(false);
    }
    if (num != 4) {
        f_drop -> setVisible(false);
    }
    if (num != 5) {
        s_drop -> setVisible(false);
    }
    if (num != 6) {
        ss_drop -> setVisible(false);
    }
    if (num != 7) {
        g_drop -> setVisible(false);
    }

}
//--------------------------------------------------------------
void ofApp::ShowRecipes(std::vector<Recipes> r) {
    for (int i = 0; i < r.size(); i++) {
        scroll -> add(r[i].GetName());
    }
}

//--------------------------------------------------------------
void ofApp::onScrollViewEvent(ofxDatGuiScrollViewEvent e){
    to_add.push_back(e.target -> getLabel());
}

//---------------------------------------------------------------
void ofApp::AddRecipe() {
    
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
