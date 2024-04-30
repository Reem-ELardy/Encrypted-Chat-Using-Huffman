#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

#ifndef NodeHeader
#define NodeHeader

class Node {
public:
    char Name;
    int freq;
    Node* left, * right;

    Node(char ch, int freq);
    //it is the constructor for the node 

    bool isLeaf() const;
    //check if the node is the last (leaf) or not 
};

#endif