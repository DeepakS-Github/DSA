#include <bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, T type){
        // type = 0 // for directed
        // type = 1 // for undirected

        adj[u].push_back(v);

        if(type==1){
            adj[v].push_back(u);
        }
    }


    void printGraph(){
        for(auto i:adj){
            cout << i.first << " -> ";
            for(auto j:i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){
    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    Graph<int> g;

    for(int j=0; j<edge; j++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }

    g.printGraph();
}