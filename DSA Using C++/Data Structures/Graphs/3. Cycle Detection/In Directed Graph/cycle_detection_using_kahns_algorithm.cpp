#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detectCycleKahn(vector<vector<int>> &adj, int vertices)
{
    vector<int> inDegree(vertices, 0);
    queue<int> q;
    int count = 0; // count of processed nodes

    // Step-1 : Compute in-degree of each nodes
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

    // Step-3 : Process nodes using kahn's algorithm
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        // decrease in-degree in neighbor nodes
        for (int neighbor : adj[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return count != vertices; // if count != vertices, means cycle exist
}

int main()
{
    int V = 4;
    vector<vector<int>> adj(V);

    // Directed edges forming a cycle: 0 → 1 → 2 → 3 → 1
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    if (detectCycleKahn(adj, V))
    {
        cout << "Cycle detected in the graph!\n";
    }
    else
    {
        cout << "No cycle detected.\n";
    }

    return 0;
}