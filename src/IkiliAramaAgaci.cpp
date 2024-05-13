/*
* @file         IkiliAramaAgaci.cpp
* @description  İkili arama ağacını oluşturan sınıf ve ağaaç fonksiyonları.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "IkiliAramaAgaci.hpp"
#include "IAANode.hpp"
#include <iostream>
using namespace std;

//İkili arama ağacının kurucu fonksiyonu.
IkiliAramaAgaci::IkiliAramaAgaci()
{
    root = nullptr;
    index = 0;
}

//İkili arama ağacının yok edici fonksiyonu.
IkiliAramaAgaci::~IkiliAramaAgaci()
{
    destroyTree(root); //Ağacın düğümlerinin silinme işlemi.
}

//İkili arama ağacına verilerin eklenmesi.
//Parametre olarak (dokudaki orta hücre, doku nesnesi, ağaç düğümü) alır.
void IkiliAramaAgaci::insert(int newData,Doku* nDoku, bstNode* current)
{
    if(root == nullptr)
    {
        root = new bstNode(nDoku);
    }
    else if(current->doku->centerCell >= newData) //Orta hücrenin değerine göre ekleme işlemleri.
    {
        if(current->left)
        {
            insert(newData, nDoku, current->left);
        }
        else
        {
            current->left = new bstNode(nDoku);
        }
    }
    else if(current->doku->centerCell < newData)
    {
        if(current->right)
        {
            insert(newData, nDoku, current->right);
        }
        else
        {
            current->right = new bstNode(nDoku);
        }
    }
}

//Ağacın kök düğümünü döndüren fonksiyon.
bstNode* IkiliAramaAgaci::getRoot()
{
    return this->root;
}

//Ağacın yüksekliğini bulan fonksiyon.
int IkiliAramaAgaci::height(bstNode* bstreeNode)
{
    if(bstreeNode == nullptr)
    {
        return 0;
    }
    else
    {
        return (1 + max(leftHeight(bstreeNode), rightHeight(bstreeNode)));
    }
}

//Sol düğümler için yükseklik hesaplar.
int IkiliAramaAgaci::leftHeight(bstNode* treeNode)
{
    return height(treeNode->left);
}

//Sağ düğümler için yükseklik hesaplar.
int IkiliAramaAgaci::rightHeight(bstNode* treeNode)
{
    return height(treeNode->right);
}

//Ana ağacın sol alt ağacı için denge kontrolünü yapan fonksiyon.
bool IkiliAramaAgaci::leftBalance(bstNode* node)
{
    if(node == nullptr)
    {
        return true;
    }

    int lHeight = leftHeight(node);
    int rHeight = rightHeight(node);

    if(abs(lHeight - rHeight) < 2 && leftBalance(node->left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Ana ağacın sağ alt ağacı için denge kontrolünü yapan fonksiyon.
bool IkiliAramaAgaci::rightBalance(bstNode* node)
{
    if(node == nullptr)
    {
        return true;
    }
    int lHeight = leftHeight(node);
    int rHeight = rightHeight(node);

    if(abs(lHeight - rHeight) < 2 && rightBalance(node->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Ana ağacın sol ve sağ alt ağaç dengesinden gelen değere göre dengeli olup olmadığının kontrolü.
bool IkiliAramaAgaci::isBalanced(bstNode* node)
{
    if(node == nullptr)
    {
        return true;
    }

    else if(leftBalance(node->left) && rightBalance(node->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Ağacın yok edicisi çağrıldığında ağacın düğümlerini silen fonksiyon.
void IkiliAramaAgaci::destroyTree(bstNode* node)
{
    if(node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
