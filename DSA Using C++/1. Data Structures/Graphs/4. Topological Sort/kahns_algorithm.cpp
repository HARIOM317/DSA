#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform topological sorting using kahn's algorithm
vector<int> kahnTopologicalSort(vector<vector<int>> &adj, int vertices)
{
    vector<int> inDegree(vertices, 0);
    vector<int> topologicalOrder;
    queue<int> q;

    // Step-1 : Compute in-degree of each node
    for (int i = 0; i < vertices; i++)
    {
        for (int j : adj[i])
        {
            inDegree[j]++;
        }
    }

    // Step-2 : Enqueue all nodes with in-degree 0
    for (int i = 0; i < vertices; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Step-3 : Process the queue
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topologicalOrder.push_back(node);

        // Decrease in-degree of neighbor
        for (int neighbor : adj[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return topologicalOrder;
}

int main()
{
    int vertices = 6;
    vector<vector<int>> adj(vertices);

    // creating directed graph (u -> v)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = kahnTopologicalSort(adj, vertices);

    cout << "Topological order : ";
    for (int v : result)
    {
        cout << v << " ";
    }

    return 0;
}