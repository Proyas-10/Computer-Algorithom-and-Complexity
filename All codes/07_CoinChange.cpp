#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int minCoins(const vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INF);
    dp[0] = 0;
    for(int c: coins)
        for(int x=c; x<=amount; x++)
            dp[x] = min(dp[x], dp[x-c] + 1);
    return dp[amount] >= INF ? -1 : dp[amount];
}

int main(){
    vector<int> coins = {1,3,4};
    int amount = 6;
    cout << "Min coins for " << amount << ": " << minCoins(coins, amount) << "\n";
    return 0;
}