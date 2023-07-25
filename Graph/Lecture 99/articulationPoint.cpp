#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(vector<bool> &visited, vector<int> &parent, vector<int> &low, vector<int> &discovery, int node, int &timer){
        timer = timer + 1;
        low[node] = timer;
        discovery[node] = timer;
        visited[node] = true;

        for(auto i: adj[node]){
            if(!visited[i]){
                parent[i] = node;
                dfs(visited, parent, low, discovery, i, timer);
            }
        }

        for(auto i: adj[node]){
            if(i!=parent[node] && low[node]>low[i]){
                low[node] = low[i];
            }
        }

        for(auto i: adj[node]){
            if(discovery[node]<=low[i] && parent[node]!=-1){
                cout << node << " ";
            }
        }


    }

    void articulationPoint(int node){
        vector<bool> visited(node,false);
        vector<int> parent(node,-1);
        vector<int> discovery(node, -1);
        vector<int> low(node, -1);

        int timer = -1;
        int startNode = 0;

        dfs(visited, parent, low, discovery, startNode, timer);

        if(adj[startNode].size()>1){
            cout << startNode << endl;
        }


    }

};

int main(){
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g;
    for(int i=0; i<edges; i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v);
    }

    cout << "Articulation point:" << endl;
    g.articulationPoint(vertices);
}