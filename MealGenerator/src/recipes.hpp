//
//  recipes.hpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#ifndef recipes_hpp
#define recipes_hpp

#include <stdio.h>
#include "ingredients.hpp"
#include <iostream>
#include <vector>

#endif /* recipes_hpp */

class Recipes{
private:
    std::string name_;
    std::string type_;
    std::string difficulty_;
    std::vector<Ingredients> ingredients_;
    
public:
    Recipes(std::string name, std::string type, std::string difficulty, std::vector<Ingredients> ingredients);
    
    //Setters
    void SetName(std::string n);
    void SetType(std::string t);
    void SetDifficulty(std::string d);
    void SetIngredients(std::vector<Ingredients> i);
    
    //Getters
    std::string GetName();
    std::string GetType();
    std::string GetDifficulty();
    std::vector<Ingredients> GetIngredients();
    
    // Helper Functions
};
