#include "AVL.h"
#include <iostream>


/*
Case		Balance Factor			Rotation
(Alignment)	Parent		Child
Left Left	+2			+1			Right
Right Right	-2			-1			Left
Left Right	 +2			-1			Left Right
Right Left	 -2			+1			Right Left
*/


std::vector<int> AVL::insertNameId(TreeNode *node, std::string& name, int UFid){
  std::vector<int> res;
  std::cout<<"Enter name of AVL"<<std::endl;
  return res;
}

std::vector<int> AVL::removeId(TreeNode* node, int UFid){
    std::vector<int> res;
    std::cout<<"Enter name of AVL"<<std::endl;
    return res;
}
std::string AVL::searchID(AVL::TreeNode* node, int UFid){
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
std::vector<std::string> AVL::searchName(AVL::TreeNode* node, std::string name){ //NLR
    std::vector<std::string> names;

    TreeNode* current = node;

    recSearchName(current, name, names);

    return names;
}

void AVL::recSearchName(AVL::TreeNode* node, std::string name, std::vector<std::string>& names){
  if(!node){
    return;
  }

  TreeNode* current = node;

  if(current->name == name){
    names.push_back(current->name);
    std::cout<< current->name <<std::endl;
  }

  recSearchName(current->left, name, names);
  recSearchName(current->right, name, names);

}


std::vector<std::string> AVL::printInorder(AVL::TreeNode* node){
    std::vector<std::string> names;

    TreeNode* current = node;

    recPrintInorder(node, names);
    return names;
}

void AVL::recPrintInorder(AVL::TreeNode* node, std::vector<std::string>& names){
  if(!node){
    return;
  }

  recPrintInorder(node->left, names);

  names.push_back(node->name);
  std::cout<< node->name <<std::endl;

  recPrintInorder(node->right, names);
}

std::vector<std::string> AVL::printPreorder(AVL::TreeNode* node){
    std::vector<std::string> names;

    TreeNode* current = node;

    recPrintPreorder(current, names);
    return names;
}

void AVL::recPrintPreorder(AVL::TreeNode* node, std::vector<std::string>& names){
  if(!node){
    return;
  }

  names.push_back(node->name);
  std::cout<< node->name <<std::endl;

  recPrintPreorder(node->left, names);
  recPrintPreorder(node->right, names);

}


std::vector<std::string> AVL::printPostorder(AVL::TreeNode* node){
    std::vector<std::string> names;

    TreeNode* current = node;
    recPrintPostorder(current, names);
    return names;
}

void AVL::recPrintPostorder(AVL::TreeNode* node, std::vector<std::string>& names){
  if(!node){
    return;
  }

  recPrintPostorder(node->left, names);
  recPrintPostorder(node->right, names);
  names.push_back(node->name);
  std::cout<< node->name <<std::endl;


}

int AVL::printLevelCount(AVL::TreeNode* node){
    if(!node) return 0;
    return 1 + std::max(printLevelCount(node->left), printLevelCount(node->right));
}

std::vector<int> AVL::removeInorderN(AVL::TreeNode* node){
    std::vector<int> res;
    std::cout<<"Enter name of AVL"<<std::endl;
    return res;
}


void AVL::del(int key) {
    std::cout << "something deleted";
}

void AVL::helperInorder(AVL::TreeNode* helpRoot)
{
    if(helpRoot == NULL)
        std::cout << "";
    else
    {
        helperInorder(helpRoot->left);
        std::cout << helpRoot->val << " ";
        helperInorder(helpRoot->right);
    }
}

AVL::TreeNode* AVL::helperInsert(TreeNode* helpRoot, int key)
{
    if (helpRoot == nullptr)
        return new TreeNode(key);
    else if (key < helpRoot->val)
        helpRoot->left = helperInsert(helpRoot->left, key);
    else
        helpRoot->right = helperInsert(helpRoot->right, key);

    return helpRoot;
}



std::vector<int> AVL::inorder()
{
    helperInorder(this->root);
    std::vector<int> output {0, 1, 2};
    return output;
}

void AVL::insert(std::string name, int UFid)
{
    this->root = helperInsert(this->root, UFid);

}