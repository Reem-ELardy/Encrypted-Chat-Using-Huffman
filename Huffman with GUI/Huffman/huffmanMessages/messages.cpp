#include <iostream>
#include <string>
#include "NodeHeader.h"
#include "HuffmanHeader.h"
#include "HashTableHeader.h"
#include "PriorityQueueHeader.h"

using namespace std;

//Definition of class constructor
Huffman::Huffman() {
    root = nullptr;
}

// Definition of class destructor 
Huffman::~Huffman() {
    deleteTree(root);
}

// Definition of Encode input string
string Huffman::encode(const string& text) {
    if (root == nullptr) {
        return "";
    }
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCode.searchLinear(int(ch));
    }
    return encodedText;
}

// Definition of Decode input string
string Huffman::decode(const string& encodedText) {
    if (root == nullptr) {
        return "";
    }
    string decodedText = "";
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        }
        else {
            current = current->right;
        }
        if (current->isLeaf()) {
            decodedText += current->Name;
            current = root;
        }
    }
    return decodedText;
}

// Definition of Build Huffman tree
void Huffman::buildTree(const string& text) {
    if (text.empty()) {
        return;
    }

    HTable huffmanchar;
    for (char ch : text) {
        huffmanchar.insertLinear(ch);
    }

    Queue pq = huffmanchar.turnintoQueue(text);

    if(pq.size()==1)
    {
        root = new Node('\0', 0);
        root->left = NULL;
        root->right = new Node(pq.front(), pq.frontfrq());
        pq.dequeue();
    }
    else
    {
        while (pq.size() > 1) {
            Node* left = new Node(pq.front(), pq.frontfrq());
            left->left = pq.frontleft();
            left->right = pq.frontright();
            pq.dequeue();
            Node* right = new Node(pq.front(), pq.frontfrq());
            right->left = pq.frontleft();
            right->right = pq.frontright();
            pq.dequeue();
            Node* parent = new Node('\0', left->freq + right->freq);
            parent->left = left;
            parent->right = right;
            pq.enqueue(parent);
        }
        root = new Node(pq.front(), pq.frontfrq());
        root->left = pq.frontleft();
        root->right = pq.frontright();
        pq.dequeue();
    }
    generateHuffmanCode(root, "");
}

// Definition of Generate Huffman codes for each character
void Huffman::generateHuffmanCode(Node* node, string code) {
    if (node == nullptr) {
        return;
    }
    if (node->isLeaf()) {
        huffmanCode.insertLinear(node->Name, code);
    }
    generateHuffmanCode(node->left, code + "0");
    generateHuffmanCode(node->right, code + "1");
}

// Definition of Delete Huffman tree
void Huffman::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
