#include <bits/stdc++.h>
using namespace std;

int dp[100]={0, 1, 2};
int fix[41];

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>fix[i];
    }
    fix[m+1]=n+1;
    
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    
    int ans =1;
    for(int i=1; i<=m+1; i++){
        if(dp[fix[i]-fix[i-1]-1] == 0)
            continue;
        ans *= dp[fix[i]-fix[i-1]-1];
    }
    cout<<ans;
}

