//
// Created by Christopher Silva on 9/18/25.
//
#ifndef AVL_H
#define AVL_H
#include <vector>


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

    void removeNth(int N) {
        int count = -1;
        root = removeInorderN(root, N, count);
    }

    TreeNode* recInsertNameId(TreeNode *root, std::string name, int UFid);

    TreeNode* removeId(TreeNode* root, int UFid);
    TreeNode* handleRemove(TreeNode* node);
    TreeNode* findInorderSuccessor(TreeNode* node);



    std::string searchIDTEST(TreeNode* root, int UFid);
    void searchID(TreeNode* root, int UFid);

    void search(std::string name, int id, int which) {
        if (which == 0) {
            searchID(this->root, id);
        } else if (which == 1) {
            searchName(this->root, name);
        }
    }
    void searchName(TreeNode* root, std::string name);
    std::vector<std::string> searchNameTEST(TreeNode* root, std::string name);

    void recSearchName(TreeNode* root, std::string name, std::vector<std::string>& names);
    std::vector<std::string> printInorder();
    void recPrintInorder(TreeNode* root, std::vector<std::string>& names);
    std::vector<std::string> printPreorder();
    void recPrintPreorder(TreeNode* root, std::vector<std::string>& names);
    std::vector<std::string> printPostorder();
    void recPrintPostorder(TreeNode* root, std::vector<std::string>& names);
    int printLevelCount(TreeNode* root);
    void PLC() {
        printLevelCount(this->root);
    }
    TreeNode* removeInorderN(TreeNode* root, int N, int &count);

    TreeNode* balanceTree(TreeNode* root);
    TreeNode* rotateRight(TreeNode* root);
    TreeNode* rotateLeft(TreeNode* root);
    int getBalanceFactor(TreeNode* root);
    void updateHeight(TreeNode* node);





};



#endif //AVL_H
