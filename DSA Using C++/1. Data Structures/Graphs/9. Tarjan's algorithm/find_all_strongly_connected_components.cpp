#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

    void tarjanDFS(int node, vector<int> &disc, vector<int> &low, vector<bool> &inStack, stack<int> &st, int &time, vector<vector<int>> &result)
    {
        disc[node] = low[node] = time++;
        st.push(node);        // Push the node onto the stack
        inStack[node] = true; //  Mark the node as being in the stack

        // Traverse all neighbors of the current node
        for (int neighbor : adj[node])
        {
            // If the neighbor is not visited
            if (disc[neighbor] == -1)
            {
                tarjanDFS(neighbor, disc, low, inStack, st, time, result);
                low[node] = min(low[node], low[neighbor]);
            }
            else if (inStack[neighbor])
            {
                low[node] = min(low[node], disc[neighbor]);
            }
        }

        if (low[node] == disc[node])
        {
            vector<int> scc;
            while (true)
            {
                int top = st.top();
                st.pop();
                inStack[top] = false;
                scc.push_back(top);

                if (top == node)
                    break;
            }
            result.push_back(scc); // Add the SCC to the result
        }
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    vector<vector<int>> findSCCs()
    {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        int time = 0;
        vector<vector<int>> result;

        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                tarjanDFS(i, disc, low, inStack, st, time, result);
            }
        }

        return result;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 3);

    vector<vector<int>> sccs = g.findSCCs();

    cout << "Strongly Connected Components: \n";
    for (auto scc : sccs)
    {
        for (int node : scc)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}