#include <iostream>
using namespace std;

int dp[1000001] ={0};

int main() {
    int num;
    cin>>num;
    
    for(int i=2; i<=num; i++){
        dp[i] = dp[i-1] + 1;
        
        if(i%2 == 0){
            int temp = dp[i/2] +1;
            dp[i] = min(dp[i], temp);
        }
        
        if(i%3 == 0){
            int temp = dp[i/3] +1;
            dp[i] = min(dp[i], temp);
        }
    }
    
    
    cout<<dp[num];
}