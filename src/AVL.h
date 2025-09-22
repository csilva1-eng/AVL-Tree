//
// Created by Christopher Silva on 9/18/25.
//
#include <vector>
#ifndef AVL_H
#define AVL_H


class AVL
{
private:
    struct TreeNode
    {
        int val;
        int balance_factor;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;
    TreeNode* helperInsert(TreeNode* helpRoot, int key);
    void helperInorder(TreeNode* helpRoot);

public:
    std::vector<int> inorder();
    void insert(std::string name, int UFid);
    void del(int key);

    std::vector<int> insertNameId(TreeNode* root, std::string& name, int UFid);
    std::vector<int> removeId(TreeNode* root, int UFid);
    std::string searchID(TreeNode* root, int UFid);
    std::vector<std::string> searchName(TreeNode* root, std::string& name);
    std::vector<std::string> printInorder(TreeNode* root);
    std::vector<std::string> printPreorder(TreeNode* root);
    std::vector<std::string> printPostorder(TreeNode* root);
    std::vector<int> printLevelCount(TreeNode* root);
    std::vector<int> removeInorderN(TreeNode* root);

};



#endif //AVL_H
