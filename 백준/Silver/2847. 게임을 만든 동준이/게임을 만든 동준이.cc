#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int arr[101];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int cnt=0;
    for(int i=n-2; i>=0; i--){
        while(arr[i]>=arr[i+1]){
            arr[i]--;
            cnt++;
        }
    }
    
    cout<<cnt;
}