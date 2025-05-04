#include <bits/stdc++.h>
using namespace std;

int dp[50005];

int main() {
    int n;
    cin>>n;
    
    
    fill(dp, dp+50005, 9);
    
    for(int i=1; i<=223; i++){
        dp[i*i]=1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i/2; j++){
            dp[i] = min(dp[i], dp[j]+dp[i-j]);
        }
    }
    
    cout<<dp[n]<<'\n';
    
    // for(int i=1; i<=n; i++){
    //     cout<<"dp"<<i<<" : "<<dp[i]<<'\n';
    // }
    
    
}