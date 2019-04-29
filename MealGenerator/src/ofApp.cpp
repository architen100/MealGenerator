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
    
    for (int p = 0; p < 7; p++) {
        recipe_add.push_back(std::vector<string> {});
    }
    
    vector<string> options = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Grocery List"};
    
    gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT );

    
    
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
    grocery_b = gui -> addButton("Grocery");

    // Function when button is clicked
    gui -> onButtonEvent(this, &ofApp::onButtonEvent);
    gui -> onTextInputEvent(this, &ofApp::onTextInputEvent);
    
    // Creating my ScrollMenu to hold my recipes
    scroll = new ofxDatGuiScrollView("Recipes", 8);
    g_scroll = new ofxDatGuiScrollView("Grocery", 8);
    
    g_scroll -> setBackgroundColor(ofColor(0x7d7066));
    
    scroll -> onScrollViewEvent(this, &ofApp::onScrollViewEvent);
    
    m_drop = new ofxDatGuiDropdown("Monday", {});
    t_drop = new ofxDatGuiDropdown("Tuesday", {});
    w_drop = new ofxDatGuiDropdown("Wednesday", {});
    r_drop = new ofxDatGuiDropdown("Thursday", {});
    f_drop = new ofxDatGuiDropdown("Friday", {});
    s_drop = new ofxDatGuiDropdown("Saturday", {});
    ss_drop = new ofxDatGuiDropdown("Sunday", {});
    
    
    //Set Visibility to False
    SetVisibility(10);
    
    
    // Setting Position for DropDown To Show Recipe
    SetPositionOfDrop();
    
    // Action for Dropdown menu
    dropdown -> onDropdownEvent(this, &ofApp::onDropdownEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    //addItem -> update();
    scroll -> update();
    g_scroll -> update();
    m_drop -> update();
    t_drop -> update();
    w_drop -> update();
    r_drop -> update();
    f_drop -> update();
    s_drop -> update();
    ss_drop -> update();
    //g_drop -> update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(ofColor(0x7d7066));
    //addItem -> draw();
    scroll -> draw();
    g_scroll -> draw();
    m_drop -> draw();
    t_drop -> draw();
    w_drop -> draw();
    r_drop -> draw();
    f_drop -> draw();
    s_drop -> draw();
    ss_drop -> draw();
    //g_drop -> draw();
    
}

//-------------------------------------------------------------
void ofApp::SetPositionOfDrop() {
    m_drop -> setPosition(ofGetScreenWidth()/2 - m_drop->getWidth() - 50, ofGetScreenHeight()/2 - m_drop->getHeight()/2);

    t_drop -> setPosition(ofGetScreenWidth()/2 - t_drop -> getWidth() - 50, ofGetScreenHeight()/2 - t_drop->getHeight()/2);

    w_drop -> setPosition(ofGetScreenWidth()/2 - w_drop -> getWidth() - 50, ofGetScreenHeight()/2 - w_drop->getHeight()/2);

    r_drop -> setPosition(ofGetScreenWidth()/2 - r_drop->getWidth() - 50, ofGetScreenHeight()/2 - r_drop->getHeight()/2);

    f_drop -> setPosition(ofGetScreenWidth()/2 - f_drop->getWidth() - 50, ofGetScreenHeight()/2 - f_drop->getHeight()/2);

    s_drop -> setPosition(ofGetScreenWidth()/2 - s_drop->getWidth() - 50, ofGetScreenHeight()/2 - s_drop->getHeight()/2);

    ss_drop -> setPosition(ofGetScreenWidth()/2 - ss_drop->getWidth() - 50, ofGetScreenHeight()/2 - ss_drop->getHeight()/2);
    
    g_scroll -> setPosition(ofGetScreenWidth()/2 - g_scroll->getWidth() - 60,
                            ofGetScreenHeight()/2 - g_scroll ->getHeight()/2 - 150);
}
//-------------------------------------------------------------
void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e) {
    int num = e.child;
    
    day = num;
    
    if (num == 0) {
        m_drop -> setVisible(true);
        SetVisibility(num);
    }
    if (num == 1) {
        t_drop -> setVisible(true);
        SetVisibility(num);
    }
    if (num == 2) {
        w_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 3) {
        r_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 4) {
        f_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 5) {
        s_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 6) {
        ss_drop -> setVisible(true);
        SetVisibility(num);

    }
    if (num == 7) {
        g_scroll -> setVisible(true);
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
        g_scroll -> setVisible(false);
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
    recipe_add[day].push_back(e.target -> getLabel());
}

//---------------------------------------------------------------
void ofApp::AddRecipe(int num) {
    
    std::cout << "in the beginning" << recipe_add.size() << std::endl;
    
    if (num == 0) {
        m_drop = new ofxDatGuiDropdown("Monday", recipe_add[0]);
        SetPositionOfDrop();
    }
    if (num == 1) {
        t_drop = new ofxDatGuiDropdown("Tuesday", recipe_add[1]);
        SetPositionOfDrop();
    }
    if (num == 2) {
        w_drop = new ofxDatGuiDropdown("Wednesday", recipe_add[2]);
        SetPositionOfDrop();
    }
    if (num == 3) {
        r_drop = new ofxDatGuiDropdown("Thursday", recipe_add[3]);
        SetPositionOfDrop();
    }
    if (num == 4) {
        f_drop = new ofxDatGuiDropdown("Friday", recipe_add[4]);
        SetPositionOfDrop();
    }
    if (num == 5) {
        s_drop = new ofxDatGuiDropdown("Saturday", recipe_add[5]);
        SetPositionOfDrop();
    }
    if (num == 6) {
        ss_drop = new ofxDatGuiDropdown("Sunday", recipe_add[6]);
        SetPositionOfDrop();
    }
}

//--------------------------------------------------------------
void ofApp::AddIngredients() {
    
    for (int i = 0; i < recipe_add.size(); i++) {
        
        for (int ii = 0; ii < recipe_add[i].size(); ii++) {
            
            for (int j = 0; j < library_.GetRecipes().size(); j++) {
                
                if (recipe_add[i][ii] == library_.GetRecipes()[j].GetName()) {
                    
                    for (int k = 0; k < library_.GetRecipes()[j].GetIngredients().size(); k++) {
                        
                        string add = library_.GetRecipes()[j].GetIngredients()[k].GetName() + ": " + std::to_string(library_.GetRecipes()[j].GetIngredients()[k].GetAmount())
                        + " " + library_.GetRecipes()[j].GetIngredients()[k].GetUnit();
                        
                        grocery_list.push_back(add);
                    }
                }
            }
        }
    }
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
        AddRecipe(day);
    }
    if (e.target -> getLabel() == "Grocery") {
        SetVisibility(10);
        AddIngredients();
        g_scroll -> setTheme(new ofxDatGuiThemeAutumn);
        for (int i = 0; i < grocery_list.size(); i++) {
            g_scroll -> add(grocery_list[i]);
        }
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

// ----------------------------------------------------------------
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e) {
    std::vector<Recipes> recipes = library_.FilterIngredients(e.text);
    scroll -> clear();
    ShowRecipes(recipes);
}

// ----------------------------------------------------------------
