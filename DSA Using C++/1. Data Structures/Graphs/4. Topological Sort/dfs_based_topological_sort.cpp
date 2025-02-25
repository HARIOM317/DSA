#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and push nodes onto the stack
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, st);
        }
    }

    st.push(node); // after visiting all neighbor, push this node onto the stack
}

void topologicalSort(int vertices, vector<vector<int>> &adj)
{
    stack<int> st;
    vector<bool> visited(vertices, false);

    // Perform DFS for each unvisited node
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    // Print the topological order by popping elements from the stack
    while (!st.empty())
    {
        int node = st.top();
        cout << node << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    int vertices = 7;
    vector<vector<int>> adj(vertices);

    // Defining ther Graph (Adjacency List Representation)
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[4].push_back(6);

    cout << "Topological sort order : ";
    topologicalSort(vertices, adj);

    return 0;
}