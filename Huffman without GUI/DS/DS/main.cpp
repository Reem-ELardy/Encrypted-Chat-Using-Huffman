#include <iostream>
#include <string>
#include "HuffmanHeader.h"

using namespace std;

int main() {
    string text;
    cout << "Write a text" << endl;
    getline(cin, text);
    Huffman huffmann;
    huffmann.buildTree(text);
    string encodedText = huffmann.encode(text);
    string decodedText = huffmann.decode(encodedText);
    cout << "Original text: " << text << endl;
    cout << "Encoded  text: " << encodedText << endl;
    cout << "Decoded text: " << decodedText << endl;
    return 0;
}
