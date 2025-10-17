#include <bits/stdc++.h>
using namespace std;

int knapsack(const vector<int>& wt, const vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            dp[i][w] = dp[i-1][w];
            if(w >= wt[i-1]) dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][w - wt[i-1]]);
        }
    }
    return dp[n][W];
}

int main(){
    vector<int> wt = {3, 4, 2, 5};
    vector<int> val = {6, 8, 4, 10};
    int W = 8;
    cout << "Max value: " << knapsack(wt, val, W) << "\n";
    return 0;
}