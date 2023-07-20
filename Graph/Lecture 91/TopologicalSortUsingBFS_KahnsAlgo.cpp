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

    
    void topoSort(int v){
        int indegree[v+1]={0};
        
        queue<int> q;

        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }

        for(int i=1; i<=v; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            cout << q.front() << " ";
            for(auto i: adj[q.front()]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            q.pop();
        }


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

    g.topoSort(vertices);




    // g.printGraph();
}