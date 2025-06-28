#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

// Comparator function to sort edges by weight
bool compareEdge(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

class DisjointSets
{
    vector<int> parent, rank;

public:
    DisjointSets(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // each vertex is its own parent initially
        }
    }

    // To find representation or root of the set for element u
    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    // Union operation to merge two sets
    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            // Union by rank
            if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's algorithm to compute MST
vector<Edge> kruskal(vector<Edge> &edges, int vertices)
{
    vector<Edge> mst;

    // Sort all edges in non-decreasing order by weight
    sort(edges.begin(), edges.end(), compareEdge);

    // Create disjoint set
    DisjointSets ds(vertices);

    // Iterating through all sorted edges
    for (Edge edge : edges)
    {
        int u = ds.find(edge.u);
        int v = ds.find(edge.v);

        if (u != v)
        {
            mst.push_back(edge);
            ds.unionSets(u, v);
        }
    }

    return mst;
}

int main()
{
    int v = 4; // Number of vertices
    vector<Edge> edges;

    // Constructing the graph (u, v, weight)
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    // compute MST using kruskal's algorithm
    vector<Edge> mst = kruskal(edges, v);
    cout << "u --> v \t weight\n\n";
    for (auto edge : mst)
    {
        cout << edge.u << " --> " << edge.v << " \t " << edge.weight << endl;
    }

    return 0;
}