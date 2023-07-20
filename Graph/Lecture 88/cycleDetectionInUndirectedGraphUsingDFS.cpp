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

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    bool isCyclic(int u){
        for(auto i:adj[u]){
            if(!visited[i]){
                parent[i]=u;
                visited[i]=true;
                bool ans = isCyclic(i);
                if(ans==true){
                    return true;
                }
            }
            else if(parent[u]!=i){
                return true;
            }
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

    g.visited[1]=true;
    g.parent[1]=-1;
    cout << g.isCyclic(1) << endl;
    g.printGraph();
}