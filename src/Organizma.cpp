/*
* @file         Organizma.cpp
* @description  Organizma sınıfının oluşturulması ve organizma fonksiyonlarını içerir.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         13 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Organizma.hpp"
#include <iomanip>

//Organizma sınıfının kurucu fonksiyonu.
Organizma::Organizma()
{
    head = nullptr;
}

//Organizma sınıfının yok edici fonksiyonu.
//Silinirken içerisindeki sistem düğümlerini de siler.
Organizma::~Organizma()
{
    Sistem* temp = head;
    while (temp != nullptr)
    {
        Sistem* tmp = temp;
        temp = temp->next;
        delete tmp;
    } 
}

//Sistem düğümlerinin organizmaya eklenmesi.
void Organizma::insertSistem(Sistem* nSystem)
{
    if(head == nullptr)
    {
        head = nSystem;
    }
    else
    {
        Sistem* temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nSystem;
        nSystem->next = nullptr;
    }
}

//Organizmanın ekrana yazdırılma işlemi.
void Organizma::printOrganism()
{
    Sistem* tempSistem = head;
    Organ* tempOrgan = tempSistem->getHead();
    Kontrol* control = new Kontrol();

    cout<<setw(55)<<"ORGANIZMA"<<endl;

    while(tempSistem != nullptr)
    {
        while(tempOrgan != nullptr)
        {
            //Ağacın dengesine göre ekrana ilgili karakterin yazımı.
            if(tempOrgan->getTree()->isBalanced(tempOrgan->getTree()->getRoot())) 
            {   
                cout<<" ";
            }
            else
            {
                cout<<"#";
            }

            tempOrgan = tempOrgan->next;
        }
        cout<<endl;
        
        tempSistem = tempSistem->next;
        
        if(tempSistem != nullptr)
        {
            tempOrgan = tempSistem->getHead();
        }
    }
}

//Organizmanın mutasyona uğratılması.
void Organizma::mutateOrganism()
{
    Sistem* tempSistem = head;
    Organ* tempOrgan = tempSistem->getHead();
    Kontrol* control = new Kontrol();

    while(tempSistem != nullptr)
    {
        while(tempOrgan != nullptr)
        {
            if(control->needMutationOrgan(tempOrgan)) //Organın mutasyon kontrolü
            {
                //Organ sınıfında yer alan fonksiyonların kullanımı.
                tempOrgan->mutation(tempOrgan->getTree()->getRoot()); //Ağacın düğümlerini gezip dokuların mutayona uğratılması.
                Doku** values = tempOrgan->getMutatedByPostOrder(tempOrgan->getTree()->getRoot()); //Mutasyonlu dokuların elde edilmesi.
                tempOrgan->mutatedTree(values); //Yeni ağacın ataması.
            }
            tempOrgan = tempOrgan->next;
        }
        tempSistem = tempSistem->next;

        if(tempSistem != nullptr)
        {
            tempOrgan = tempSistem->getHead();
        }
    }
}

//Mutasyona uğramış organizmanın ekrana yazdırılması.
void Organizma::printMutatedOrganism()
{
    Sistem* tempSistem = head;
    Organ* tempOrgan = tempSistem->getHead();
    Kontrol* control = new Kontrol();

    cout<<setw(55)<<"ORGANIZMA (MUTASYONA UGRADI)"<<endl;

    while(tempSistem != nullptr)
    {
        while(tempOrgan != nullptr)
        {
            if(tempOrgan->getTree()->isBalanced(tempOrgan->getTree()->getRoot()))
            {
                cout<<" ";
            }
            else
            {
                cout<<"#";
            }
            tempOrgan = tempOrgan->next;
        }
        cout<<endl;
        
        tempSistem = tempSistem->next;
        
        if(tempSistem != nullptr)
        {
            tempOrgan = tempSistem->getHead();
        }
    }
}