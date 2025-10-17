#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;

int main(){
    int n = 4;
    vector<vector<long long>> d(n, vector<long long>(n, INF));
    for(int i=0;i<n;i++) d[i][i]=0;
    d[0][1]=5; d[0][3]=10;
    d[1][2]=3;
    d[2][3]=1;

    for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if(d[i][k] + d[k][j] < d[i][j])
            d[i][j] = d[i][k] + d[k][j];

    cout<<"Distance matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]>=INF/2) cout<<"INF ";
            else cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}