#include <bits/stdc++.h>
using namespace std;

struct comparator{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
};

class Graph{
    public:
    map<int, list<pair<int,int>>> adj;


    void addEdge(int u, int v, int d){
        pair<int,int> vd = make_pair(v,d); 
        pair<int,int> ud = make_pair(u,d);
        adj[u].push_back(vd);
        adj[v].push_back(ud);
    }

    void print(){
        for(auto i: adj){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << "[" << j.first << " "  << j.second << "] ";
            }
            cout << endl;
        }
        cout << endl;   
    }


    void minimumSpanningTree(int nodes){
        priority_queue<pair<int,int>> pq;
        vector<int> dist(nodes, INT_MAX);

        dist[0]=0;
        pq.push(make_pair(0,0));

        while(!pq.empty()){
            for(auto i: adj[(pq.top()).first]){
                if(i.second<dist[i.first]){
                    pq.push(i);
                    dist[i.first]=i.second;
                }
            }
            pq.pop();
        }

        for(auto i: dist){
            cout << i << " ";
        }
        cout << endl;
    }

};

int main(){
    int nodes;
    cout << "Number of nodes: ";
    cin >> nodes;

    int edges;
    cout << "Number of edges: ";
    cin >> edges;

    Graph g;

    for(int i=0; i<edges; i++){
        int u,v,d;
        cin >> u >> v >> d;
        g.addEdge(u,v,d);
    }

    g.minimumSpanningTree(nodes);
}