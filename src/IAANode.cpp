/*
* @file         IAANode.cpp
* @description  İkili arama ağacı için düğüm sınıfı.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "IAANode.hpp"

//bstNode sınıfının kurucu fonksiyonu.
//İkili arama ağacının düğümü.
bstNode::bstNode(Doku* nDoku)
{
    left = nullptr;
    right = nullptr;
    this->doku = nDoku;
}

//bstNode sınıfının yok edici fonksiyonu.
bstNode::~bstNode()
{
    
}