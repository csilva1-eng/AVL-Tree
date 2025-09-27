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
        int UFID;
        std::string name;
        int height;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x, int y, const std::string& s) : UFID(x), name(s), height(y), left(nullptr), right(nullptr){}
    };

    TreeNode* root = nullptr;

public:
    TreeNode* getRoot() {
        return root;
    }

   void insert(std::string name, int UFid) {
        root = recInsertNameId(root, name, UFid);
    }

    void removeById(int UFid) {
        root = removeId(root, UFid);
    }

    TreeNode* recInsertNameId(TreeNode *root, std::string name, int UFid);

    TreeNode* removeId(TreeNode* root, int UFid);
    TreeNode* handleRemove(TreeNode* node);
    TreeNode* findInorderSuccessor(TreeNode* node);



    std::string searchID(TreeNode* root, int UFid);
    std::vector<std::string> searchName(TreeNode* root, std::string name);
    void recSearchName(TreeNode* root, std::string name, std::vector<std::string>& names);
    std::vector<std::string> printInorder();
    void recPrintInorder(TreeNode* root, std::vector<std::string>& names);
    std::vector<std::string> printPreorder(TreeNode* root);
    void recPrintPreorder(TreeNode* root, std::vector<std::string>& names);
    std::vector<std::string> printPostorder(TreeNode* root);
    void recPrintPostorder(TreeNode* root, std::vector<std::string>& names);
    int printLevelCount(TreeNode* root);
    std::vector<int> removeInorderN(TreeNode* root);

    TreeNode* balanceTree(TreeNode* root);
    TreeNode* rotateRight(TreeNode* root);
    TreeNode* rotateLeft(TreeNode* root);
    int getBalanceFactor(TreeNode* root);
    void updateHeight(TreeNode* node);





};



#endif //AVL_H
