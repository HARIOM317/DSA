#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> &graph, int N)
{
    vector<int> color(N, -1); // -1 means uncolored

    for (int i = 0; i < N; i++)
    {
        if (color[i] == -1)
        { // If node is uncolored
            queue<int> q;
            q.push(i);
            color[i] = 0; // Start coloring with 0

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node])
                {
                    if (color[neighbor] == -1)
                    {
                        color[neighbor] = 1 - color[node]; // opposite color
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node])
                    {
                        return false; // Same color conflict
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    // Example 1 - Bipartite Graph
    vector<vector<int>> graph = {
        {1, 3}, // Node 0 is connected to 1 and 3
        {0, 2}, // Node 1 is connected to 0 and 2
        {1, 3}, // Node 2 is connected to 1 and 3
        {0, 2}, // Node 3 is connected to 0 and 2
    };

    int N = graph.size();

    if (isBipartite(graph, N))
    {
        cout << "The graph is bipartite" << endl;
    }
    else
    {
        cout << "The graph is not bipartite" << endl;
    }

    // Example 2: Non-bipartite graph (contains odd-length cycle)
    vector<vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    N = graph2.size();

    if (isBipartite(graph2, N))
    {
        cout << "The graph is bipartite" << endl;
    }
    else
    {
        cout << "The graph is not bipartite" << endl;
    }

    return 0;
}