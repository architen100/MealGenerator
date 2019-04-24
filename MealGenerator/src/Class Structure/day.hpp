//
//  day.hpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#ifndef day_hpp
#define day_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "library.hpp"

#endif /* day_hpp */

class Day {
private:
    std::vector<Recipes> day_r_;
    
public:
    Day(std::vector<Recipes> r);
};
