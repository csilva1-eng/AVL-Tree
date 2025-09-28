#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "captureInput.h"

captureInput::captureInput(){
  runXTimes = 0;
  }

void captureInput::setRunXTimes(){
  std::cin >> runXTimes;
}


std::vector<std::string> captureInput::getInstructions(){
  std::cin.ignore(); //ignore \n from number ( wow !)

  for(int i = 0; i < runXTimes; i++){
    std::string input;
    std::getline(std::cin, input);

    instructions.push_back(input);
  }

  return instructions;
}


void captureInput::determineInstructions(){
   for(std::string input : instructions){
     int firstSpace = input.find_first_of(' ');
     std::string orderGiven = input.substr(0, firstSpace);

     if(orderGiven == "insert"){
       handleInsert(input.substr(firstSpace+2));
     } else if(orderGiven == "remove"){
       handleRemove(input.substr(firstSpace+1));
     } else if(orderGiven == "removeInorder"){
       handleRemoveInorder(input.substr(firstSpace+1));
     } else if(orderGiven == "printInorder"){
       tree.printInorder();
     } else if(orderGiven == "printPreorder"){
       tree.printPreorder();
     } else if(orderGiven == "printPostorder"){
       tree.printPostorder();
     } else if(orderGiven == "printLevelCount"){
       tree.PLC();
     } else if(orderGiven == "search"){
       handleSearch(input.substr(firstSpace+1));
     } else {
       badInput(); //Any invalid or misspelled commands must be ignored with an "unsuccessful" message followed by executing the next command.
       }
   }
}

void captureInput::handleInsert(std::string input){
  int firstSpace = input.find_first_of(' ');
  std::string name = input.substr(0, firstSpace - 1);
  input = input.substr(firstSpace +1);

  for(auto i : name){
    if(!isalpha(i) && i != ' '){ badInput(); return;}
    }

    std::string ID = input;

    for(auto i : ID){
      if(isalpha(i) || i == ' '){ badInput(); return;}
    }

    tree.insert(name, std::stoi(ID));
}

void captureInput::handleRemove(std::string input){
  int count = 0;
  for(auto i : input){
    if(isalpha(i) || i == ' '){ badInput(); return;}
    count++;
  }

  if (count != 8) {
    badInput();
    return;
  }

  tree.removeById(std::stoi(input));
}

void captureInput::handleRemoveInorder(std::string input){


  for(auto i : input){
    if(isalpha(i) || i == ' '){ badInput(); return;}
  }

  tree.removeNth(std::stoi(input));
}


void captureInput::handleSearch(std::string input){
  input = input.substr(1);
  bool isName = true;
  bool isId = true;
  for(auto i : input){
    if(!isalpha(i) && i != ' '){ isName = false;}
  }

  for(auto i : input){
    if(isalpha(i) || i == ' '){ isId = false;}
  }

  if(!isName && !isId){ badInput(); return;}

  if(isId){
    tree.search("", std::stoi(input), 0);
    } else if(isName){
      tree.search(input, 0, 1);
    }

}

void captureInput::badInput(){
  std::cout << "unsuccessful" << std::endl;
}



