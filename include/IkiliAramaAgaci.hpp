#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp
#include "IAANode.hpp"

class IkiliAramaAgaci
{
    public:
        IkiliAramaAgaci();
        ~IkiliAramaAgaci();
        void insert(int data, Doku* doku, bstNode* currentNode);
        bool isBalanced(bstNode* node);
        bstNode* getRoot();
        int index;
    private:
        void destroyTree(bstNode* node);
        bool leftBalance(bstNode* node);
        bool rightBalance(bstNode* node);
        int height(bstNode* root);
        int leftHeight(bstNode* node);
        int rightHeight(bstNode* node);
        bstNode* root;
};

#endif