#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Build a Huffman Tree to generate prefix codes for characters based on their frequencies.

struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

struct cmp
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void encode(Node *root, string str, unordered_map<char, string> &ans)
{
    // base case
    if (!root->left && !root->right)
    {
        ans[root->data] = str;
        return;
    }

    // Assign codes
    encode(root->left, str + '0', ans);  // add 0 in left subtree
    encode(root->right, str + '1', ans); // add 1 in right subtree
}

unordered_map<char, string> buildHuffmanTree(string text)
{
    // Step-1 : Count freq of char
    unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }

    // Step-2 : Make a priority queue and insert the nodes
    priority_queue<Node *, vector<Node *>, cmp> pq;
    for (auto pair : freq)
    {
        Node *node = new Node(pair.first, pair.second);
        pq.push(node);
    }

    // Step-3 : Build a Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        // create tree
        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // push new node into pq
        pq.push(newNode);
    }

    // Step-4 : Encode the data
    Node *root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    return huffmanCode;
}

int main()
{
    string text = "aabbbcccddddeeeefffff";
    unordered_map<char, string> huffmanCode = buildHuffmanTree(text);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << endl;

    return 0;
}