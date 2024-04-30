#include <iostream>
#include <stdio.h>
#include "NodeHeader.h"


#pragma once

using namespace std;

typedef char QueueElement;

class Queue
{
public:

    Queue();
    bool empty() const;
    void enqueue(const QueueElement& Name, int key);
    void enqueue(Node* n);
    QueueElement front() const;
    QueueElement frontfrq() const;
    Node* frontleft() const;
    Node* frontright() const;
    int size();
    void dequeue();


private:
    /*** Node class ***/
    class PNode
    {
    public:
        char Name;
        int key;
        PNode* next = 0;
        PNode* previous = 0;
        Node* left = 0;
        Node* right = 0;
        //--- Node constructor
        PNode(QueueElement Nam = '0', int k = 0)
        {
            Name = Nam; key = k;
        }

        PNode(int k = 0, QueueElement Nam = '0', Node* lft = 0, Node* rght = 0)
        {
            Name = Nam; key = k;
            left = lft; right = rght;
        }

    };

    typedef PNode* NodePointer;

    /***** Data Members *****/
    NodePointer MyFront,      // pointer to front of queue
        MyBack;       // pointer to back of queue

}; // end of class declaration