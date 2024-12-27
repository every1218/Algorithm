#include <bits/stdc++.h>
using namespace std;

int dp[1001][31];

int main() {
    int t,w;
    cin>>t>>w;
    
    for(int i=1; i<=t; i++){
        int jadu;
        cin>>jadu;
        
        dp[i][0] = dp[i-1][0];
        for(int j=1; j<=w; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
        }
        
        if(jadu==1){ //1번나무에서 떨어졌을 때
            for(int j=0; j<=w; j+=2) dp[i][j]++;
        }else{ //2번나무에서 떨어졌을 때
            for(int j=1; j<=w; j+=2) dp[i][j]++;
        }
    }
    
    int ans=0;
    for(int j=0; j<=w; j++){
        ans = max(ans, dp[t][j]);
    }
    cout<<ans;
}
