/*
* @file         Hucre.cpp
* @description  Doku bağlı listesinin düğümü olmak üzere hücre sınıfı.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Hucre.hpp"
#include <iostream>
using namespace std;

//Doku bağlı listesinde düğüm olarak kullanılacak olan hücrenin kurucu fonksiyonu.
Hucre::Hucre(int data)
{
    this->DNALength = data;
    next = nullptr;
}

//Hücre sınıfının yok edici fonksiyonu.
Hucre::~Hucre()
{

}
