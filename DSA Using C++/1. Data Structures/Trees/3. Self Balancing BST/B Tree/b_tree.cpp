#include <iostream>

using namespace std;

#define ORDER 4

// B-Tree Node Class
class BTreeNode
{
public:
    int keys[ORDER - 1];        // Array of Keys
    BTreeNode *children[ORDER]; // Pointers to child nodes
    int keyCount;               // Number of keys currently in node
    bool isLeaf;                // indicates if the node is a leaf

    BTreeNode(bool leaf)
    {
        isLeaf = leaf;
        keyCount = 0;
        for (int i = 0; i < ORDER; i++)
        {
            children[i] = nullptr;
        }
    }
};

// BTree Class
class BTree
{
private:
    BTreeNode *root;

    // Utility function to insert a node
    void insertNonFull(BTreeNode *node, int key)
    {
        int i = node->keyCount - 1;

        if (node->isLeaf)
        {
            while (i >= 0 && key < node->keys[i])
            {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->keyCount++;
        }
        else
        {
            while (i >= 0 && key < node->keys[i])
            {
                i--;
            }

            i++;
            if (node->children[i]->keyCount == ORDER - 1)
            {
                splitChild(node, i, node->children[i]);
                if (key > node->keys[i])
                    i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

    // To split child node
    void splitChild(BTreeNode *parent, int index, BTreeNode *child)
    {
        int midIndex = (ORDER - 1) / 2;
        BTreeNode *newChild = new BTreeNode(child->isLeaf);
        newChild->keyCount = ORDER / 2 - 1;

        // Copy second half of keys to new child
        for (int j = 0; j < newChild->keyCount; j++)
        {
            newChild->keys[j] = child->keys[midIndex + 1 + j];
        }

        // If not a leaf, copy child pointers
        if (!child->isLeaf)
        {
            for (int j = 0; j <= newChild->keyCount; j++)
            {
                newChild->children[j] = child->children[midIndex + 1 + j];
            }
        }

        child->keyCount = midIndex;

        // Shift parent pointers to accommodate new child
        for (int j = parent->keyCount; j >= index + 1; j--)
        {
            parent->children[j + 1] = parent->children[j];
        }
        parent->children[index + 1] = newChild;

        // Move parent's keys forward
        for (int j = parent->keyCount - 1; j >= index; j--)
        {
            parent->keys[j + 1] = parent->keys[j];
        }

        // Move the middle key up
        parent->keys[index] = child->keys[midIndex];
        parent->keyCount++;
    }

    // Utility function to search a key
    BTreeNode *search(BTreeNode *node, int key)
    {
        int i = 0;
        while (i < node->keyCount && key > node->keys[i])
        {
            i++;
        }

        if (i < node->keyCount && node->keys[i] == key)
        {
            return node;
        }

        if (node->isLeaf)
            return nullptr;

        return search(node->children[i], key);
    }

    // Utility function to traverse the tree
    void traverse(BTreeNode *node)
    {
        if (node == nullptr)
            return;

        int i;
        for (i = 0; i < node->keyCount; i++)
        {
            if (!node->isLeaf)
            {
                traverse(node->children[i]);
            }
            cout << node->keys[i] << " ";
        }

        if (!node->isLeaf)
            traverse(node->children[i]);
    }

    // to free the memory
    void destroyTree(BTreeNode *node)
    {
        if (node)
        {
            if (!node->isLeaf)
            {
                for (int i = 0; i <= node->keyCount; i++)
                {
                    destroyTree(node->children[i]);
                }
            }
            delete node;
        }
    }

public:
    // constructor
    BTree()
    {
        root = nullptr;
    }

    // to insert a new key
    void insert(int key)
    {
        if (!root)
        {
            root = new BTreeNode(true);
            root->keys[0] = key;
            root->keyCount = 1;
        }
        else
        {
            if (root->keyCount == ORDER - 1)
            {
                BTreeNode *newRoot = new BTreeNode(false);
                newRoot->children[0] = root;
                splitChild(newRoot, 0, root);
                int i = (key > newRoot->keys[0]) ? 1 : 0;
                insertNonFull(newRoot->children[i], key);
                root = newRoot;
            }
            else
            {
                insertNonFull(root, key);
            }
        }
    }

    // to search a key
    bool search(int key)
    {
        return search(root, key) != nullptr;
    }

    // to traverse the tree
    void traverse()
    {
        traverse(root);
        cout << endl;
    }

    // destructor
    ~BTree()
    {
        destroyTree(root);
    }
};

int main()
{
    BTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    tree.insert(37);
    tree.insert(45);
    tree.insert(50);

    cout << "B Tree : ";
    tree.traverse();

    int key = 10;
    cout << key << " is present : " << (tree.search(key) ? "Yes" : "No") << endl;

    key = 15;
    cout << key << " is present : " << (tree.search(key) ? "Yes" : "No") << endl;

    return 0;
}
