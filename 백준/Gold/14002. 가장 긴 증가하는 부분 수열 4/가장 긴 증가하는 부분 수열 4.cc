#include <iostream>
#include <stack>

using namespace std;

int arr[1001];
int dp[1001];
int idx[1001];

int main(){
    int num;
    cin>>num;
    
    for(int i=1; i<=num; i++){
        cin>>arr[i];
    }
    
    for(int i=1; i<=num; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j]){
                if (dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
					idx[i] = j;
				}
            }
        }
    }
    
    int max =0, max_idx = 0;
    for(int i=1; i<=num; i++){
        if(max < dp[i]){
            max = dp[i];
            max_idx = i;
        }
    }
    cout<<max<<endl;
    
    stack<int>s;
    for(int i=max_idx; i>0;){
        s.push(arr[i]);
        i = idx[i];
    }
    
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    
}