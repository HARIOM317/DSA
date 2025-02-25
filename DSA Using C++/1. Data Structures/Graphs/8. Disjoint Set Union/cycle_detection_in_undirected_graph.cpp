#include <iostream>
#include <vector>

using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initially each node is its own parent
        }
    }

    // Find operation
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union operation
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool hasCycle(vector<pair<int, int>> &edges, int vertices)
{
    DSU dsu(vertices);

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        // Find the root of u and v
        int rootU = dsu.find(u);
        int rootV = dsu.find(v);

        if (rootU == rootV)
        {
            return true; // cycle detected
        }

        // otherwise, union the two sets
        dsu.unionSets(u, v);
    }

    return false; // No cycle detected
}

int main()
{
    int vertices = 4;
    // First example
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

    if (hasCycle(edges, vertices))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    // Second example
    vertices = 5;
    edges.clear();
    edges.resize(5);
    edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};

    if (hasCycle(edges, vertices))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}