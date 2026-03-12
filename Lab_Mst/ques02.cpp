#include <bits/stdc++.h>
using namespace std;




void solve(vector<int>&nums){
    vector<int>bitcount[32];
    for(auto x : nums){
        if(x & 1 <<bit) bitcount[x] = 1;
    }
}


int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    int l=1,h =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        h = max(h,arr[i]);
    }

    int maxoper;
    cin>>maxoper;
    int ans =0;

    while(l<=h){
        int mid = (l+h)/2;
        int count =0;
        for(auto x: arr) count = count + (x-1)/mid;

        if(count <= maxoper){
            ans = min(ans,mid);
            h = mid -1;
        }
        else l = mid +1;

    }
    cout<<ans;

    return 0;
}