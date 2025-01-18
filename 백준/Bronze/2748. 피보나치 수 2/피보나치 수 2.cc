#include <bits/stdc++.h>
using namespace std;

long long dp[91] ={0, 1,};

int main() {
    int n;
    cin>>n;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}
