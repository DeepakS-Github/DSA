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


    void bfs(T u){
        unordered_map<T, bool> visited;
        queue<T> q;
        visited[u] = true;
        q.push(u);
        while(!q.empty()){
            cout << q.front() << " ";
            for(auto i: adj[q.front()]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
            q.pop();
        }
        cout << endl;
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

    g.bfs(1);

    g.printGraph();
}