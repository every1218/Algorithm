#include <bits/stdc++.h>
using namespace std;

int dp[101][11] ={{0},{0,1,1,1,1,1,1,1,1,1}};
//dp[i][j] : i자리수의 j로 끊나는 게 몇 갠지

int main() {
    int n;
    cin>>n;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    
    
    int ans=0;
    for(int j=0; j<=9; j++){
        ans = (ans+dp[n][j])%1000000000;
    }
    cout<<ans;
}