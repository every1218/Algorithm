#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main() {
    int n;
    cin>>n;
    
    fill(dp,dp+100001,INT_MAX);
    
    dp[0]=0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j*j<=i; j++){ 
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    cout<<dp[n];
    
    //dp[i] = min(dp[i], dp[i-j*j]+1);
    
    //ex) dp[13] 
    //dp[13-1] + 1 = d[12] + dp[1] = 4 + 1 = 5
    //dp[13-4] + 1 = d[9] + dp[4] = 1 + 1 = 2 <-당선 
    //dp[13-9] + 1 = d[5] + dp[9] = 2 + 1 = 3
}