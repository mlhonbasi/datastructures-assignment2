#ifndef Organ_hpp
#define Organ_hpp
#include "IkiliAramaAgaci.hpp"

class Organ
{
    public:
        Organ();
        ~Organ();
        void setTree(IkiliAramaAgaci* &tree);
        void mutatedTree(Doku** &dokus);
        void mutation(bstNode* node);
        Doku** getMutatedByPostOrder(bstNode* node);
        IkiliAramaAgaci* getTree();
        Organ* next;
    private:
        IkiliAramaAgaci* dokuTree; 
        void postOrder(bstNode* node, Doku** &array);
};

#endif