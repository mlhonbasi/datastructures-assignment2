/*
* @file         Kontrol.cpp
* @description  Mutasyon kontrolü fonksiyonlarını içeren sınıf.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         14 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Kontrol.hpp"

Kontrol::Kontrol() //Kontrol sınıfının kurucusu.
{}

Kontrol::~Kontrol() //Kontrol sınıfının yok edicisi.
{}

//Organdaki ağacın kök değerine göre mutasyona uğramasına gerek var mı yok mu kontrol eden fonksiyon.
bool Kontrol::needMutationOrgan(Organ* org)
{
    int rootValue = org->getTree()->getRoot()->doku->centerCell;

    if(rootValue % 50 == 0)
    {
        return true;
    }    
    else
    {
        return false;
    }
}

//Dokudaki hücrelerin mutasyona uğramasına gerek var mı yok mu kontrol eden fonksiyon.
bool Kontrol::needMutationHucre(Hucre* hucre)
{
    if(hucre->DNALength % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}