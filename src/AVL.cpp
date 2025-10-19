#include "AVL.h"
#include <iostream>



//===================================================BALANCING STUFF==================================================//
AVL::TreeNode* AVL::balanceTree(TreeNode* node) {
  if (!node) {
    return node;
  }
  updateHeight(node);
    int balanceParent = 0;
    int balanceChildR = 0;
    int balanceChildL = 0;
    if (node->right) balanceChildR = getBalanceFactor(node->right);
    if (node->left) balanceChildL = getBalanceFactor(node->left);
    if (node) balanceParent = getBalanceFactor(node);


    if(balanceParent == 2 && balanceChildL == 1) { //LL case
      node = rotateRight(node);
    } else if(balanceParent == -2 && balanceChildR == -1) { //RR case
      node = rotateLeft(node);
    } else if(balanceParent == 2 && balanceChildL == -1) { //LR case
      node->left = rotateLeft(node->left);
      node = rotateRight(node);
    } else if(balanceParent == -2 && balanceChildR == 1) { //RL case
      node->right = rotateRight(node->right);
      node = rotateLeft(node);
    }

    return node;

}

int AVL::getBalanceFactor(TreeNode* node) { // using heights to find balance factor to then use in balanceTree
  if(!node) return 0;

  int heightLeft = node->left ? node->left->height : 0;
  int heightRight = node->right ? node->right->height : 0;
  return heightLeft - heightRight;
}

void AVL::updateHeight(TreeNode* node) { // simple update heights of node. they can hold height
  if(!node) return;
  int heightLeft = node->left ? node->left->height : 0;
  int heightRight = node->right ? node->right->height : 0;
  node->height = std::max(heightLeft, heightRight) + 1;
}

AVL::TreeNode* AVL::rotateRight(TreeNode* node) {
  if (!node || !node->left) return node;
  TreeNode* newParent = node->left;
  TreeNode* temp = newParent->right;

  newParent->right = node;
  node->left = temp;

  updateHeight(node);
  updateHeight(newParent);

  return newParent;
}

AVL::TreeNode* AVL::rotateLeft(TreeNode* node) {
  if (!node || !node->right) return node;
  TreeNode* newParent = node->right;
  TreeNode* temp = newParent->left;
  newParent->left = node;
  node->right = temp;

  updateHeight(node);
  updateHeight(newParent);

  return newParent;
}

//===================================================END BALANCING STUFF===============================================//


//===================================================INSERT/REMOVE STUFF==============================================//


bool AVL::checkString(std::string name) { //check if string is a valid string before input into anything
  for(auto i : name){
    if(!isalpha(i) && i != ' '){ std::cout << "unsuccessful" << std::endl; return false;}
  }
  return true;
}

bool AVL::checkInt(std::string UFid) {

  if (UFid.length() != 8) {std::cout << "unsuccessful" <<  std::endl; return false;}
  for(auto i : UFid) {
    if(isalpha(i) || i == ' '){return false;}
  }
    return true;
}



AVL::TreeNode* AVL::recInsertNameId(TreeNode *node, std::string name, std::string UFid){ //recursively search to find where to insert new node
  if(!node) {
    std::cout << "successful" << std::endl;
    return new TreeNode(UFid, 1, name);
  }
  int nodesId = std::stoi(node->UFID);
  int newNodesId = std::stoi(UFid);

  if(nodesId > newNodesId){
    node->left = recInsertNameId(node->left, name, UFid);
  } else if(nodesId < newNodesId) {
    node->right =  recInsertNameId(node->right, name, UFid);
  }else if(nodesId == newNodesId) {
     std::cout << "unsuccessful" << std::endl;
     return node;
  }

  updateHeight(node);
  return balanceTree(node);
}


AVL::TreeNode* AVL::removeId(TreeNode* node, std::string UFid){ // recursively search to find node to remove
    if(!node ) {
      std::cout << "unsuccessful" << std::endl;
      return node;
    }
  int nodesId = std::stoi(node->UFID);
  int removeNodesId = std::stoi(UFid);

    if(nodesId < removeNodesId) {
      node->right = removeId(node->right, UFid);
      updateHeight(node);
    } else if(nodesId > removeNodesId) {
      node->left = removeId(node->left, UFid);
      updateHeight(node);
    } else {
      node = handleRemove(node); //handle removal cases in different function
      std::cout << "successful" << std::endl;
    }

    return node;
  }


AVL::TreeNode* AVL::handleRemove(TreeNode* node){ //handles all three removal case, one kid, two kids, no kids
  if(node->left == nullptr && node->right == nullptr){
    delete node;
    return nullptr;
  }
  if(!node->left  || !node->right){
    TreeNode* childNode = node->right ? node->right : node->left;
    delete node;
    return childNode;
  }
    TreeNode* successorNode = findInorderSuccessor(node);
    node->UFID = successorNode->UFID;
    node->name = successorNode->name;
    node->right = removeSuccessorId(node->right, successorNode->UFID);
    return node;

}

