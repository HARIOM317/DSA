#include <iostream>
#include <vector>

using namespace std;

// The Floyd Warshall algorithm is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph. It works for graphs with positive or negative edge weights (but no negative cycles).

int INF = 1e9;

void floydWarshall(vector<vector<int>> &dist, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void printMatrix(vector<vector<int>> &dist, int n)
{
    cout << "Shortest distances : " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> graph = {
        {0, 3, 6, INF},
        {INF, 0, -2, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}};

    vector<vector<int>> dist = graph;

    floydWarshall(dist, n);
    printMatrix(dist, n);

    return 0;
}