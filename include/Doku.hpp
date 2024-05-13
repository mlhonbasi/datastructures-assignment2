#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"
#include <iostream>

using namespace std;

class Doku
{
    public:
        Doku();
        ~Doku();
        Hucre* getHead();
        void insertCell(int data);
        void sortedDNALengths(int* numbers);
        void mutationCells();
        int cellCount();
        int centerCell;
    private:
        void setCenterCell();
        Hucre* head;
};

#endif