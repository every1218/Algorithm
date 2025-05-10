#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, one;
    cin>>n>>m>>one;
    
    // if(n==1){cout<<0; return 0;}
    
    vector<int>v[n+1];
    
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    
    bool check[10005] ={0};
    stack<int>s;
    s.push(one);
    vector<int>dfs;
    
    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        if (check[cur]) continue;
        check[cur] = true;
        dfs.push_back(cur);

        for (auto it = v[cur].rbegin(); it != v[cur].rend(); it++) {
            if (!check[*it]) {
                s.push(*it);
            }
        }
    }
    
    for(int i:dfs){
        cout<<i<<' ';
    }cout<<'\n';
    
    //-------------------------------------------------------------
    
    
    fill(check, check+10005,0);
    queue<int>q;
    check[one]=true;
    q.push(one);
    vector<int>bfs;
    bfs.push_back(one);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int j:v[cur]){
            if(check[j]==true) continue;
            check[j]=true;
            bfs.push_back(j);
            q.push(j);
        }
    }
    
    for(int i:bfs){
        cout<<i<<' ';
    }
        
}