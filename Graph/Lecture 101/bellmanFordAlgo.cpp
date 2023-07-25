#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>>  adj;

    void addEdge(int u, int v, int d){
        pair<int,int> vd = make_pair(v,d);
        adj[u].push_back(vd);
    }

    void shortestDistance(int start, int end, int nodes){
        vector<int> dist(nodes+1, INT_MAX);
        dist[start] = 0;
        
        for(int i=1; i<=nodes-1; i++){
            for(auto j: adj){
                for(auto k: j.second){
                    if(dist[j.first]+k.second<dist[k.first]){
                        dist[k.first]=dist[j.first]+k.second;
                    }
                }
            }
        }

        // Check graph is negative or not
        for(auto j: adj){
            for(auto k: j.second){
                if(dist[j.first]+k.second<dist[k.first]){
                    cout << "Graph is negatve, so there is no shortes path/shortest path is negative infinte";
                    return;
                }
            }
        }

        for(int i=start; i<=end; i++){
            cout << dist[i] << " ";
        }
        cout << endl;

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
        int u,v,d;
        cin >> u >> v >> d;
        g.addEdge(u,v,d);
    }

    g.shortestDistance(1,3,vertices);
}