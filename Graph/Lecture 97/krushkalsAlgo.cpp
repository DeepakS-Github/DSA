#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<int>> gp;
    vector<int> parent;
    vector<int> rank;

    Graph(int nodes)
    {
        parent.resize(nodes + 1);  // Resize the vector to accommodate 'nodes' number of elements.
        rank.resize(nodes + 1, 0); // Resize and initialize the rank vector to 0.
        for (int i = 0; i <= nodes; i++)
        {
            parent[i] = i;
        }
    }

    void addEdge(int u, int v, int d)
    {
        vector<int> r;
        r.push_back(u);
        r.push_back(v);
        r.push_back(d);
        gp.push_back(r);
    }

    int findParent(int index)
    {
        if (index == parent[index])
        {
            return index;
        }

        return parent[index] = findParent(parent[index]);
    }

    void unionSet(int index1, int index2, int nodes)
    {
        int index1Parent = findParent(index1);
        int index2Parent = findParent(index2);
        if (rank[index1Parent] == rank[index2Parent])
        {
            parent[index2Parent] = index1Parent;
            rank[index1Parent]++;
        }
        else if (rank[index1Parent] > rank[index2Parent])
        {
            parent[index2Parent] = index1Parent;
        }
        else
        {
            parent[index1Parent] = index2Parent;
        }
    }

    bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    int krushkals(int edges, int nodes)
    {

        sort(gp.begin(), gp.end(), [](const vector<int> &a, const vector<int> &b){ return a[2] < b[2]; });

        int ans = 0;
        for (int i = 0; i < edges; i++)
        {
            if (findParent(gp[i][0]) != findParent(gp[i][1]))
            {
                cout << gp[i][0] << " " << gp[i][1] << " " << gp[i][2] << endl;
                ans = ans + gp[i][2];
                unionSet(gp[i][0], gp[i][1], nodes);
            }
        }
        return ans;
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

    Graph g(vertices);

    for (int i = 0; i < edges; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        g.addEdge(u, v, d);
    }

    cout << g.krushkals(edges, vertices);
}