/*
* @file         Sistem.cpp
* @description  Sistem sınıfının oluşması ve içerdiği fonksiyonlar.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         13 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Sistem.hpp"

//Sistem sınıfının kurucusu
Sistem::Sistem()
{
    head = nullptr;
    next = nullptr;
}

//Sistem sınıfının yok edicisi.
Sistem::~Sistem()
{
    Organ* temp = head;
    while(temp != nullptr)
    {
        Organ* tmp = temp;
        temp = temp->next;
        delete tmp;
    }
}

//Sistemin içine organ düğümlerinin eklenme işlemini yapan fonksiyon.
void Sistem::insertOrgan(Organ* newOrgan)
{
    if(head == nullptr)
    {
        head = newOrgan;
    }
    else
    {
        Organ* temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newOrgan;
        newOrgan->next = nullptr;
    }
}

//İlk düğümü döndüren fonksiyon.
Organ* Sistem::getHead()
{
    return this->head;
}