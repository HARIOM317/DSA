#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // create distance array and initialize with infinite
    dist[source] = 0;             // set distance from source to itself to 0

    // Create Min-Heap : (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currDist = pq.top().first;
        int currNode = pq.top().second;

        pq.pop();

        // Skip outdated entries
        if (currDist > dist[currNode])
            continue;

        // Update neighbor
        for (auto neighbor : graph[currNode])
        {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            int newDist = currDist + weight;

            if (newDist < dist[nextNode])
            {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    return dist;
}

int main()
{
    int vertices = 4;
    vector<vector<pair<int, int>>> graph(vertices);

    graph[0].push_back({1, 40}); // Edge 0 --> 1 with weight 40
    graph[0].push_back({2, 10}); // Edge 0 --> 2 with weight 10
    graph[2].push_back({1, 20}); // Edge 2 --> 1 with weight 20
    graph[1].push_back({3, 10}); // Edge 1 --> 3 with weight 10
    graph[2].push_back({3, 50}); // Edge 2 --> 3 with weight 50

    int source = 0;
    vector<int> distance = dijkstra(graph, source);

    // printing output
    cout << "SOURCE = " << source << endl;

    for (int i = 0; i < vertices; i++)
    {
        cout << "Shortest distance " << source << " --> " << i << " = " << distance[i] << endl;
    }

    return 0;
}