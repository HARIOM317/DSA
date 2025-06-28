#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
private:
    vector<int> parent; // Stores te parent of each element
    vector<int> rank;   // Stores the rank (depth) of each tree

public:
    // Constructor to initialize the Union-Find data structure
    UnionFind(int size)
    {
        parent.resize(size);
        rank.resize(size, 1); // Initially, each set has rank 1

        for (int i = 0; i < size; i++)
        {
            parent[i] = i; // initially each element is its own parent
        }
    }

    // Find operation with Path Compression
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union operation with Union by Rank
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            // Attach the smaller rank tree under the root of the larger rank tree
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX] += 1; // Increase rank if ranks are equal
            }
        }
    }

    // Check if two elements are in the same set
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    UnionFind uf(10); // Create a Union-Find structure for 10 elements

    uf.unionSets(1, 2);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);
    uf.unionSets(5, 6);
    uf.unionSets(5, 7);
    uf.unionSets(7, 8);
    uf.unionSets(8, 9);
    uf.unionSets(9, 0);

    cout << "Are 1 and 3 connected? " << (uf.connected(1, 3) ? "Yes" : "No") << endl;
    cout << "Are 1 and 4 connected? " << (uf.connected(1, 4) ? "Yes" : "No") << endl;
    cout << "Are 4 and 9 connected? " << (uf.connected(4, 9) ? "Yes" : "No") << endl;
    cout << "Are 4 and 0 connected? " << (uf.connected(4, 0) ? "Yes" : "No") << endl;

    return 0;
}