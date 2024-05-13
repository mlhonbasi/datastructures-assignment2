#ifndef Sistem_hpp
#define Sistem_hpp
#include "Organ.hpp"

class Sistem
{
    public:
        Sistem();
        ~Sistem();
        void insertOrgan(Organ* organ);
        Organ* getHead();
        Sistem* next;
    private:
        Organ* head;
};

#endif