#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+n);
    
    int num=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            num+=arr[j];
        }
    }
    
    cout<<num;
    
}

// 3 1 4 3 2
// 3 4 8 11 13 = 39

// 1 2 3 3 4
// 1 3 6 9 13 = 32
