#ifndef CAPTURE_INPUT_H
#define CAPTURE_INPUT_H
#pragma once
#include <vector>
#include <string>
#include "AVL.h"

class captureInput
{

  AVL tree;

  int runXTimes;

  std::vector<std::string> instructions;


  public:

    captureInput();

    AVL getTree() {
        return tree;
    }

    void setRunXTimes();

    std::vector<std::string> getInstructions();
    void setInstructions(std::string instr) { //for testing
        instructions.push_back(instr);
    }

    void determineInstructions();

    void handleSearch(std::string input);
    void handleInsert(std::string input);
    void handleRemove(std::string input);
    void handleRemoveInorder(std::string input);
    void badInput();

};











#endif