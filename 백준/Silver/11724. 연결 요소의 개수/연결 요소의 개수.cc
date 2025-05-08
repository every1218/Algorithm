#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    
    if(m==0){ cout<<n; return 0;}
    
    vector<int>v[n+1];
    
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // for(int i=1; i<=n; i++){
    //     cout<<i<<" : ";
    //     for(int j:v[i]){
    //         cout<<j<<' ';    
    //     }cout<<'\n';
    // }
    
    
    bool check[1005] ={false};
    int cnt=0;
    
    queue<int>q;
    for(int i=1; i<=n; i++){
        if(check[i]==false) {
            cnt++;
            q.push(i);
        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int j:v[cur]){
                if(check[j]==true) continue;
                check[j]=true;
                q.push(j);
            }
        }
        
    }
    cout<<cnt;
}