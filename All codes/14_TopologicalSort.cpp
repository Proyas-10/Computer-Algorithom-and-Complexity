#include <bits/stdc++.h>
using namespace std;

// Kahn's algorithm
vector<int> topoKahn(const vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> indeg(n,0);
    for(int u=0;u<n;u++) for(int v:adj[u]) indeg[v]++;
    queue<int> q;
    for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
    vector<int> order;
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(int v:adj[u]) if(--indeg[v]==0) q.push(v);
    }
    if(order.size()!=n) return {}; // cycle
    return order;
}

// DFS-based topo
void dfsTopo(int u, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& order){
    vis[u]=1;
    for(int v:adj[u]) if(!vis[v]) dfsTopo(v,adj,vis,order);
    order.push_back(u);
}

vector<int> topoDFS(const vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> vis(n,0), order;
    for(int i=0;i<n;i++) if(!vis[i]) dfsTopo(i,adj,vis,order);
    reverse(order.begin(), order.end());
    return order;
}

int main(){
    vector<vector<int>> adj = {
        {1,2}, {3}, {3}, {}
    };
    auto ord1 = topoKahn(adj);
    cout<<"Kahn topo: ";
    for(int x: ord1) cout<<x<<" ";
    cout<<"\n";

    auto ord2 = topoDFS(adj);
    cout<<"DFS topo:  ";
    for(int x: ord2) cout<<x<<" ";
    cout<<"\n";
    return 0;
}