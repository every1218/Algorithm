#include <iostream>
using namespace std;

int a[1001];
int dp[1001];

int main() {
    int num;
    cin>>num;
    
    for(int i=1; i<=num; i++){
        cin>>a[i];
    }
    
    for(int i=1; i<=num; i++){
        dp[i]=a[i];
        for(int j=1; j<=i; j++){
            if(a[i]>a[j]){
                dp[i] = max(dp[i], dp[j]+a[i]);
            }
        }
    }
    
    int result =0;
    for(int i=1; i<=num; i++){
        result = max(result, dp[i]);
    }
    
    cout<<result;
    
    
}