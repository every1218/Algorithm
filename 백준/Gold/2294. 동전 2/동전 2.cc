#include <bits/stdc++.h>
using namespace std;

int arr[101];
int dp[10001];

int main() {
    int n,k;
    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    
    fill(dp, dp+10001, 100000);
    dp[0]=0;
    
    for(int i=1; i<=n; i++){  
        for(int j=arr[i]; j<=k; j++){ 
            dp[j]=min(dp[j], dp[j-arr[i]]+1);
        }
    }
    
    if(dp[k] == 100000){
        cout<<-1;
    }else{
        cout<<dp[k];
    }
}