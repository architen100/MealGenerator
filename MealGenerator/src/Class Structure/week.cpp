//
//  week.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#include "week.hpp"
#include <vector>
#include <iostream>

Week::Week(std::vector<Day> d, std::vector<Ingredients> g) {
    days_ = d;
    grocery_ = g;
}
