#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    // creating an undirected edge between u and v vertices
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        // recursively visit all unvisited neighbors
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        cout << "DFS Traversal : ";

        DFSUtil(start, visited); // start DFS from given node
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.DFS(0); // Start DFS from node 0

    return 0;
}