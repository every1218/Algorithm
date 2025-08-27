#include <bits/stdc++.h>
using namespace std;

int arr[51];
int dp[51][1001];

int main() {
    int n, s, m;
    cin>>n>>s>>m;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    
    if(s+arr[0] <= m)
        dp[0][s+arr[0]] = 1;
    if(s-arr[0] >= 0)
        dp[0][s-arr[0]] = 1;
    
    
    for(int i=1; i<n; i++){
        for(int j=0; j<1001; j++){
            if(dp[i-1][j]==1 && j+arr[i]<=m){
                dp[i][j+arr[i]]=1;
            }
            if(dp[i-1][j]==1 && j-arr[i]>=0){
                dp[i][j-arr[i]]=1;
            }
        }
    }
    
    int result=-1;
    for(int j=0; j<1001; j++){
        if(dp[n-1][j]==1)
            result = max(result, j);
    }
    
    cout<<result;
    
}