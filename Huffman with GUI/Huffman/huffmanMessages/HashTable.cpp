#pragma once

#include <iostream>
#include <string>
#include "HashTableHeader.h"
#include "PriorityQueueHeader.h"


using namespace std;

HTable::HTable()
{

}

//------------------------ Hash function ----------------------------------------
int HTable::hash(int Ascii)
{   
    return Ascii % TableSize;
}

//----------------- insert Linear probing ---------------------------------------
void HTable::insertLinear(char ch)
{
    int index = hash(int(ch));

    if (table[index].Name == ch) {
         table[index].freq++;
        return;
    }

    else if (table[index].key == -1) { // No collision
        HNode n (index, ch, 1);
        table[index] = n;
        return;
    }

}

void HTable::insertLinear(char ch, string cod)
{
    int index = hash(int(ch));

    HNode n(index, ch, 0);
    n.code = cod;
    table[index] = n;
}

//----------------- search Linear probing ---------------------------------------
string HTable::searchLinear(int Ascii) {
    int index = hash(Ascii);
    string code = table[index].code;
    return code;
}

Queue HTable::turnintoQueue(const string& text)
{
    Queue TIQ;

    for (char ch : text)
    {
        int index = hash(int(ch));
        if (table[index].key == -1)
            continue;

        else
        {
            TIQ.enqueue(table[index].Name, table[index].freq);

            table[index].key = -1;
            table[index].freq = 0;
            table[index].Name = '0';
        }
    }

    return TIQ;
}
