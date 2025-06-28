#include <iostream>
#include <vector>

using namespace std;

bool DFS(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            bool cycleDetected = DFS(neighbor, node, adj, visited);
            if (cycleDetected)
                return true;
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }

    return false;
}

bool cycleDetection(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> adj(n + 1);

    // Build adjacency list
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    // Check each component for a cycle
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (DFS(i, -1, adj, visited))
                return true;
        }
    }

    return false;
}

int main()
{
    // First test case : No cycle
    int vertices = 5;
    vector<vector<int>> edges1 = {
        {1, 2},
        {2, 3}, // Component 1
        {4, 5}  // Component 2
    };

    if (cycleDetection(edges1, vertices))
    {
        cout << "Cycle present in Graph 1" << endl;
    }
    else
    {
        cout << "No any cycle present in Graph 1" << endl;
    }

    // First test case : Cycle
    vertices = 6;
    vector<vector<int>> edges2 = {
        {1, 4},
        {4, 3},
        {3, 1}, // Component 1 (Cyclic component)
        {5, 6}  // Component 2
    };

    if (cycleDetection(edges2, vertices))
    {
        cout << "Cycle present in Graph 2" << endl;
    }
    else
    {
        cout << "No any cycle present in Graph 2" << endl;
    }

    return 0;
}