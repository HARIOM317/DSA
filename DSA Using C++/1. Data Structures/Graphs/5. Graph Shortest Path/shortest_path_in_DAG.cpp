#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj; // adjacency list

    // function to add a directed edge from 'u' to 'v' with the specific weight
    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    // DFS to perform topological sorting
    void dfs(int node, vector<bool> &visited, stack<int> &topologicalStack)
    {
        visited[node] = true;

        for (auto neighbor : adj[node])
        {
            int nextNode = neighbor.first;
            if (!visited[nextNode])
            {
                dfs(nextNode, visited, topologicalStack);
            }
        }

        topologicalStack.push(node);
    }

    // function to get topological sorting order
    stack<int> topologicalSort(int vertices)
    {
        vector<bool> visited(vertices, false);
        stack<int> st;

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st);
            }
        }

        return st;
    }

    // function to compute the shortest path from src in DAG
    vector<int> shortestPathDAG(int src, int vertices)
    {
        // Step-1 : Get the topological order of the nodes
        stack<int> st = topologicalSort(vertices);

        // Step-2 : Initialize distance to all nodes as infinite
        vector<int> dist(vertices, INT_MAX);

        dist[src] = 0; // distance from source to itself is 0

        // Step-3 : Process nodes in topological order
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX)
            {
                for (auto neighbor : adj[node])
                {
                    int nextNode = neighbor.first;
                    int weight = neighbor.second;

                    // update distance if shorter path is found
                    if (dist[node] + weight < dist[nextNode])
                    {
                        dist[nextNode] = dist[node] + weight;
                    }
                }
            }
        }

        return dist;
    }

    void printAdj()
    {
        cout << "Graph Adjacency List : \n";
        for (auto i : adj)
        {
            cout << i.first << " -> [ ";
            for (auto j : i.second)
            {
                cout << "{" << j.first << ", " << j.second << "} ";
            }
            cout << "]\n";
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int vertices = 6;
    int src = 1;

    vector<int> distance = g.shortestPathDAG(src, vertices);

    // Output the shortest distances.
    cout << "\nSOURCE : " << src << endl;
    for (int i = 0; i < vertices; i++)
    {
        if (distance[i] == INT_MAX)
        {
            cout << "Shortest distance for destination " << i << " = " << "infinite" << endl;
        }
        else
        {
            cout << "Shortest distance for destination " << i << " = " << distance[i] << endl;
        }
    }

    return 0;
}