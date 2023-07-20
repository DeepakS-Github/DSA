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


    void shortestPath(int nodes){
        vector<int> sDist(nodes);
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> pq;

        for(int i=0; i<nodes; i++){
            sDist[i] = INT_MAX;
        }

        pq.push(make_pair(0,0));
        sDist[0] = 0;
        
        while(!pq.empty()){
            pair <int,int> mini = pq.top();
            for(auto i: adj[mini.first]){
                int dist = i.second + mini.second;
                if(sDist[i.first]>dist){
                    sDist[i.first]=dist;
                    pq.push(make_pair(i.first, dist));
                }
            }
            pq.pop();
        }

        for(int i=0; i<nodes; i++){
            cout << sDist[i] << " ";
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
    g.print();

    g.shortestPath(nodes);
}