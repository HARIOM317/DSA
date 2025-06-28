#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

// Function to print MST
void printMST(vector<int> &parent, vector<int> &key)
{
    cout << "Edge \t\t Weight\n";
    for (int i = 1; i < parent.size(); i++)
    {
        cout << parent[i] << " --> " << i << " \t " << key[i] << endl;
    }
}

// Prim's algorithm to find Minimum Spanning Tree (MST)
void primsMST(int vertices, vector<vector<pii>> &adj)
{
    vector<int> key(vertices, INT_MAX); // to pick minimum weight of edge
    vector<int> parent(vertices, -1);   // to store constructed MST
    vector<int> inMST(vertices, false); // to represent set of vertices included in MST

    priority_queue<pii, vector<pii>, greater<pii>> pq; // {key, vertex}

    // start with the first vertex 0
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second; // vertex with minimum key
        pq.pop();

        // skip if u is already included in MST
        if (inMST[u])
            continue;

        // include u in MST
        inMST[u] = true;

        // traverse all vertices of u
        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // print the MST
    printMST(parent, key);
}

int main()
{
    int vertices = 5;
    vector<vector<pii>> adj(vertices);

    // Function to add an undirected edge b/w u and v with weight w
    auto addEdge = [&](int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    // Constructing a Graph
    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    // Run Prim's algorithm to find the MST
    primsMST(vertices, adj);

    return 0;
}