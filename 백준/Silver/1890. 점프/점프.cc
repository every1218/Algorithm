#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int board[101][101];
    long long dp[101][101];
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    
    dp[0][0]=1;
    
    //↓ 이 코드 맞는지 한번더 체크. (지금 이론상으론 맞는 거 같아. 구현 실수같음)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 기준보다 위쪽인 애들 체크
            for(int a=0; a<i; a++){
                //만약) 위쪽인 애들의 x값 + 점프뛸수있는 거리 = 기준의 x 위치
                // -> 기준 dp에 값 더하기
                if(board[a][j]+a == i){
                    dp[i][j] += dp[a][j];
                }
            }
            
            // 기준보다 왼쪽인 애들 체크
            for(int b=0; b<j; b++){
                //만약) 왼쪽인 애들의 y값 + 점프뛸수있는 거리 = 기준의 y 위치
                // -> 기준 dp에 값 더하기
                if(board[i][b]+b == j){
                    dp[i][j] += dp[i][b];
                }
            }
        }
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<dp[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
    cout<<dp[n-1][n-1];
}