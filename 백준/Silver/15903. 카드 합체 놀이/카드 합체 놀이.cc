#include <bits/stdc++.h>
using namespace std;

//정렬 or 우선순위 큐 
//제일 작은 거 2장 골라서 다한다음 바꾸면 되잖아

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long arr[1000001];
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){ 
        cin>>arr[i];
    }
    
    while(m--){
        sort(arr, arr+n);
        
        long long total = arr[0] + arr[1];
        arr[0] = total;
        arr[1] = total;
    }
    
    long long ans=0;
    for(int i=0; i<n; i++){ 
        ans += arr[i];
    }
    
    cout<<ans;
}

