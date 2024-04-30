#pragma once

#include <iostream>
#include <string>
#include "NodeHeader.h"
#include "HashTableHeader.h"

using namespace std;



class Huffman {
private:
    Node* root;
    HTable huffmanCode;
public:
    Huffman();
    // class constructor of huffman 

    ~Huffman();
    // class destructor of huffman 

    string encode(const string& text);
    // Encode input string

    string decode(const string& encodedText);
    // Decode input string

    void buildTree(const string& text);
    // Build Huffman tree

    void generateHuffmanCode(Node* node, string code);
    // Generate Huffman codes for each character

    void deleteTree(Node* node);
    // Delete Huffman tree
};