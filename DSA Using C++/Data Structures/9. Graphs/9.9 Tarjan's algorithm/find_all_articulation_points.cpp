#include <iostream>
#include <vector>

using namespace std;

// Articulation Point : An articulation point (or cut vertex) is a vertex in a graph whose removal increases the number of connected components in the graph

void dfs(int node, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, int &time, vector<vector<int>> &adj)
{
    visited[node] = true;
    disc[node] = low[node] = time++;
    int children = 0;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            children++;
            parent[neighbor] = node;
            dfs(neighbor, visited, disc, low, parent, ap, time, adj);

            low[node] = min(low[node], low[neighbor]);

            // Articulation point condition for root
            if (parent[node] == -1 && children > 1)
            {
                ap[node] = true;
            }
            // Articulation point condition for non-root
            if (parent[node] != -1 && low[neighbor] >= disc[node])
            {
                ap[node] = true;
            }
        }
        else if (neighbor != parent[node])
        {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

vector<int> findArticulationPoints(vector<vector<int>> &adj, int n)
{
    vector<bool> visited(n, false);
    vector<int> disc(n, 0), low(n, 0), parent(n, -1);
    vector<bool> ap(n, false);
    int time = 0;

    // Perform DFS for each vertex
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, disc, low, parent, ap, time, adj);
        }
    }

    // Prepare result
    vector<int> result;
    for (int node = 0; node < n; node++)
    {
        if (ap[node])
        {
            result.push_back(node);
        }
    }

    return result;
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};    // vertex 0 is connected to vertex 1 and 2
    adj[1] = {0, 2};    // vertex 1 is connected to vertex 0 and 2
    adj[2] = {0, 1, 3}; // vertex 2 is connected to vertex 0, 1 and 3
    adj[3] = {2, 4};    // vertex 3 is connected to vertex 2 and 4
    adj[4] = {3};       // vertex 4 is connected to vertex 3

    vector<int> articulationPoints = findArticulationPoints(adj, n);

    cout << "Articulation Points : ";
    for (int node : articulationPoints)
    {
        cout << node << " ";
    }

    return 0;
}