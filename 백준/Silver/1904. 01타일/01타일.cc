#include <bits/stdc++.h>
using namespace std;

int dp[1000001] ={0,1,2};

int main() {
    int n;
    cin>>n;
    
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-1])%15746;
    }
    
    cout<<dp[n];
}