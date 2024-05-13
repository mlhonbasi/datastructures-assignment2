/*
* @file         Queue.cpp
* @description  Radix sort için kuyruk sınıfının oluşturulması ve kuyruk fonksiyonlarını içerir.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Queue.hpp"
#include <iostream>
using namespace std;

//Kuyruk sınıfının oluşturulması.
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    queueSize = 0;
}

//Kuyruk sınıfının yok edicisi.
Queue::~Queue()
{
    while(front != nullptr)
    {
        queueNode* temp = front;
        front = front->next;
        delete temp;
    }
}

//Kuyruk boş mu kontrolünü yapan fonksiyon.
bool Queue::isEmpty()
{
    if(front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Kuyruğa ekleme işlemi yapan fonksiyon.
void Queue::enQueue(int data)
{
    if(front == nullptr)
    {
        front = new queueNode(data);
        rear = front;
    }
    else
    {
        queueNode* newNode = new queueNode(data);
        rear->next = newNode;
        rear = newNode;
    }
    queueSize++;
}

//Kuyruktan çıkarma işlemi yapan fonksiyon.
void Queue::deQueue()
{
    if(front != nullptr)
    {
        queueNode* temp = front->next;
        delete front;
        front = temp;
    }
    if(front==nullptr)
    {
        rear = nullptr;
    }
    queueSize--;
}

//Baş düğümün verisini döndürür.
int Queue::peek()
{
    if(front != nullptr)
    {
        return front->data;
    }
}

//Kuyruktaki eleman boyutunu döndürür.
int Queue::size()
{
    return queueSize;
}