#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V; // No. of vertices

    // Pointer to a list containing adjacency list
    list<int> *adj;

    // Vector to store indegree of vertices
    vector<int> indegree;

    // function returns a topological sort
    vector<int> topologicalSort();

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // Prints all edges that can be added without making any
    // cycle
    void maximumEdgeAddition();
};

//  Constructor of graph
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    // Initialising all indegree with 0
    for (int i = 0; i < V; i++)
        indegree.push_back(0);
}

//  Utility function to add edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.

    // increasing inner degree of w by 1
    indegree[w]++;
}

//  Main function to print maximum edges that can be added
vector<int> Graph::topologicalSort()
{
    vector<int> topological;
    queue<int> q;

    //  In starting push all node with indegree 0
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        //  push the node into topological vector
        topological.push_back(t);

        //  reducing indegree of adjacent vertices
        for (list<int>::iterator j = adj[t].begin();
             j != adj[t].end(); j++)
        {
            indegree[*j]--;

            //  if indegree becomes 0, just push
            // into queue
            if (indegree[*j] == 0)
                q.push(*j);
        }
    }
    return topological;
}

//  The function prints all edges that can be
//  added without making any cycle
//  It uses recursive topologicalSort()
void Graph::maximumEdgeAddition()
{
    bool *visited = new bool[V];
    vector<int> topo = topologicalSort();

    //  looping for all nodes
    for (int i = 0; i < topo.size(); i++)
    {
        int t = topo[i];

        //  In below loop we mark the adjacent node of t
        for (list<int>::iterator j = adj[t].begin();
             j != adj[t].end(); j++)
            visited[*j] = true;

        //  In below loop unmarked nodes are printed
        for (int j = i + 1; j < topo.size(); j++)
        {
            // if not marked, then we can make an edge
            // between t and j
            if (!visited[topo[j]])
                cout << t << "-" << topo[j] << " ";

            visited[topo[j]] = false;
        }
    }
}

// Driver code to test above methods
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.maximumEdgeAddition();
    return 0;
}