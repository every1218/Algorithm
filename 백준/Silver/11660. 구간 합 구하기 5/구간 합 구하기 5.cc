#include <iostream>
using namespace std;

int board[1025][1025];
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n ;j++){
            cin>>board[i][j];
        }
    }
    
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n ;j++){
            dp[i][j] = board[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    
    
    // for(int i=1; i<=n ;i++){
    //     for(int j=1; j<=n ;j++){
    //         cout<<dp[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
    
    while(m--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]<<'\n';
    }
}
