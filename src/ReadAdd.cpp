/*
* @file         ReadAdd.cpp
* @description  Dosyadan okuma işlemleri ve okunan verilerin ilgili yapılara eklenmeleri.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "ReadAdd.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ReadAdd::ReadAdd()
{}
ReadAdd::~ReadAdd()
{}

//Dosyadan okuma işlemleri ve okunan verilerin ilgili yapılara eklenme işlemleri.
void ReadAdd::ReadnAdd(Organizma* organism)
{
    string line;
    int number;
    int lineCounter = 0;
    int organCounter = 0;

    ifstream file("Veri.txt");
    
    Sistem* nSystem = new Sistem();
    Organ* organ = new Organ();
    IkiliAramaAgaci* bst = new IkiliAramaAgaci();
    
    while(getline(file,line))
    {
        Doku* activeDoku = new Doku();

        stringstream ss(line);   

        while(ss>>number) //Satırdan sayı okundukça dokuya hücre eklenmesi
        {
            activeDoku->insertCell(number);
        }

        //Satır okuma tamamlandıktan sonra satırdaki sayıların radix sort ile sıralanıp dokunun içerisinde güncellenmesi.
        Radix* rdx = new Radix(activeDoku, activeDoku->cellCount());
        int* sortedNums = rdx->sort();
        activeDoku->sortedDNALengths(sortedNums);
        delete rdx;
        
        lineCounter++;
        bst->insert(activeDoku->centerCell, activeDoku, bst->getRoot()); //Ağacın içine doku eklenmesi.
        
        if(lineCounter == 20) //20 satır/doku olduğunda organın içine ağacın yerleştirilmesi.
        {
            organ->setTree(bst); 
            nSystem->insertOrgan(organ); //Sistemin içine organın yerleştirilmesi.

            bst = new IkiliAramaAgaci();
            organ = new Organ();
            organCounter++;
            
            lineCounter = 0;
        }
        
        if(organCounter == 100) //Organ sayısı 100 olduğunda organizmanın içine sistemin yerleştirilmesi.
        {
            organism->insertSistem(nSystem);
            nSystem = new Sistem();
            organCounter = 0;
        }
    } 
}