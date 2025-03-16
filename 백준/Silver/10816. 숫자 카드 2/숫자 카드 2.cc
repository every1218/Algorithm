#include <bits/stdc++.h>
using namespace std;

int arr[500005];
int n;

int up_search(int target){
    int st=0, en=n;
    
    while(st<en){
        int mid = (st+en)/2;
        if(arr[mid]>target){
            en=mid;
        }else 
            st=mid+1;
    }
    return st;
}

int down_search(int target){
    int st=0, en=n;
    
    while(st<en){
        int mid = (st+en)/2;
        if(arr[mid]>=target){
            en=mid;
        }else 
            st=mid+1;
    }
    return st;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int t;
        cin>>t;
        cout<<up_search(t)-down_search(t)<<' ';
    }
}