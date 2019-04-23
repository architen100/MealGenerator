//
//  ParserTest.cpp
//  MealGenerator
//
//  Created by Archisha Majee on 4/22/19.
//

#define CATCH_CONFIG_RUNNER

#include <stdio.h>
#include "ofApp.h"
#include "/Users/archi/Desktop/catch3.hpp"

int main(int argc, char* argv[]) {
    // global setup...
    
    int result = Catch::Session().run(1, argv );
    
    // global clean-up...
    
    return result;
}

TEST_CASE("test size of JSON") {
    ofApp *app = new ofApp;
    std::vector<Recipes> recipes = app->Parser();
    Library library = Library(recipes);
    REQUIRE(19 == recipes.size());
}

TEST_CASE("test size of array after flitering by type (breakfast)") {
    ofApp *app = new ofApp;
    std::vector<Recipes> recipes = app->Parser();
    Library library = Library(recipes);
    int size = library.FilterType("breakfast").size();
    REQUIRE(5 == size);
}

TEST_CASE("test size of array after flitering by type (main)") {
    ofApp *app = new ofApp;
    std::vector<Recipes> recipes = app->Parser();
    Library library = Library(recipes);
    int size = library.FilterType("main").size();
    REQUIRE(11 == size);
}

TEST_CASE("test size of array after flitering by difficulty (easy)") {
    ofApp *app = new ofApp;
    std::vector<Recipes> recipes = app->Parser();
    Library library = Library(recipes);
    int size = library.FilterDifficulty("easy").size();
    REQUIRE(10 == size);
}

TEST_CASE("test size of array after flitering by difficulty (hard)") {
    ofApp *app = new ofApp;
    std::vector<Recipes> recipes = app->Parser();
    Library library = Library(recipes);
    int size = library.FilterDifficulty("hard").size();
    REQUIRE(9 == size);
}






