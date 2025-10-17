#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<pair<double,int>> ratio(n);
    for(int i=0;i<n;i++) ratio[i] = { (double)val[i]/wt[i], i };
    sort(ratio.rbegin(), ratio.rend());
    double total = 0;
    for(auto &p: ratio){
        if(W==0) break;
        int i = p.second;
        if(wt[i] <= W){
            total += val[i];
            W -= wt[i];
        } else {
            total += p.first * W;
            W = 0;
        }
    }
    return total;
}

int main(){
    vector<int> wt = {10, 40, 20, 30};
    vector<int> val = {60, 40, 100, 120};
    int W = 50;
    cout << "Max value (fractional): " << fractionalKnapsack(wt,val,W) << "\n";
    return 0;
}