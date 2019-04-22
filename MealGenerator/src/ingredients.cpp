//
//  ingredients.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#include "ingredients.hpp"
#include <iostream>

Ingredients::Ingredients(std::string n, int a, std::string u){
    name_ = n;
    amount_ = a;
    unit_ = u;
}

// Setters
void Ingredients::SetName(std::string n) {
    name_ = n;
}

void Ingredients::SetAmount(int a) {
    amount_ = a;
}

void Ingredients::SetUnit(std::string u) {
    unit_ = u;
}

// Getters
int Ingredients::GetAmount() {
    return amount_;
}

std::string Ingredients::GetName() {
    return name_;
}
std::string Ingredients::GetUnit() {
    return unit_;
}


