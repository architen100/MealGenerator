//
//  week.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#include "week.hpp"
#include "day.hpp"
#include "ingredients.hpp"
#include <iostream>
#include <vector>

Week::Week(std::vector<Day> d, std::vector<Ingredients> i) {
    days_ = d;
    grocery_ = i; 
}
