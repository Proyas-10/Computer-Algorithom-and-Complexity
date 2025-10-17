#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

int partition_(vector<int>& a,int l,int r){
    int pivot = a[r], i=l-1;
    for(int j=l;j<r;j++){
        if(a[j] <= pivot){
            i++; swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quickSort(vector<int>& a,int l,int r){
    if(l<r){
        int p = partition_(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

int main(){
    vector<int> a1 = {5,1,4,2,8};
    bubbleSort(a1);
    cout<<"Bubble: "; for(int x: a1) cout<<x<<" "; cout<<"\n";

    vector<int> a2 = {10,7,8,9,1,5};
    quickSort(a2,0,a2.size()-1);
    cout<<"Quick:  "; for(int x: a2) cout<<x<<" "; cout<<"\n";
    return 0;
}