# Final Project
This project is a meal generator which allows a user to filter through a JSON file and select what ypes of recipes they want based on certain characteristics. For example, if they want a hard or easy recipe or if they want a certain ingredient. The user can then add the recipes they want for each day and also get a list of all the grocery items they need to buy for that week. 

# Getting Started 
To deploy the project on your local machine you will need to have the OpenFrameworks application for development and testing purposes. 

# Prerequisties 
You will need to make sure you have the ofxJson and ofxDatGui addon to get the project up and running. 

# Installing 
1. Clone the project and download it to your desktop 
2. Open OpenFrameworks and import the downloaded project using the respective button
3. After click Generate Project and the project should be up and running 

# Running the Test 
To run the tests for this program you will need to use Catch.hpp 
If you go to the test file, you should see a Parser Test file which tests whether the project parses the JSON file correctly 
- For example it tests whether the size of recipes in the JSON file is the correct size 
To run the tests correctly, you must uncomment the test file and then comment out the main file to make sure not to get a clang error 
 
# Authors 
- Archisha Majee 

# Acknowledgments 
-  Parser code inspired from: https://stackoverflow.com/questions/46203948/reading-array-of-the-json-in-jsoncpp?fbclid=IwAR2_ysL6noXrM6GfDO-zXr5TRqJbhR8q1R_N3q_bMK6WyF9x9bEsNp-5xsc 