AVL::TreeNode* AVL::removeSuccessorId(TreeNode* node, std::string UFid){ // this is to remove successor (really to avoid saying success twice)
  if(!node ) {
    std::cout << "unsuccessful" << std::endl;
    return node;
  }
  int nodesId = std::stoi(node->UFID);
  int removeNodesId = std::stoi(UFid);

  if(nodesId < removeNodesId) {
    node->right = removeId(node->right, UFid);
    updateHeight(node);
  } else if(nodesId > removeNodesId) {
    node->left = removeId(node->left, UFid);
    updateHeight(node);
  } else {
    node = handleRemove(node); //handle removal cases in different function
  }

  return node;
}

AVL::TreeNode* AVL::findInorderSuccessor(TreeNode* node){ //find inorder successor for removal cases
  if (!node || !node->right) return nullptr;
  node = node->right;
  while(node->left){
    node = node->left;
  }

  return node;

}

AVL::TreeNode* AVL::removeInorderN(TreeNode* node, int N, int &count){
  if (!node) {
    return nullptr;
  }

  node->left = removeInorderN(node->left, N, count);
  if (node) count++;
  if (count == N) {
    node = removeId(node, node->UFID);
    return node;
  }
  node->right = removeInorderN(node->right, N, count);

  return node;
}

//===================================================END INSERT/REMOVE STUFF==========================================//



//===================================================SEARCH STUFF=====================================================//

void AVL::searchID(AVL::TreeNode* node, std::string UFid){ //recursively search for UFid and print name
  if (!node) {std::cout << "unsuccessful" << std::endl; return;}
    std::string foundName = "";
  int nodesId;
  int searchNodesId;
    while(node && node->UFID != UFid){
       nodesId = std::stoi(node->UFID);
       searchNodesId = std::stoi(UFid);

      if(nodesId > searchNodesId){
        node = node->left;
      } else {
        node = node->right;
      }
    }

    if(nodesId == searchNodesId){
      foundName = node->name;
      std::cout<< foundName <<std::endl;
      return;
    }
    std::cout<<"unsuccessful"<<std::endl;
}

std::string AVL::searchIDTEST(AVL::TreeNode* node, std::string UFid){ //this is jsut for testing so i can have the string it returns
  std::string foundName = "";
  TreeNode* current = node;

  while(current && current->UFID != UFid){
    if(current->UFID > UFid){
      current = current->left;
    } else {
      current = current->right;
    }
  }
  if(current->UFID == UFid){
    foundName = current->name;
    std::cout<< foundName <<std::endl;
    return foundName;
  }
  std::cout<<"unsuccessful"<<std::endl;
  return foundName;
}

void AVL::searchName(AVL::TreeNode* node, std::string name){ //NLR
    std::vector<std::string> UFids;


    recSearchName(node, name, UFids);
  if (UFids.size() == 0){std::cout << "unsuccessful" << std::endl;return;}
  for (auto number : UFids) {
    std::cout << number << std::endl;
  }


}

std::vector<std::string> AVL::searchNameTEST(TreeNode* node, std::string name){ //NLR this is just for testing so i can have the vector
  std::vector<std::string> UFids;


  recSearchName(node, name, UFids);

  for (auto number : UFids) {
    std::cout << number << std::endl;
  }

  return UFids;
}

void AVL::recSearchName(AVL::TreeNode* node, std::string name, std::vector<std::string>& UFids){
  if(!node){
    return;
  }


  if(node->name == name){
    UFids.push_back(node->UFID);
  }

  recSearchName(node->left, name, UFids);
  recSearchName(node->right, name, UFids);

}

//===================================================END SEARCH STUFF=================================================//


//===================================================PRINT STUFF=======================================================//

std::vector<std::string> AVL::printInorder(){ //LNR
    std::vector<std::string> names;

    recPrintInorder(this->root, names);

  for (int i = 0; i < names.size(); i++) {
    if (i != names.size() - 1) {std::cout<< names[i] << ", ";}
    else {std::cout<< names[i] << std::endl;}
  }
    return names;
}

void AVL::recPrintInorder(TreeNode* node, std::vector<std::string>& names){
  if(!node){
    return;
  }

  recPrintInorder(node->left, names);

  names.push_back(node->name);

  recPrintInorder(node->right, names);
}

std::vector<std::string> AVL::printPreorder(){ //NLR
    std::vector<std::string> names;

    recPrintPreorder(this->root, names);
  for (int i = 0; i < names.size(); i++) {
    if (i != names.size() - 1) {std::cout<< names[i] << ", ";}
    else {std::cout<< names[i] << std::endl;}
  }
    return names;
}

void AVL::recPrintPreorder(TreeNode* node, std::vector<std::string>& names){
  if(!node){
    return;
  }

  names.push_back(node->name);

  recPrintPreorder(node->left, names);
  recPrintPreorder(node->right, names);

}


std::vector<std::string> AVL::printPostorder(){ //LRN
    std::vector<std::string> names;

    recPrintPostorder(this->root, names);

  for (int i = 0; i < names.size(); i++) {
    if (i != names.size() - 1) {std::cout<< names[i] << ", ";}
    else {std::cout<< names[i] << std::endl;}
  }
    return names;
}

void AVL::recPrintPostorder(TreeNode* node, std::vector<std::string>& names){
  if(!node){
    return;
  }

  recPrintPostorder(node->left, names);
  recPrintPostorder(node->right, names);
  names.push_back(node->name);


}

int AVL::printLevelCount(TreeNode* node){

  return node ? node->height: 0;
}


//===================================================END PRINT STUFF==================================================//






