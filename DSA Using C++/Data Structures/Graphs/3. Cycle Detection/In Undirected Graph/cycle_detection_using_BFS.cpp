#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfsCycleDetection(vector<vector<int>> &graph, int start, vector<bool> &visited)
{
    queue<pair<int, int>> q; // pair of (current_node, parent_node)

    q.push({start, -1}); // starting node has no parent
    visited[start] = true;

    while (!q.empty())
    {
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : graph[curr])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push({neighbor, curr});
            }
            else if (neighbor != parent)
            {
                return true; // cycle detected
            }
        }
    }

    return false; // no cycle found
}

bool detectCycle(vector<vector<int>> &graph, int vertices)
{
    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            if (bfsCycleDetection(graph, i, visited))
                return true;
        }
    }

    return false;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> graph(vertices);

    // Component 1 (Cyclic component)
    // Edge between 0 and 1
    graph[0].push_back(1);
    graph[1].push_back(0);

    // Edge between 0 and 2
    graph[0].push_back(2);
    graph[2].push_back(0);

    // Edge between 1 and 2
    graph[1].push_back(2);
    graph[2].push_back(1);

    // Component 2
    // Edge between 3 and 4
    graph[3].push_back(4);
    graph[4].push_back(3);

    if (detectCycle(graph, vertices))
    {
        cout << "Graph contains a cycle" << endl;
    }
    else
    {
        cout << "Graph doesn't contains a cycle" << endl;
    }

    return 0;
}