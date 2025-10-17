#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<int> vis(n,0);
    queue<int> q;
    q.push(start); vis[start]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v: adj[u]){
            if(!vis[v]){ vis[v]=1; q.push(v); }
        }
    }
    cout<<"\n";
}

int main(){
    vector<vector<int>> adj = {
        {1,2}, {0,2}, {0,1,3}, {2}
    };
    cout<<"BFS from 0: ";
    bfs(adj,0);
    return 0;
}