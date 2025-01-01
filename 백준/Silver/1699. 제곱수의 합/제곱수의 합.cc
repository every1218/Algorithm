#include <iostream>
#include <cmath>
using namespace std;

int dp[100001] ={0, 1};
int main() {
    int num;
    cin>>num;
    
    for(int i=1; i<=num; i++){
        dp[i] = i;
        if(sqrt(i) - (int)(sqrt(i)) == 0){
            dp[i] = 1;
        }
        else{
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
    }
    
    cout<<dp[num];
}


// dp[1] = 1
// dp[2] = 2
// dp[3] = 3
// dp[4] = 1
// dp[5] = 2
// dp[6] = 3
// dp[7] = 4
// dp[8] = 2 
// dp[9] = 1 

// 7 = 2^2 + 1+1+1

// 11 = 3^2 +1 + 1

// 126 = 81 + 36 + 9
//       9^2 + 6^2 + 3^2
