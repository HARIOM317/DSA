#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs1(int node, vector<bool> &visited, stack<int> &st, const vector<vector<int>> &adj)
{
    if (visited[node])
        return;
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs1(neighbor, visited, st, adj);
        }
    }

    st.push(node);
}

void dfs2(int node, vector<bool> &visited, const vector<vector<int>> &transpose, vector<int> &component)
{
    if (visited[node])
        return;
    visited[node] = true;

    component.push_back(node);
    for (int neighbor : transpose[node])
    {
        if (!visited[neighbor])
        {
            dfs2(neighbor, visited, transpose, component);
        }
    }
}

vector<vector<int>> kossaraju(int n, const vector<vector<int>> &adj)
{
    vector<bool> visited(n, false);
    stack<int> st;

    // First DFS - to fill the stack
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(i, visited, st, adj);
        }
    }

    // Build transposed graph
    vector<vector<int>> transpose(n);
    for (int u = 0; u < n; u++)
    {
        for (int v : adj[u])
        {
            transpose[v].push_back(u);
        }
    }

    // Mark all elements as unvisited
    fill(visited.begin(), visited.end(), false);

    // Second DFS - to find SCCs
    vector<vector<int>> sccs;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            vector<int> component;
            dfs2(node, visited, transpose, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(5);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[3].push_back(4);

    vector<vector<int>> sccs = kossaraju(n, adj);

    cout << "Strongly Connected Components : " << endl;
    for (auto component : sccs)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}