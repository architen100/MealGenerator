//
//  library.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#include "library.hpp"
#include "recipes.hpp"
#include <iostream>
#include <vector>

Library::Library(std::vector<Recipes> r) {
    recipes_ = r;
}

void Library::SetRecipes(std::vector<Recipes> r) {
    recipes_ = r;
}

std::vector<Recipes> Library::GetRecipes() {
    return recipes_;
}


