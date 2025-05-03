#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int layer[260];

int main() {
    int n,m,b;
    cin>>n>>m>>b;
    
    
    int mx=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            mx = max(mx, arr[i][j]);
        }
    }
    
    
    int inven=b;
    int t=0;
    
    for (int k=mx; k>=0; k--){
        int save=inven;
        int tsave=t;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(arr[i][j]<k){
                   inven -= (k-arr[i][j]);
                   t+= k-arr[i][j];
               }
            }
        }
        // cout<<k<<"층 일때 인벤:"<<inven<<" 시간 :"<<t<<'\n';
        
        if(inven>=0){
            layer[k] = t;
        }else{
            layer[k] = INT_MAX;
        }
        
        
        inven=save;
        t=tsave;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(arr[i][j]==k){
                   arr[i][j]--;
                   t+=2;
                   inven++;
               }
            }
        }
    }
    
    
    pair<int, int>ans ={INT_MAX, INT_MAX};
    
    for (int k=mx; k>=0; k--){
        if(ans.first > layer[k]){
            ans.first=layer[k];
            ans.second=k;
        }
        // cout<<layer[k]<<' '<<k<<'\n';
    }
    
    // cout<<"답 :";
    cout<<ans.first<<' '<<ans.second;
    
    
}