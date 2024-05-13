#ifndef Queue_hpp
#define Queue_hpp
#include "QueueNode.hpp"

class Queue
{
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enQueue(int data);
        void deQueue();
        int peek();
        int size();
    private:
        queueNode* front;
        queueNode* rear;
        int queueSize;     
};

#endif