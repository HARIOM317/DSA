#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v); // directed graph
    }

    bool dfs(int node, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, visited, recStack))
                {
                    return true; // cycle detected
                }
            }
            else if (recStack[neighbor])
            {
                return true; // cycle detected
            }
        }

        recStack[node] = false; // Backtrack (Remove node from recursive stack)

        return false;
    }

    bool hasCycle()
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 2); // This edge creates a cycle

    if (g.hasCycle())
    {
        cout << "Cycle detected in the graph!" << endl;
    }
    else
    {
        cout << "No cycle in the graph." << endl;
    }

    return 0;
}