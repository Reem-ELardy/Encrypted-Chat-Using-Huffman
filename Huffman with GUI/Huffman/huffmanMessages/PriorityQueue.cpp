#include "PriorityQueueHeader.h"

//--- Definition of Queue constructor
Queue::Queue()
    : MyFront(0), MyBack(0)
{}

//--- Definition of empty()
bool Queue::empty() const
{
    return (MyFront == 0);
}

int Queue::size()
{
    NodePointer q = MyFront;
    int count = 0;

    while (q != NULL)
    {
        count++;
        q = q->next;
    }

    return count;
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement& value, int key) {
    int cnt = 0;
    Queue::NodePointer newptr = new Queue::PNode(value, key), loc = MyBack;
    if (empty()) {
        MyFront = MyBack = newptr;
        return;
    }
    if (key >= MyBack->key) {
        MyBack->next = newptr;
        newptr->previous = MyBack;
        MyBack = newptr;
        return;
    }
    while (key < loc->key) {
        loc = loc->previous;
        if (loc == 0)  break;
    }
    if (loc == 0) {
        newptr->next = MyFront;
        newptr->previous = 0;
        MyFront = newptr;
        newptr->next->previous = newptr;
    }
    else {
        newptr->next = loc->next;
        newptr->previous = loc;
        loc->next = newptr;
        newptr->next->previous = newptr;
    }
}

void Queue::enqueue(Node* n) {
    int cnt = 0;
    Queue::NodePointer newptr = new Queue::PNode(n->freq, n->Name, n->left, n->right), loc = MyBack;
    if (empty()) {
        MyFront = MyBack = newptr;
        return;
    }
    if (n->freq >= MyBack->key) {
        MyBack->next = newptr;
        newptr->previous = MyBack;
        MyBack = newptr;
        return;
    }
    while (n->freq < loc->key) {
        loc = loc->previous;
        if (loc == 0)  break;
    }
    if (loc == 0) {
        newptr->next = MyFront;
        newptr->previous = 0;
        MyFront = newptr;
        newptr->next->previous = newptr;
    }
    else {
        newptr->next = loc->next;
        newptr->previous = loc;
        loc->next = newptr;
        newptr->next->previous = newptr;
    }
}

//--- Definition of front()
QueueElement Queue::front() const
{
    if (!empty())
        return (MyFront->Name);

}

Node* Queue::frontleft() const
{
    if (!empty())
        return (MyFront->left);

}

Node* Queue::frontright() const
{
    if (!empty())
        return (MyFront->right);

}

//--- Definition of dequeue()
void Queue::dequeue()
{
    if (!empty())
    {
        Queue::NodePointer ptr = MyFront;
        MyFront = MyFront->next;
        delete ptr;
        if (MyFront == 0)     // queue is now empty
            MyBack = 0;
    }
    else
        return;
}

QueueElement Queue::frontfrq() const
{
    if (!empty())
        return (MyFront->key);
}