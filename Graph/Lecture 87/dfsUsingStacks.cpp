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


    void dfs(T u){
        unordered_map<T, bool> visited;
        stack<T> s;
        s.push(u);
        visited[u]=true;
        while(!s.empty()){
            int temp = s.top();
            cout << temp << " ";
            s.pop();
            for(auto i: adj[temp]){
                if(!visited[i]){
                    s.push(i);
                    visited[i]=true;
                }
            }
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

    g.dfs(1);

    g.printGraph();
}