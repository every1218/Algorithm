#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int arr[1001];
    int dp[1001];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int mx=0;
    dp[0]=1;
    
    for(int i=1; i<n; i++){
        int temp=0;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j])
            temp = max(temp, dp[j]);
        }
        dp[i]= temp+1;
        mx=max(mx,dp[i]);
    }
    
    // for(int i=0; i<n; i++){
    //     cout<<dp[i]<<' ';
    // }cout<<'\n';
    
    cout<<mx;
}