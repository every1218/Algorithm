#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    
    int arr[1000000];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+n);
    
    int cut=floor(n*0.15 + 0.5);
    double sum=0;
    int cnt=0;
    
    for(int i=cut; i<n-cut; i++){
        sum+=arr[i];
        cnt++;
    }
    
    cout<<floor(sum/cnt + 0.5);
}