#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    int mx=0;
    for(int i=0; i<n; i++){ 
        arr[i] = arr[i]*(n-i);
        mx = max(mx, arr[i]);
    }
    cout<<mx<<'\n';
    
}