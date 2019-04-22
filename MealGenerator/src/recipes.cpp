//
//  recipes.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#include "recipes.hpp"
#include "ingredients.hpp"
#include <iostream>
#include <vector>

Recipes::Recipes(std::string n, std::string t, std::string d, std::vector<Ingredients> i) {
    name_ = n;
    type_ = t;
    difficulty_ = d;
    ingredients_ = i;
    
}

// Setters
void Recipes::SetName(std::string n) {
    name_ = n;
}

void Recipes::SetType(std::string t) {
    type_ = t;
}

void Recipes::SetDifficulty(std::string d) {
    difficulty_ = d;
}

void Recipes::SetIngredients(std::vector<Ingredients> i) {
    ingredients_ = i;
}

//Getters
std::string Recipes::GetName() {
    return name_;
}

std::string Recipes::GetType() {
    return type_;
}

std::string Recipes::GetDifficulty() {
    return difficulty_;
}

std::vector<Ingredients> Recipes::GetIngredients() {
    return ingredients_;
}
