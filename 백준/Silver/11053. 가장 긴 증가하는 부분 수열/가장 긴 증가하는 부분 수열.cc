#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    int num;
    cin>>num;
    
    for(int i=1; i<=num; i++){
        cin>>arr[i];
    }
    
    for(int i=1; i<=num; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    int result=0;
    for(int i=1; i<=num; i++){
        result = max(result, dp[i]);
    }
    cout<<result;
}
