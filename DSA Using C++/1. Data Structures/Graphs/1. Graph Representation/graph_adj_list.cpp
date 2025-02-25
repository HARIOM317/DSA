#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 : undirected graph
        // direction = 1 : directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        // create an edge from v to u if undirected
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // function to print adjacency list
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> [ ";
            for (int j : i.second)
            {
                cout << j << " ";
            }
            cout << "]" << endl;
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(10, 20, 1);
    g.addEdge(10, 30, 1);
    g.addEdge(10, 40, 1);
    g.addEdge(20, 20, 1);
    g.addEdge(20, 30, 1);
    g.addEdge(20, 50, 1);
    g.addEdge(20, 60, 1);
    g.addEdge(30, 40, 1);
    g.addEdge(40, 50, 1);
    g.addEdge(40, 20, 1);
    g.addEdge(50, 60, 1);
    g.addEdge(60, 10, 1);
    g.addEdge(60, 30, 1);

    g.printAdjList();

    return 0;
}