#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, T type)
    {
        // type = 0;   // Directed graph
        // type = 1;   // Undirected graph

        adj[u].push_back(v);
        if (type == 1)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void shortestPathUtil(int visited[], int parent[], queue<int> q)
    {
        while (!q.empty())
        {
            for (auto i : adj[q.front()])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = q.front();
                }
            }
            q.pop();
        }
    }

    void shortestPath(int v, int start, int end)
    {
        int visited[v + 1] = {0};
        int parent[v + 1] = {0};
        queue<int> q;
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = -1;
                shortestPathUtil(visited, parent, q);
            }
        }

        for (int i = 1; i <= v; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;

        while (end!=-1){
            cout << end << " ";
            end = parent[end];
        }
    }
};

int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    Graph<int> g;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }

    g.shortestPath(vertices, 1, 8);

    // g.printGraph();
}