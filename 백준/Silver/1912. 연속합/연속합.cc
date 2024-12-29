#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    dp[0] = arr[0];
    for(int i=1; i<n; i++){
        dp[i]=max(arr[i],dp[i-1]+arr[i]);
    }
    
    int ans=-9999;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans;
}


//10 -4 3 1 5 6 -35 12 21 -1
//10 6 9 10 15 21 -14 12 33 32