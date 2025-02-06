#include <bits/stdc++.h>
using namespace std;

int dp[10001][3] = {{0,0,0}, {1,0,0},{1,1,0},{1,1,1}};

int main() {
    int n;
    cin>>n;
    
    for(int i=4; i<10001; i++){
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-2][0] + dp[i-2][1];
        dp[i][2] = dp[i-3][0] + dp[i-3][1] + dp[i-3][2];
        
        // cout<<i<<" : "<<dp[i][0]+dp[i][1]+dp[i][2]<<'\n';
    }
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        cout<<dp[temp][0]+dp[temp][1]+dp[temp][2]<<'\n';
    }

}