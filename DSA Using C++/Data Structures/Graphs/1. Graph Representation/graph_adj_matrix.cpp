#include <iostream>

using namespace std;

class Graph
{
private:
    int V;           // Number of vertices
    int **adjMatrix; // Pointer to a 2D array (adjacency matrix)
    bool direction;

public:
    Graph(int vertices, bool direction)
    {
        V = vertices;
        this->direction = direction;
        adjMatrix = new int *[V]; // dynamically allocate memory for adjacency matrix
        for (int i = 0; i < V; i++)
        {
            adjMatrix[i] = new int[V];
            // initialize adjacency matrix with 0
            for (int j = 0; j < V; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // function to add an edge between two vertices
    void addEdge(int src, int dest)
    {
        // 0 : undirected, 1 : directed
        adjMatrix[src][dest] = 1;
        if (!direction)
        {
            adjMatrix[dest][src] = 1; // for undirected graph
        }
    }

    // function to print the adjacency matrix
    void printGraph()
    {
        cout << "Adjacency Matrix : " << endl;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // destructor to deallocate memory
    ~Graph()
    {
        for (int i = 0; i < V; i++)
        {
            delete[] adjMatrix[i]; // delete each row
        }
        delete[] adjMatrix; // delete the array of pointers
    }
};

int main()
{
    Graph g(5, 0); // Creating a undirected graph with 5 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the adjacency matrix
    g.printGraph();

    return 0;
}