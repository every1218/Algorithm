#include <bits/stdc++.h>
using namespace std;

long long dp[1000001]={0,1};

int main() {
    int n;
    cin>>n;
    
    if(n==0){
        cout<<0<<'\n'<<0<<'\n';
        return 0;
    }
    
    int temp =0;
    if(n<0){
        if(n%2 ==0)
            cout<<-1<<'\n';
        else
            cout<<1<<'\n';
        temp = n * -1;
    }else{
        cout<<1<<'\n';
        temp = n;
    }
    
    for(int i=2; i<=temp; i++){
        dp[i] = (dp[i-2] + dp[i-1])%1000000000;
    }

    cout<<dp[temp]<<'\n'; 
    // 0 -1 -2 -3 -4 -5 -6 -7
    // 0  1 -1  2 -3  5 -8 13 
}
