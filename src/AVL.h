//
// Created by Christopher Silva on 9/18/25.
//
#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <ostream>
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


    //===================================================INSERT/REMOVE STUFF==========================================//
   void insert(std::string name, int UFid) {
        if (!checkString(name)) return;
        if (!checkInt(UFid)) return;
        root = recInsertNameId(root, name, UFid);
    }

    bool checkString(std::string name);

    bool checkInt(int UFid);

    void removeById(int UFid) {
        if (!checkInt(UFid)) return;
        root = removeId(root, UFid);
    }

    void removeNth(int N) {
        int count = -1;
        root = removeInorderN(root, N, count);
    }

    TreeNode* recInsertNameId(TreeNode *root, std::string name, int UFid);
    TreeNode* removeId(TreeNode* root, int UFid);
    TreeNode* removeSuccessorId(TreeNode* node, int UFid); //only here to avoid saying success twice
    TreeNode* handleRemove(TreeNode* node);
    TreeNode* findInorderSuccessor(TreeNode* node);
    TreeNode* removeInorderN(TreeNode* root, int N, int &count);


    //===================================================END INSERT/REMOVE STUFF======================================//



    //===================================================SEARCH STUFF=================================================//

    void search(std::string name, int id, int which) {
        if (which == 0) {
            if (!checkInt(id)) return;
            searchID(this->root, id);
        } else if (which == 1) {
            if (!checkString(name)) return;
            searchName(this->root, name);
        }
    }

    void searchID(TreeNode* root, int UFid);
    void searchName(TreeNode* root, std::string name);
    void recSearchName(TreeNode* root, std::string name, std::vector<int>& UFids);

    std::string searchIDTEST(TreeNode* root, int UFid);
    std::vector<int> searchNameTEST(TreeNode* root, std::string name);

    //===================================================END SEARCH STUFF=============================================//



    //===================================================PRINT STUFF=======================================================//
    void PLC() {
        int count = printLevelCount(this->root);
        std::cout << count << std::endl;
    }

    std::vector<std::string> printInorder();
    void recPrintInorder(TreeNode* root, std::vector<std::string>& names);
    std::vector<std::string> printPreorder();
    void recPrintPreorder(TreeNode* root, std::vector<std::string>& names);
    std::vector<std::string> printPostorder();
    void recPrintPostorder(TreeNode* root, std::vector<std::string>& names);
    int printLevelCount(TreeNode* root);


    //===================================================BALANCE STUFF================================================//
    TreeNode* balanceTree(TreeNode* root);
    TreeNode* rotateRight(TreeNode* root);
    TreeNode* rotateLeft(TreeNode* root);
    int getBalanceFactor(TreeNode* root);
    void updateHeight(TreeNode* node);
    //===================================================END BALANCE STUFF============================================//


};



#endif //AVL_H
