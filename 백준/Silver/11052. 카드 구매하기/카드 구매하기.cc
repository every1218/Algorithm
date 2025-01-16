#include <iostream>
using namespace std;

int dp[1001];

int main() {
    int num;
    cin>>num;

    cin>>dp[1];
    for(int i=2; i<=num; i++){
        cin>>dp[i];
        for(int j=1; j<i; j++){
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
    }
    
    cout<<dp[num];
    
}