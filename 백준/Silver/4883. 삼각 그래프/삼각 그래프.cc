#include <bits/stdc++.h>
using namespace std;

int main() {
    int t=1;
    
    while(1){
        int arr[100001][3];
        int dp[100001][3];
        
        int n;
        cin>>n;
        if(n==0){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        dp[0][1] = arr[0][1];
        dp[0][2] = dp[0][1]+arr[0][2];
        dp[1][0] = dp[0][1]+arr[1][0];
        dp[1][1] = min({dp[0][1], dp[0][2],dp[1][0]}) +arr[1][1];
        dp[1][2] = min({dp[0][1], dp[0][2],dp[1][1]}) +arr[1][2];
        
        for(int i=2; i<n; i++){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + arr[i][0];
            dp[i][1] = min({dp[i-1][0], dp[i-1][1],dp[i-1][2],dp[i][0]}) + arr[i][1];
            dp[i][2] = min({dp[i-1][1], dp[i-1][2], dp[i][1]}) + arr[i][2];
        }
        
        int ans = dp[n-1][1];
        cout<<t<<". "<<ans<<'\n';
        
        t++;
    }
}