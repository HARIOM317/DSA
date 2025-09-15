#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    // createing undirected graph
    void addEdge(int u, int v)
    {
        adj[u].push_back(v); // edge from u to v
        adj[v].push_back(u); // edge from v to u
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false); // To keep track of visited nodes
        queue<int> q;                   // for BFS traverse

        // starts from vertex start
        visited[start] = true;
        q.push(start);

        cout << "BFS traversal : ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " "; // print the node

            // visit all adjacent nodes
            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(6); // creating a graph with 6 vertices (0 to 5)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.BFS(0); // starts BFS from node 0

    return 0;
}