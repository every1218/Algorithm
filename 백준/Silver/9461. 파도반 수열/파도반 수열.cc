#include <bits/stdc++.h>
using namespace std;

long long dp[101] = {0, 1, 1, 1, 2, 2 ,3, 4, 5};

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        for(int i=9; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-5];
            // cout<<"dp["<<i<<"] : "<<dp[i]<<'\n';
        }
        cout<<dp[n]<<'\n';
    }
}