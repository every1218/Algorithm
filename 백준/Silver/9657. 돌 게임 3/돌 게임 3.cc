#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main() {
    int n;
    cin>>n;
    
    fill(dp, dp+1001, -9999);
    
    dp[1]=1; //SK 승
    dp[2]=2; //CY 승
    dp[3]=1; //SK 승
    dp[4]=1; //SK 승
    
    
    for(int i=5; i<=1000; i++){
        if(dp[i-1]==2 || dp[i-3]==2 || dp[i-4]==2)
            dp[i]=1;
        else
            dp[i]=2;
    }

    if(dp[n]==1)
        cout<<"SK";
    else
        cout<<"CY";
}