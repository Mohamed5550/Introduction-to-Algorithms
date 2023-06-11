#include <bits/stdc++.h>

using namespace std;
struct Node {
    Node *left = NULL;
    Node *right = NULL;
    int freq;
    char item;
};

struct NodeComparator {
    bool operator() (Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

struct HuffmanTree {
    Node *root = NULL;
    int count = 0; // count of all characters
};

string readFile(string fileName)
{
    ifstream file;
    file.open(fileName);

    int i = 0;
    string line;
    string s;
    while(getline(file, line)) {
        if(i > 0) s += '\n';
        s += line;
        i ++;
    }

    file.close();

    return s;
}

HuffmanTree *generateHuffmanTree(string &text, map<char, int> &freq)
{
    for(auto i: text) freq[i] ++;

    priority_queue<Node *, vector <Node *>, NodeComparator> pq;
    for(auto i: freq) {
        Node *temp = new Node;
        temp->freq = i.second;
        temp->item = i.first;

        pq.push(temp);
    }

    for(int i = 1; i < freq.size(); i ++) {
        Node *temp = new Node;
        Node *x = pq.top(); pq.pop();
        Node *y = pq.top(); pq.pop();
        temp->left = x;
        temp->right = y;
        temp->freq = x->freq + y->freq;
        
        pq.push(temp);
    }

    HuffmanTree *temp = new HuffmanTree;
    temp->root = pq.top();

    return temp;

}

void dfs(Node *node, string s, map<char, string> &charCodes)
{
    if(node->left == NULL && node->right == NULL) {
        charCodes[node->item] = s;
        return;
    }

    dfs(node->left, s+'0', charCodes);
    dfs(node->right, s+'1', charCodes);
}

string optimizeText(HuffmanTree *huffman, string &text, map<char, int> &freq)
{
    map <char, string> charCodes;
    dfs(huffman->root, "", charCodes);

    for(auto i: charCodes) {
        huffman->count += i.second.size() * freq[i.first];
    }
    string optimized;
    for(auto i: text) {
        optimized += charCodes[i];
    }

    return optimized;
}

string textToBinary(string &text)
{
    string s;
    for(auto i: text)
    {
        bitset<8> binary(i);
        s += binary.to_string();
    }   

    return s;
}

string getOriginalText(HuffmanTree *huffman, string &text)
{
    string original;
    Node *iterator = huffman->root;

    string originalText = textToBinary(text);
    while(originalText.size() > huffman->count) originalText.pop_back();
    
    for(auto i: originalText) {
        if(i == '0') {
            iterator = iterator->left;
        } else {
            iterator = iterator->right;
        }

        if(iterator->item != '\0') {
            original += iterator->item;
            iterator = huffman->root;
        }
    }

    return original;
}

char writeByte(string s)
{
    while(s.size() < 8) s += '0';
    bitset<8> binary(s);
    unsigned long decimal = binary.to_ulong();

    // Convert unsigned long to char
    char character = static_cast<char>(decimal);

    return character;
}

string encodeAndWrite(string &s)
{
    string temp;
    string s2;
    for(auto i: s) {
        if(temp.size() == 8) {
            s2 += writeByte(temp);
            temp = "";
        }

        temp += i;
    }

    if(temp.size()) s2 += writeByte(temp);
    return s2;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // read the file
    string text = readFile("original.txt");

    // building Huffman Tree
    map<char, int> freq;
    HuffmanTree *huffman = generateHuffmanTree(text, freq);

    // compress the file and write it to the compressed file
    ofstream compressedFile;
    compressedFile.open("compressed.txt");

    string optimized = optimizeText(huffman, text, freq);
    compressedFile << encodeAndWrite(optimized);
    compressedFile.close();

    // decompress the file and write it into a new file
    string optimizedText = readFile("compressed.txt");

    ofstream UncompressedFile;
    UncompressedFile.open("uncompressed.txt");


    string unoptimized = getOriginalText(huffman, optimizedText);
    UncompressedFile << unoptimized;

    UncompressedFile.close();
}