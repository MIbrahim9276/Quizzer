/*
Copyright (c) <year>, <copyright holder>
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

// Function declarations
map<string, string> getQuestions(string filePath);
int getScore(string answer, string rightAnswer);

int main(int argc, char* argv[]) {
  // Take the mode from the command line arguments
  if (argc != 2) {
    std::cout << "Usage: ./main [mode]";
    return 1;
  }
  map<string, string> data = getQuestions(argv[1]);

  // Loop through the questions and add them to the score
  int score = 0;
  for (map<string, string>::iterator i = data.begin(); i!= data.end(); i++) {
    cout << i->first << "?" << endl;
    string answer;
    cin >> answer;
    score += getScore(answer, i->second);
  }

  cout << "Your score is: " << score << endl;

  return 0;
}

map<string, string> getQuestions(string filePath) {
  // Open the file in read mode
  ifstream file;
  file.open(filePath);

  // Get the first line containing column names
  string line;
  getline(file, line);

  // Loop through the rest of the columns and add them to the map
  char seperator = ',';
  map<string, string> data;

  while (getline(file, line)) {
    // Define variables to hold the strings
    string temp, question;

    // Loop through the string to seperate it
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == seperator) {
        question = temp;
        temp.clear();
        continue;
      }

      temp += line[i];
    }

    data[question] = temp;
  }

  return data;
}

int getScore(string answer, string rightAnswer) {
  if (answer == rightAnswer) return 10;
  return 5;
}