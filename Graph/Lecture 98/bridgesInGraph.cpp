#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void dfs(vector<bool> &visited, int node, int &timer, vector<int> &discovery, vector<int> &lowestTimeNeighbour, vector<int> &parent)
    {
        timer = timer + 1;
        visited[node] = true;
        discovery[node] = timer;
        lowestTimeNeighbour[node] = timer;
        for (auto i : adj[node])
        {
            if (!visited[i])
            { // Corrected from !visited[node] to !visited[i]
                parent[i] = node;
                dfs(visited, i, timer, discovery, lowestTimeNeighbour, parent); // Corrected from node to i
            }
        }

        if (parent[node] != -1)
        {
            for (auto i : adj[node])
            {
                if(i!=parent[node] && lowestTimeNeighbour[node]>lowestTimeNeighbour[i]){
                    lowestTimeNeighbour[node]=lowestTimeNeighbour[i];
                }
            }

            if (discovery[parent[node]] < lowestTimeNeighbour[node])
            {
                cout << parent[node] << " - " << node << endl;
            }
        }
    }

    void findBridge(int nodes)
    {
        vector<int> discovery(nodes, -1);
        vector<int> lowestTimeNeighbour(nodes, -1);
        vector<int> parent(nodes, -1);

        vector<bool> visited(nodes, false);
        int timer = -1;

        for (int i = 0; i < nodes; ++i)
        {
            if (!visited[i])
            {
                dfs(visited, i, timer, discovery, lowestTimeNeighbour, parent);
            }
        }
    }
};

int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Bridges are: " << endl;

    g.findBridge(vertices);
}