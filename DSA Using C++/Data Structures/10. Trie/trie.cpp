#include <iostream>

using namespace std;

// Trie Node
class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

// Trie Class
class Trie
{
private:
    TrieNode *root;

    // Helper function for deletion
    bool deleteHelper(TrieNode *node, string word, int depth = 0)
    {
        if (!node)
            return false;

        if (depth == word.size())
        {
            if (!node->isEndOfWord)
            {
                return false;
            }
            node->isEndOfWord = false;
            return !hasChildren(node); // If no children, delete node
        }

        int index = word[depth] - 'a';
        if (deleteHelper(node->children[index], word, depth + 1))
        {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->isEndOfWord && !hasChildren(node);
        }

        return false;
    }

    // Check if a node has children
    bool hasChildren(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i])
                return true;
        }
        return false;
    }

    // Recursive function to print Trie contents
    void printHelper(TrieNode *node, string prefix)
    {
        if (node->isEndOfWord)
        {
            cout << prefix << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i])
            {
                printHelper(node->children[i], prefix + char('a' + i));
            }
        }
    }

public:
    // constructor
    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index])
            {
                // char is not present
                node->children[index] = new TrieNode(); // map char with children[index]
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search a word in the Trie
    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index])
            {
                // word is not present
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord; // (word found but can be prefix of word, so return true if isEndOfWord is true for word)
    }

    // Check if a prefix of word exists in the Trie
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (!node->children[index])
            {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }

    // Delete a word from the Trie
    void deleteWord(string word)
    {
        deleteHelper(root, word, 0);
    }

    // Print all words in the Trie
    void print()
    {
        printHelper(root, "");
    }
};

int main()
{
    Trie trie;

    // Insertion
    trie.insert("welcome");
    trie.insert("welldone");
    trie.insert("code");
    trie.insert("coder");
    trie.insert("coding");
    trie.insert("apple");
    trie.insert("applet");
    trie.insert("app");

    // Traversal
    cout << "Trie contents: " << endl;
    trie.print();

    // Searching
    cout << "\nword welcome : " << (trie.search("welcome") ? "present" : "absent") << endl;
    cout << "word apple : " << (trie.search("apple") ? "present" : "absent") << endl;
    cout << "word python : " << (trie.search("python") ? "present" : "absent") << endl;
    cout << "word person : " << (trie.search("person") ? "present" : "absent") << endl;
    cout << "word coding : " << (trie.search("coding") ? "present" : "absent") << endl;

    // Check prefixes
    cout << "\nPrefix wel : " << (trie.startsWith("wel") ? "present" : "absent") << endl;
    cout << "Prefix cod : " << (trie.startsWith("cod") ? "present" : "absent") << endl;
    cout << "Prefix ding : " << (trie.startsWith("ding") ? "present" : "absent") << endl;

    // Deletion
    trie.deleteWord("code");
    trie.deleteWord("applet");

    // Print after deletion
    cout << "\nTrie content : (After deletion)" << endl;
    trie.print();

    return 0;
}