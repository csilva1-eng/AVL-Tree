#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "captureInput.h"


//===================================================GRAB FROM CONSOLE STUFF==========================================//

captureInput::captureInput(){
  runXTimes = 0;
  }

void captureInput::setRunXTimes(){ //what is the number? and make sure its valid number
  std::string firstLine = "";
  std::getline(std::cin, firstLine);
  for(auto i : firstLine){
    if(isalpha(i) || i == ' '){ badInput(); runXTimes = 0; return;}

  }
  runXTimes = std::stoi(firstLine);
}


std::vector<std::string> captureInput::getInstructions(){ //put all instructions into a vector to execute in order
  if (runXTimes == 0){return instructions;}

  for(int i = 0; i < runXTimes; i++){
    std::string input;
    std::getline(std::cin, input);

    instructions.push_back(input);
  }

  return instructions;
}


void captureInput::determineInstructions(){ //determine what to do with each instruction, parsing to find what the first word is
  if (instructions.size() == 0){return;}
   for(std::string input : instructions){
     int firstSpace = input.find_first_of(' ');
     std::string orderGiven = input.substr(0, firstSpace);

     if(orderGiven == "insert"){
       handleInsert(input.substr(firstSpace+1));
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

//===================================================END GRAB FROM CONSOLE STUFF======================================//



//===================================================BEGIN HANDLERS STUFF=============================================//

void captureInput::handleInsert(std::string input){ //check if the name and id is good or not then pass into insert
  int firstSpace = input.find_first_of(' ');
  if (firstSpace == std::string::npos || input[0] != '\"' || input.find_last_of('\"') == 0) {
    std::cout << "unsuccessful" << std::endl;
    return;
  }


  std::string name = input.substr(1, firstSpace-2);
  std::string check = input.substr(firstSpace);
  if (check.length() >= 8) {
    input = input.substr(firstSpace+1);
  }

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

  std::string check = input;
  if (input[0] == '\"') {
    input = input.substr(1);
    if (input.find_first_of('\"') != std::string::npos) {
      check = input.substr(0, input.find_first_of('\"'));
    } else {
      badInput();
      return;
    }
  }

  input = check;



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
    tree.search("nothing", std::stoi(input), 0);
    } else if(isName){
      tree.search(input, 0, 1);
    }

}

void captureInput::badInput(){
  std::cout << "unsuccessful" << std::endl;
}



