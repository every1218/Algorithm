#include <bits/stdc++.h>
using namespace std;

int t[16];
int p[16];
int dp[16];

int main() {
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>t[i]>>p[i];
    }
    
    for(int i=1; i<=n+1; i++){
        dp[i] = max(dp[i], dp[i-1]);
        if(i+t[i]<=n+1){
            dp[i+t[i]]=max(dp[i+t[i]], dp[i]+p[i]);
        }
    }
    
    cout<<dp[n+1];
}