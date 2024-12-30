#include <iostream>
using namespace std;

int dp[1000][10];

int main() {
    int num;
    cin>>num;
    
    for(int i=0; i<=9; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=num; i++){
        for(int j=0; j<=9; j++){
            for(int k=j; k<=9; k++){
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;
            }
        }
    }
    
    int result =0;
    for(int i=0; i<=9; i++){
        result = (result + dp[num][i]) % 10007;
    }
    cout<<result<<endl;
}
