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

std::vector<int> AVL::removeId(TreeNode* node, int UFid){}
std::string AVL::searchID(AVL::TreeNode* node, int UFid){}
std::vector<std::string> AVL::searchName(AVL::TreeNode* node, std::string& name){}
std::vector<std::string> AVL::printInorder(AVL::TreeNode* node){}
std::vector<std::string> AVL::printPreorder(AVL::TreeNode* node){}
std::vector<std::string> AVL::printPostorder(AVL::TreeNode* node){}
std::vector<int> AVL::printLevelCount(AVL::TreeNode* node){}
std::vector<int> AVL::removeInorderN(AVL::TreeNode* node){}


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