#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include "NodeHeader.h"

using namespace std;

//Definition of class constructor
Node::Node(char c, int frq)
{
    this->Name = c;
    this->freq = frq;
    left = right = nullptr;
}

//Definition of isleaf()
bool Node::isLeaf() const
{
    return (left == nullptr && right == nullptr);
}
