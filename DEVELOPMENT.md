# Work Log

## Week 1: 
Created my project proposal 
played with the ofxJson library by creating my own json file and playing around with that 
started experimenting with the ofxDropdown gui

## Week 2: 
Class Structure Overview : 
    1. Week 
        - A vector of days 
    2. Days 
        .- A vector of recipes 
    3. Recipes 
        - Name 
        - Type 
        - Ingredients (vector) 
    4. Ingredients 
        - Name 
        - Amount 
        - Units 

Layout Overview : 
    - Buttons for each type of meal (Lunch, dinner, breakfast, snack)
    - Dropdown Menu for each day 
        - Displays the recipes for each day 
    - Week 
        - A grocery list of all the ingredients 

## Week 3: 
    - Changed my JSON structure so that type is a string instead of an array
    - Ran into a problem with parsing because my ingredients is another array 
    - Found a way to parse a nested array by creating another Json::Value object which take the root ingredients at entries[ i ]
    - Had problems running my catch because main wasn't working 
        - Bypassed problem by creating my own main for catch 
    - Had to create an empty constructor so my ofApp can call my library class 
    - Used a new GUI called ofxDatGui 
        - Played around with the dropdown menu to see if gui worked 
        - Had to rename the ofDatGui files so it matched the project path
