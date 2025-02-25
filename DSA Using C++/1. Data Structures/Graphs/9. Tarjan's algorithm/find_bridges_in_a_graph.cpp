#include <iostream>
#include <vector>

using namespace std;

// Bridges : A bridge (also called a cut edge) in a graph is a edge by whose removal the graph becomes disconnected (or divided into two or more components).

class Graph
{
    int V;
    vector<vector<int>> adj;

    void dfs(int node, int parent, int &time, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<pair<int, int>> &bridges)
    {
        visited[node] = true;
        disc[node] = low[node] = time++;

        for (int neighbor : adj[node])
        {
            if (neighbor == parent)
                continue;

            if (!visited[neighbor])
            {
                dfs(neighbor, node, time, visited, disc, low, bridges);

                low[node] = min(low[node], low[neighbor]);

                // Check for bridge
                if (low[neighbor] > disc[node])
                {
                    bridges.push_back({node, neighbor});
                }
            }
            else
            {
                // Back edge: update low value of current node
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> findBridges()
    {
        vector<bool> visited(V, false);
        vector<int> disc(V, 0), low(V, 0);
        vector<pair<int, int>> bridges;
        int time = 0, parent = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, parent, time, visited, disc, low, bridges);
            }
        }

        return bridges;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    vector<pair<int, int>> bridges = g.findBridges();

    cout << "Bridges in the graph:\n";
    for (auto bridge : bridges)
    {
        cout << bridge.first << " --> " << bridge.second << endl;
    }

    return 0;
}