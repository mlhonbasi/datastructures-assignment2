/*
* @file         Radix.cpp
* @description  Radix sort algoritması için gerekli fonksiyonları içerir.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Radix.hpp"
using namespace std;

//Radix sınıfının kurucusu.
Radix::Radix(Doku* doku,int count)
{
    this->amountOfNumbers = count; 
    this->numbers = new int[amountOfNumbers]; //Dokudaki hücre sayısı kadarlık yeni dizi oluşumu.

    Hucre* temp = doku->getHead();
    for(int i=0; i < amountOfNumbers; i++) //Dokunun hücrelerinin değerlerinin diziye aktarılması.
    {
        this->numbers[i] = temp->DNALength;
        temp = temp->next; 
    }

    queues = new Queue*[10]; //Son basamak sayı değerlerine göre ekleme çıkarılma işlemleri yapılacak olan kuyrukların oluşturulması.
    for(int i=0; i < 10; i++)
    {
        queues[i] = new Queue();
    }
}

//Radix sınıfının yok edicisi.
Radix::~Radix()
{
    delete[] numbers;

    for(int i = 0 ; i < 10 ; i++)
    {
        delete queues[i];
    }
    delete[] queues;
}

//Sıralama işlemini yapan fonksiyon.
int* Radix::sort()
{
    for(int i=0; i < amountOfNumbers; i++) //Sayıların son basamak değerlerine göre kuyruğa alınması.
    {
        int lastDigit = numbers[i]%10;
        queues[lastDigit]->enQueue(numbers[i]);
    }

    int maxDigit = maxNumOfDigits(); //En çok basamak içeren sayı.
    int digitMltp = 10;

    for(int i = 1; i < maxDigit; i++)
    {
        int lengths[10];
        queueLength(lengths); //Kuyruktaki eleman sayılarının diziye alınması.

        for(int j=0; j < 10; j++)
        {
            int iCount = lengths[j]; //Aynı son basamağı içeren sayıların adedi.
            while(iCount)
            {
                int nextNum = queues[j]->peek(); //Kuyruktan sayının alınması.
                queues[j]->deQueue();
                int digit = (nextNum/digitMltp)%10; //Sayının diğer basamağının elde edilmesi. 123 sayısında onlar basamağı olan 2'nin eldesi gibi.
                queues[digit]->enQueue(nextNum);    //Sayının elde edilen son basamağına göre kuyruğa eklenmesi.
                iCount--;
            }
        }
        digitMltp = digitMltp*10;
    }

    int arrayIndex = 0;
    
    for(int i=0; i < 10; i++) //Sıralanmış sayıların diziye eklenmesi.
    {
        while(!queues[i]->isEmpty())
        {
            numbers[arrayIndex] = queues[i]->peek();
            queues[i]->deQueue();
            arrayIndex++;
        }
    }
    return numbers;
}

//Sayının basamak sayısını döndürür
int Radix::numOfDigits(int number)
{
    int digitCount = 0;
    while(number != 0)
    {
        number = number/10;
        digitCount++;
    }
    return digitCount;
}

//En çok basamak içeren sayının basamak sayısını döndürür.
int Radix::maxNumOfDigits() 
{
    int maxDigitCount = numOfDigits(numbers[0]);
    int nextDigitCount;
    for(int i = 1; i < amountOfNumbers; i++)
    {
        nextDigitCount = numOfDigits(numbers[i]);

        if(maxDigitCount < nextDigitCount)
        {
            maxDigitCount = nextDigitCount;
        }
    }
    return maxDigitCount;
}

//Kuyruklardaki eleman sayılarının diziye alınması.
void Radix::queueLength(int* lengths)
{
    for(int i=0; i < 10; i++)
    {
        lengths[i] = queues[i]->size();
    }
}