#ifndef IAANode_hpp
#define IAANode_hpp
#include "Doku.hpp"

class bstNode
{
    public:
        bstNode(Doku* doku);
        ~bstNode();
        bstNode* left;
        bstNode* right;
        Doku* doku;
};

#endif