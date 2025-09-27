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
// Treenode( ufid, balance_factor, name)
AVL::TreeNode* AVL::balanceTree(TreeNode* node) {
    int balanceParent = 0;
    int balanceChildR = 0;
    int balanceChildL = 0;
    if (node->right) balanceChildR = getBalanceFactor(node->right);
    if (node->left) balanceChildL = getBalanceFactor(node->left);
    if (node) balanceParent = getBalanceFactor(node);


    if(balanceParent == 2 && balanceChildL == 1) {
      node = rotateRight(node);
    } else if(balanceParent == -2 && balanceChildR == -1) {
      node = rotateLeft(node);
    } else if(balanceParent == 2 && balanceChildL == -1) {
      node = rotateLeft(node);
      node = rotateRight(node);
    } else if(balanceParent == -2 && balanceChildR == 1) {
      node = rotateRight(node);
      node = rotateLeft(node);
    }

    return node;

}

int AVL::getBalanceFactor(TreeNode* node) {
  if(!node) return 0;

  int heightLeft = node->left ? node->left->height : 0;
  int heightRight = node->right ? node->right->height : 0;
  return heightLeft - heightRight;
}

void AVL::updateHeight(TreeNode* node) {
  if(!node) return;
  int heightLeft = node->left ? node->left->height : 0;
  int heightRight = node->right ? node->right->height : 0;
  node->height = std::max(heightLeft, heightRight) + 1;
}

AVL::TreeNode* AVL::rotateRight(TreeNode* node) {
  if (!node || !node->left || !node->right) return node;
  TreeNode* newParent = node->left;
  TreeNode* temp = newParent->right;

  newParent->right = node;
  node->left = temp;

  updateHeight(node);
  updateHeight(newParent);

  return newParent;
}

AVL::TreeNode* AVL::rotateLeft(TreeNode* node) {
  if (!node || !node->left || !node->right) return node;
  TreeNode* newParent = node->right;
  TreeNode* temp = newParent->left;
  newParent->left = node;
  node->right = temp;

  updateHeight(node);
  updateHeight(newParent);

  return newParent;
}

/*

rotateLeft (node)
{
grandchild = node->right->left;
newParent = node->right;
newParent->left = node;
node->right = grandchild;
return newParent;
}
 */


AVL::TreeNode* AVL::recInsertNameId(TreeNode *node, std::string name, int UFid){
  if(!node) {
    std::cout << "inserted " << name << std::endl;
    std::cout << "successful" << std::endl;
    return new TreeNode(UFid, 1, name);
  }

  if(node->UFID > UFid){
    node->left = recInsertNameId(node->left, name, UFid);
  } else if(node->UFID < UFid) {
    node->right =  recInsertNameId(node->right, name, UFid);
  }else if(node->UFID == UFid) {
     std::cout << "unsuccessful" << std::endl;
     return node;
  }

  updateHeight(node);
  return balanceTree(node);
}
/*
Find and remove the account with the specified ID from the tree.
[Optional: Balance the tree automatically if necessary.
We will test your code only on cases where the tree will be balanced before and after the deletion.
So you can implement a BST deletion and still get full credit]
If deletion is successful, print ““successful.”
If the ID does not exist within the tree, print “unsuccessful.”
You must prioritize replacing a removed node with its inorder successor for the
case where the deleted node has two children.
 */

AVL::TreeNode* AVL::removeId(TreeNode* node, int UFid){
    if(!node ) {
      std::cout << "unsuccessful" << std::endl;
      return node;
    }




    if(node->UFID < UFid) {
      node->right = removeId(node->right, UFid);
    } else if(node->UFID > UFid) {
      node->left = removeId(node->left, UFid);
    } else {
      std::cout << "successful" << std::endl;
      std::cout << "removed " << node->name << std::endl;
      node = handleRemove(node);
    }

    return node;
  }


AVL::TreeNode* AVL::handleRemove(TreeNode* node){
  if(node->left == nullptr && node->right == nullptr){
    delete node;
    return nullptr;
  }
  if(!node->left  || !node->right){
    TreeNode* childNode = node->right ? node->right : node->left;
    delete node;
    return childNode;
  } else{
     //  TreeNode* successorNode = node->right;
     // if(successorNode->left){
     //         successorNode = findInorderSuccessor(node);
     //   }
     //   if(successorNode->UFID == node->right->UFID){
     //     successorNode->right = node->right->right;
     //   } else {
     //
     //     successorNode->right = node->right; // but what happens to successor nodes original right if it has to find successor?
     //    }
    TreeNode* successorNode = findInorderSuccessor(node);
    node->UFID = successorNode->UFID;
    node->name = successorNode->name;
    node->right = removeId(node->right, successorNode->UFID);
    return node;
  }
}

AVL::TreeNode* AVL::findInorderSuccessor(TreeNode* node){
  if (!node || !node->right) return nullptr;
  node = node->right;
  while(node->left){
    node = node->left;
  }

  return node;

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


std::vector<std::string> AVL::printInorder(){
    std::vector<std::string> names;

    recPrintInorder(this->root, names);
    return names;
}

void AVL::recPrintInorder(TreeNode* node, std::vector<std::string>& names){
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




