#ifndef Radix_hpp
#define Radix_hpp
#include "Queue.hpp"
#include "Doku.hpp"

class Radix
{
    public:
        Radix(Doku* doku, int count);
        ~Radix();
        int* sort();       
    private:
        int numOfDigits(int number);
        int maxNumOfDigits();
        void queueLength(int* lentghs);
        int* numbers;
        int amountOfNumbers;
        Queue** queues;
};

#endif