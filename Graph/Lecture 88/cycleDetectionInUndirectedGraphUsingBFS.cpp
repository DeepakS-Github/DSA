#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Graph{
    public:
    unordered_map<T,list<T>> adj;

    void addEdge(T u, T v, T type){
        // type = 0;   // Undirected graph
        // type = 1;   // Directed graph

        adj[u].push_back(v);
        if(type==0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }


    bool isCyclic(int u){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        
        q.push(u);
        parent[u] = -1;
        visited[u] = true;

        while(!q.empty()){
            for(auto i: adj[q.front()]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    parent[i]=q.front();
                }
                else if(parent[q.front()]!=i){
                    return true;
                }
            }
            q.pop();
        }
        return false;
    }

    
};

int main(){
    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    Graph <int> g;

    for(int i=0; i<edge; i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }

    cout << g.isCyclic(1) << endl;
    g.printGraph();
}