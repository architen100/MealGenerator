//
//  library.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#include "library.hpp"
#include <iostream>
#include <fstream>
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

std::vector<std::string> Library::GetGroceryList(std::vector<std::vector<std::string>> recipe_add, Library library_) {
    
    std::vector<std::string> grocery_list;
    for (int i = 0; i < recipe_add.size(); i++) {
        
        for (int ii = 0; ii < recipe_add[i].size(); ii++) {
            
            for (int j = 0; j < library_.GetRecipes().size(); j++) {
                
                if (recipe_add[i][ii] == library_.GetRecipes()[j].GetName()) {
                    
                    for (int k = 0; k < library_.GetRecipes()[j].GetIngredients().size(); k++) {
                        
                        std::string add = library_.GetRecipes()[j].GetIngredients()[k].GetName() + ": " + std::to_string(library_.GetRecipes()[j].GetIngredients()[k].GetAmount())
                        + " " + library_.GetRecipes()[j].GetIngredients()[k].GetUnit();
                        
                        grocery_list.push_back(add);
                    }
                }
            }
        }
    }
    return grocery_list;
}
