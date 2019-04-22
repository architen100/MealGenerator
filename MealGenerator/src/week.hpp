//
//  week.hpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#ifndef week_hpp
#define week_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "day.hpp"
#include "ingredients.hpp"

#endif /* week_hpp */

class Week {
private:
    std::vector<Day> days_;
    std::vector<Ingredients> grocery_;
public:
    Week(std::vector<Day> d, std::vector<Ingredients> g);
}
