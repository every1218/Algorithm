#include <bits/stdc++.h>
using namespace std;


struct State{
    int imo, clp, t;
};

int main() {
    int s;
    cin>>s;
    
    bool vis[1001][1001];
    
    queue<State>q;
    q.push({1,0,0});
    vis[1][0]=true;
    
    while(!q.empty()){
        State cur = q.front(); q.pop();
        
        if(cur.imo ==s){
            cout<<cur.t<<'\n';
            return 0;
        }
        
        //1.복사
        if(!vis[cur.imo][cur.imo]){
            vis[cur.imo][cur.clp]=true;
            q.push({cur.imo, cur.imo, cur.t+1});
        }
        
        //2.붙여넣기
        if(cur.clp>0 && cur.imo+cur.clp<=1000 && !vis[cur.imo+cur.clp][cur.clp]){
            vis[cur.imo][cur.clp]=true;
            q.push({cur.imo+cur.clp, cur.clp, cur.t+1});
        }
        
        //3.삭제
        if(cur.imo>1 && !vis[cur.imo-1][cur.clp]){
            vis[cur.imo-1][cur.clp]=true;
            q.push({cur.imo-1, cur.clp, cur.t+1});
        }
    }
    
}

