//
//  ingredients.hpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#ifndef ingredients_hpp
#define ingredients_hpp

#include <stdio.h>
#include <iostream>

#endif /* ingredients_hpp */

class Ingredients {
private:
    static int amount_;
    static std::string name_;
    static std::string unit_;
    
public:
    Ingredients(std::string name, int amount, std::string unit);
    // Setters
    void SetName(std::string n);
    void SetAmount(int a);
    void SetUnit(std::string u);
    
    // Getters
    std::string GetName();
    std::string GetUnit();
    int GetAmount();
};
