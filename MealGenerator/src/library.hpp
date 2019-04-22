//
//  library.hpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#ifndef library_hpp
#define library_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "recipes.hpp"


#endif /* library_hpp */

class Library {
private:
    std::vector<Recipes> recipes_;
    
    public :
    Library(std::vector<Recipes> r);
    
    //Setters
    void SetRecipes(std::vector<Recipes> r);
    
    // Getters
    std::vector<Recipes> GetRecipes();
};
