/*
* @file         Doku.cpp
* @description  Dokuları oluşturan sınıf ve içerdiği fonksiyonlar.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Doku.hpp"
#include "Hucre.hpp"
#include "Kontrol.hpp"
#include <iostream>

using namespace std;

//Doku sınıfının kurucu fonksiyonu.
Doku::Doku()
{
    head = nullptr;
}

//Doku sınıfının yok edici fonksiyonu. 
//Doku silinirken içindeki hücre düğümlerini de siler.
Doku::~Doku()
{
    Hucre* temp = head;
    while(temp != nullptr)
    {
        Hucre* tmp = temp;
        temp = temp->next;
        delete tmp;
    }
    head = nullptr;
}

//Doku bağlı listesine hücre düğümlerinin eklemesini yapan fonksiyon.
void Doku::insertCell(int data)
{
    Hucre* newCell = new Hucre(data);

    if(head == nullptr)
    {
        head = newCell;
    }
    else
    {
        Hucre* temp = head;
        
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newCell;
        newCell->next = nullptr;
    }
}

//Dokudaki hücre sayısını döndüren fonksiyon.
int Doku::cellCount()
{
    int cellCount = 0;
    Hucre* temp = this->head;
    
    while(temp != nullptr)
    {
        cellCount++;
        temp = temp->next;
    }

    return cellCount;  
}

//Radix sort işleminden sonra sıralanan hücre dna uzunluklarının tekrardan dokuya sıralı biçimde eklenme işlemi.
void Doku::sortedDNALengths(int* numbers)
{
    Hucre* temp = this->head;
    int dokuSize = this->cellCount();
    int counter = 0;
    
    while(temp != nullptr)
    {
        temp->DNALength = numbers[counter];
        temp = temp->next;
        counter++;
    }
    setCenterCell(); //Sıralama yapıldıktan sonra orta değer hesaplanması.
}

//Dokuda yer alan hücrelerin ortasındaki hücreyi bulma fonksiyonu.
void Doku::setCenterCell()
{
    int dokuSize = this->cellCount();
    int center = (dokuSize)/2;

    Hucre* temp = this->head;

    for(int i = 0; i < center; i++)
    {
        temp = temp->next;
    }
    this->centerCell = temp->DNALength;
}

//Dokudaki hücreleri mutasyona uğratan fonksiyon.
void Doku::mutationCells()
{
    Kontrol* control = new Kontrol();
    Hucre* temp = this->head;

    while(temp != nullptr)
    {
        if(control->needMutationHucre(temp))
        {
            temp->DNALength = (temp->DNALength/2);
        }
        temp = temp->next;
    }
    delete control;
}

//Doku listesinin ilk düğümünü döndürür.
Hucre* Doku::getHead()
{
    return head;
}