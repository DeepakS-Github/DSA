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
    unordered_map <int, bool> dfsVisited;


    bool isCyclic(int u){
        for(auto i: adj[u]){
            if(!visited[i]){
                visited[i]=true;
                dfsVisited[i]=true;
                bool next = isCyclic(i);
                dfsVisited[i]=false;
                if(next==true){
                    return true;
                }
            }
            else if(dfsVisited[i]){
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
    g.dfsVisited[1]=true;
    cout << g.isCyclic(1) << endl;
    g.printGraph();
}