#include <bits/stdc++.h>
using namespace std;

int arr[2001];
bool dp[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        dp[i][i] = 1;
    }

    for(int i=n-1; i>0; i--){
        for(int j=i+1; j<=n; j++){
            if(arr[i] == arr[j]) {
                if(dp[i+1][j-1] || i == j-1)
                    dp[i][j]=1;
            }
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<dp[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
    int m;
    cin>>m;
    while(m--) {
        int s, e;
        cin>>s>>e;
        cout<<dp[s][e]<<'\n';
    }
}