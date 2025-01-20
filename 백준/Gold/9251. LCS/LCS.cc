#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
    string str1, str2;
    cin>>str1>>str2;

    int result =0;    
    for(int i=1; i<=str2.length(); i++){
        for(int j=1; j<=str1.length(); j++){
            if(str1[j-1] == str2[i-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            result = max(result, dp[i][j]);
        }
    }
    
    cout<<result;    
}