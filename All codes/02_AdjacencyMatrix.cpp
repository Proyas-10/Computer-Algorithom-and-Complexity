#include <bits/stdc++.h>
using namespace std;

class MatrixGraph {
    int n;
    vector<vector<int>> mat;
public:
    MatrixGraph(int n): n(n), mat(n, vector<int>(n,0)) {}
    void addEdge(int u,int v,int w=1){ mat[u][v] = w; }
    void removeEdge(int u,int v){ mat[u][v] = 0; }
    bool hasEdge(int u,int v) const { return mat[u][v] != 0; }
    void print() const {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<mat[i][j]<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    MatrixGraph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    cout<<"Adjacency Matrix:\n";
    g.print();
    return 0;
}