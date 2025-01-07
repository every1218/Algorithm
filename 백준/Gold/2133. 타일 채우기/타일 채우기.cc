#include <bits/stdc++.h>
using namespace std;

int dp[31] ={1, 0, 3, 0, 11};

int main() {
    int n;
    cin>>n;
    
    if(n%2 ==1){
        cout<<0;
        return 0;
    }
    
    for(int i=6; i<=n; i+=2){
        dp[i] = dp[i-2]*3; 
        for(int j=0; j<=i-4; j+=2){ 
            dp[i] += dp[j]*2;
        }
    }
    
    cout<<dp[n];
}