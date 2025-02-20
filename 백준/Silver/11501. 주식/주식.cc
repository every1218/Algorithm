#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    int arr[1000000];
    while(t--){
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
        int mx=0;
        long long ans=0;
        for(int i=n-1; i>=0; i--){
            if(mx<arr[i]){
                mx = arr[i];
            }
            ans += mx-arr[i];
        }
        
        cout<<ans<<'\n';
    }
    
}

