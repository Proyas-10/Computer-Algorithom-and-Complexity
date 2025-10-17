#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int u, const vector<vector<int>>& adj, vector<int>& vis) {
    vis[u]=1;
    cout<<u<<" ";
    for(int v: adj[u]) if(!vis[v]) dfsUtil(v, adj, vis);
}

void dfs(const vector<vector<int>>& adj, int start) {
    vector<int> vis(adj.size(), 0);
    dfsUtil(start, adj, vis);
    cout<<"\n";
}

int main(){
    vector<vector<int>> adj = {
        {1,2}, {0,2}, {0,1,3}, {2}
    };
    cout<<"DFS from 0: ";
    dfs(adj,0);
    return 0;
}