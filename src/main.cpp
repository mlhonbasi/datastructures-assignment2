/*
* @file         main.cpp
* @description  Programın başlatılması.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Organizma.hpp"
#include "ReadAdd.hpp"
#include <iostream>
using namespace std;

int main()
{
    Organizma* organism = new Organizma();
    ReadAdd::ReadnAdd(organism);   

    system("CLS");
    organism->printOrganism();
   
   if(cin.get() == '\n')
   {
        system("CLS");
        organism->mutateOrganism();
        organism->printMutatedOrganism();
   }
    

    return 0;
}