//
//  library.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#include "library.hpp"
#include <iostream>
#include <vector>

Library::Library(std::vector<Recipes> r) {
    recipes_ = r;
}

// Empty constructor for ofApp
Library::Library() {
    
}

void Library::SetRecipes(std::vector<Recipes> r) {
    recipes_ = r;
}

std::vector<Recipes> Library::GetRecipes() {
    return recipes_;
}

// Filtering Methods
std::vector<Recipes> Library::FilterType(std::string type) {
    std::vector<Recipes> to_return;
    for (int i = 0; i < recipes_.size(); i++) {
        if (type == recipes_.at(i).GetType()) {
            to_return.push_back(recipes_.at(i));
        }
    }
    return to_return;
}

std::vector<Recipes> Library::FilterDifficulty(std::string diff) {
    std::vector<Recipes> to_return;
    for (int i = 0; i < recipes_.size(); i++) {
        if (diff == recipes_.at(i).GetDifficulty()) {
            to_return.push_back(recipes_.at(i));
        }
    }
    return to_return;
}

std::vector<Recipes> Library::FilterIngredients(std::string ingre) {
    std::vector<Recipes> to_return;
    for (int i = 0; i < recipes_.size(); i++) {
        
        for (int ii = 0; ii < recipes_[i].GetIngredients().size(); ii++) {
            
            if (ingre == recipes_[i].GetIngredients()[ii].GetName()) {
                to_return.push_back(recipes_.at(i));
            }
        }
    }
    return to_return;
}




