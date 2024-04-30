#pragma once

#include <iostream>
#include <string>
#include "PriorityQueueHeader.h"

using namespace std;

const int TableSize = 127;

class HTable
{
private:
    class HNode {
    public:
        int key;
        int freq;
        char Name;
        string code;
        HNode(int k=-1, char Nam = '0', int frq = 0)
        {
            key = k;  freq = frq; Name = Nam;
        }
    };

    int hash(int key);
    HNode table[TableSize];

public:
    HTable();
    // Linear Probing
    void insertLinear(char Name);
    void insertLinear(char ch, string cod);
    string searchLinear(int Ascii);
    Queue turnintoQueue(const string& text);
};