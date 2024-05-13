/*
* @file         Organ.cpp
* @description  Organ sınıfının oluşturulması ve organa ait ağaç ve mutasyon fonksiyonlarını içerir.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Organ.hpp"
#include "Radix.hpp"

//Organ sınıfının kurucu fonksiyonu.
Organ::Organ()
{
    next = nullptr;
    dokuTree = nullptr;
}

//Organ sınıfının yok edici fonksiyonu.
Organ::~Organ()
{
    delete dokuTree;
}

//Organın ağacının atama/belirlenme işlemi.
void Organ::setTree(IkiliAramaAgaci* &tree)
{
    this->dokuTree = tree;
}

//Organın ağacını döndürür.
IkiliAramaAgaci* Organ::getTree()
{
    return this->dokuTree;
}

//Mutasyona uğrama varsa organdaki ağacın düğümlerinin gezilip mutasyona uğratılması.
void Organ::mutation(bstNode* treeNode)
{
    if(treeNode == nullptr)
    {
        return;
    }

    mutation(treeNode->left);
    mutation(treeNode->right);

    treeNode->doku->mutationCells(); //Düğüme ulaştıktan sonra dokuların hücrelerinin mutasyon işleminin yapılması.
}

//Mutasyona uğrayan dokuların post order olarak diziye alındıktan sonra döndürülmesi.
Doku** Organ::getMutatedByPostOrder(bstNode* node) 
{
    Doku** dokular = new Doku*[20];
    for(int i = 0; i < 20; i++)
    {
        dokular[i] = new Doku();
    }
    postOrder(node, dokular);

    return dokular;
}

//Post order olarak dokuların diziye eklenme işlemi.
void Organ::postOrder(bstNode* node, Doku** &dokular)
{
    if(node == nullptr)
    {
        return;
    }
    
    postOrder(node->left, dokular);
    postOrder(node->right, dokular);

    dokular[this->dokuTree->index++] = node->doku;
}

//Mutasyona uğramış olan organın ağacının yeniden oluşturulması.
void Organ::mutatedTree(Doku** &mutatedDoku)
{
    IkiliAramaAgaci* newMutatedTree = new IkiliAramaAgaci();

    /*Dosya okumadaki mantığa göre mutasyona uğrayan dokuların tekrardan sıralama işlemlerinen geçip
    yeni oluşturulan ağaca eklenmesi yapılır.*/
    for(int i = 0; i < 20; i++)
    {
        Radix* rdx = new Radix(mutatedDoku[i], mutatedDoku[i]->cellCount()); 
        int* sorted = rdx->sort();
        mutatedDoku[i]->sortedDNALengths(sorted);
        
        newMutatedTree->insert(mutatedDoku[i]->centerCell,mutatedDoku[i], newMutatedTree->getRoot());
        
        delete rdx;
    }
    delete this->getTree(); //Eski ağaç silinir.
    this->setTree(newMutatedTree); //Yeni ağaç atanır.
}