#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    
    if(n==1){cout<<0; return 0;}
    
    vector<int>v[n+1];
    
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    bool check[105] ={0};
    int cnt=0;
    
    queue<int>q;
    check[1]=true;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int j:v[cur]){
            if(check[j]==true) continue;
            check[j]=true;
            q.push(j);
            cnt++;
        }
    }
        
    cout<<cnt;
}