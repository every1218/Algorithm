#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int arr[2][100000]={0};
        int dp[2][100000]={0};
        
        int n;
        cin>>n;
        
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
                if(j==0) dp[i][j] = arr[i][j];
            }
        }
        dp[0][1] = arr[1][0] + arr[0][1];
        dp[1][1] = arr[0][0] + arr[1][1];
        
        for(int j=2; j<n; j++){
            dp[0][j] = max({dp[0][j-2], dp[1][j-2], dp[1][j-1]}) + arr[0][j];
            dp[1][j] = max({dp[0][j-2], dp[1][j-2], dp[0][j-1]}) + arr[1][j];
        }
        
        cout<<max(dp[0][n-1], dp[1][n-1])<<'\n';
        
        // for(int i=0; i<2; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<dp[i][j]<<' ';            
        //     }cout<<'\n';
        // }
    }
}