#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    map<int, list<int>> adj;
    map<int, list<int>> transposeadj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void dfs(int node, vector<bool> &visited, stack<int> &st){
        visited[node]=true;
        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(i, visited, st);
            }
        }
        st.push(node);
        return;
    }

    void transposeOfGraph(){
        for(auto i: adj){
            for(auto j: i.second){
                transposeadj[j].push_back(i.first);
            }
        }
    }

    void ans(int node, vector<bool> &visited){
        cout << node << " ";
        visited[node]=true;
        for(auto i: transposeadj[node]){
            if(!visited[i]){
                ans(i, visited);
            }
            else{
                cout << endl;
            }
        }
        return;
    }

    void topoOrder(int nodes){
        vector<bool> visited(nodes);
        stack<int> st;

        for(int i=0; i<nodes; i++){
            if(!visited[i]){
                dfs(i, visited, st);
            }
        }

        transposeOfGraph();

        for(int i=0; i<nodes; i++){
            visited[i]=false;
        }

        cout << "-----------------------------------------" << endl;
        while(!st.empty()){
            if(!visited[st.top()]){
                ans(st.top(), visited);
            }
            st.pop();
        }
        
    }
   
};

int main(){
    Graph g;
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for(int i=0; i<edges; i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v);
    }   

    g.topoOrder(vertices);

    
}