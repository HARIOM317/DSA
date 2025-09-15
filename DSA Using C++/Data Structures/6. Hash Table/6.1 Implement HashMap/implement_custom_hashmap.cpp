#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;

    // constructor
    Node(string key, int val)
    {
        this->key = key;
        this->value = val;
        this->next = nullptr;
    }

    // destructor
    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

class HashTable
{
    int totalSize;
    int currSize; // to perform re-hashing
    Node **table;

    // hash function to get hash index
    int hashFunction(string key)
    {
        int idx = 0;
        for (int i = 0; i < key.size(); i++)
        {
            idx = idx + (key[i] * key[i]) % totalSize;
        }
        return idx % totalSize;
    }

    // re-hashing hash table --> O(n)
    void rehashing()
    {
        Node **oldTable = table;
        int oldSize = totalSize;

        totalSize = 2 * totalSize;
        currSize = 0;

        table = new Node *[totalSize]; // declare new table with double size

        // initialize new table with NULL pointers
        for (int i = 0; i < totalSize; ++i)
        {
            table[i] = nullptr;
        }

        // copy old data
        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldTable[i]; // head pointer
            while (temp != nullptr)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            // delete old nodes
            if (oldTable[i] != nullptr)
            {
                delete oldTable[i];
            }
        }

        // delete old table
        delete[] oldTable;
    }

public:
    // constructor
    HashTable(int size = 5)
    {
        totalSize = size;
        currSize = 0;
        table = new Node *[totalSize];

        // initialize table with NULL pointers
        for (int i = 0; i < totalSize; i++)
        {
            table[i] = nullptr;
        }
    }

    // destructor
    ~HashTable()
    {
        for (int i = 0; i < totalSize; i++)
        {
            if (table[i] != nullptr)
            {
                delete table[i]; // Node destructor recursively deletes chain
            }
        }
        delete[] table;
    }

    // __________ Hashmap operations __________

    // Avg: O(1), Worst: O(n) (when re-hashing)
    void insert(string key, int val)
    {
        int idx = hashFunction(key);

        Node *newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double threshold = currSize / (double)totalSize;
        if (threshold > 0.7)
        {
            rehashing(); // perform re-hashing, when size crossed threshold value
        }
    }

    // find is key present or not
    bool find(string key)
    {
        int idx = hashFunction(key);
        Node *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // get value bu key
    int at(string key)
    {
        int idx = hashFunction(key);
        Node *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    // remove data
    void erase(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        Node *prev = nullptr;

        while (temp)
        {
            if (temp->key == key)
            {
                if (prev == nullptr)
                { // head
                    table[idx] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                currSize--;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    // get size of table
    int size()
    {
        return this->currSize;
    }

    // _____ OTHER _____
    // print hash table
    void print()
    {
        cout << "\n";
        for (int i = 0; i < totalSize; i++)
        {
            Node *temp = table[i];
            if (temp)
            {
                cout << i << " : [ ";
                while (temp)
                {
                    cout << "(" << temp->key << "," << temp->value << ")" << " -> ";

                    temp = temp->next;
                }
                cout << "NULL ]" << endl;
            }
        }
        cout << endl;
    }
};

int main()
{
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("China", 140);
    ht.insert("USA", 50);
    ht.insert("UK", 45);
    ht.insert("Russia", 40);
    ht.insert("Nepal", 20);

    ht.print();
    cout << "Size: " << ht.size() << endl;

    // get value by key
    cout << "Value at India: " << ht.at("India") << endl;
    cout << "Value at Canada: " << ht.at("Canada") << endl;

    // check whther key is present or not
    cout << "Is USA present: " << (ht.find("USA") ? "Yes" : "No") << endl;

    // delete data
    ht.erase("USA");
    ht.erase("China");
    ht.erase("Nepal");

    ht.print();
    cout << "Size: " << ht.size() << endl;

    cout << "Is USA present: " << (ht.find("USA") ? "Yes" : "No") << endl;

    return 0;
}