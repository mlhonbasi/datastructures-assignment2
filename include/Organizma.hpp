#ifndef Organizma_hpp
#define Organizma_hpp
#include "Kontrol.hpp"
#include "Sistem.hpp"

class Organizma
{
    public:
        Organizma();
        ~Organizma();
        void insertSistem(Sistem* sistem);
        void printOrganism();
        void printMutatedOrganism();
        void mutateOrganism();
    private:
        Sistem* head;
};

#endif