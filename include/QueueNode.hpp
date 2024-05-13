#ifndef QueueNode_hpp
#define QueueNode_hpp

class queueNode
{
    public:
        queueNode(int data);
        ~queueNode();
        int data;
        queueNode* next;
};

#endif