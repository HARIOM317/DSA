#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// To find the shortest path from a single source to all other nodes in a weighted graph (even with negative weights).
const int INF = INT_MAX;

struct Edge
{
    int u, v, w; // u: source, v: destination, w: weight
};

// Bellman-Ford Algorithm
vector<int> bellmanFord(vector<Edge> &edges, int vertices, int source)
{
    vector<int> distance(vertices, INF); // Initialize distance as infinite

    // Initialize source distance as 0
    distance[source] = 0;

    // Relax all edges (V-1 times)
    for (int i = 1; i <= vertices - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (distance[u] != INF && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (distance[u] != INF && distance[u] + w < distance[v])
        {
            cout << "Graph contains a negative cycle!\n";
            return {};
        }
    }

    return distance;
}

int main()
{
    int vertices = 5;
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    int source = 0;

    vector<int> shortestDistance = bellmanFord(edges, vertices, source);

    // Printing shortest distance
    for (int i = 0; i < vertices; i++)
    {
        if (shortestDistance[i] == INF)
        {
            cout << "Shortest distance (" << source << " --> " << i << ")   =   " << "INF" << endl;
        }
        else
        {
            cout << "Shortest distance (" << source << " --> " << i << ")   =   " << shortestDistance[i] << endl;
        }
    }

    return 0;
}