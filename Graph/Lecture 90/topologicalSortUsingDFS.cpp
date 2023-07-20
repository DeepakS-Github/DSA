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
        if(type==1){
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

    unordered_map <int, bool> visited;
    stack<int> topologicalSort;


    void dfs(int u){
        visited[u]=true;
        for(auto i: adj[u]){
            if(!visited[i]){
                dfs(i);
            }
        }
        topologicalSort.push(u);
    }

    void printStack(){
        while(!topologicalSort.empty()){
            cout << topologicalSort.top() << " ";
            topologicalSort.pop();
        }
        cout << endl;
    }
    

    
};

int main(){
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    Graph <int> g;

    for(int i=0; i<edge; i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }

    for(int i=1; i<=vertices; i++){
        if(!g.visited[i]){
            g.dfs(i);
        }
    }
    g.printStack();



    g.printGraph();
}