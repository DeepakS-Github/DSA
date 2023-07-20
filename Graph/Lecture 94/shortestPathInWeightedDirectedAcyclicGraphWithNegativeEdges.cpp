#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int, int>>> adj;

    void addEdge(int u, int v, int w){
        pair<int, int> p = make_pair(v,w);
        adj[u].push_back(p);
    }

    void printGraph(){
        cout << "Printing graph: " << endl;
        for(auto i: adj){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << "[" << j.first << " " << j.second << "], ";
            }
            cout << endl;
        }
    }
};


int main(){
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g;

    for(int i=1; i<=edges; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g.addEdge(u,v,w);
    }

    g.printGraph();
}