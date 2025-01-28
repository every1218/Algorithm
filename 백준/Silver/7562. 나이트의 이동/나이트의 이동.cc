#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int dx[8] = {-2,-2,-1,1,2,2,1,-1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int vis[301][301]={0};
        
        int i;
        cin>>i;
        
        int stx=0, sty=0;
        int edx=0, edy=0;
        
        cin>>stx>>sty;
        cin>>edx>>edy;
        
        if(stx==edx && sty==edy) {
            cout<<0<<'\n';
            continue;
        }
        
        queue<pair<int,int>>q;
        q.push({stx, sty});
        vis[stx][sty]=0;
        
        while(!q.empty()){
            int nx, ny;
            pair<int,int> cur = q.front(); q.pop();
            
            for(int k=0; k<8; k++){
                nx = cur.X + dx[k];
                ny = cur.Y + dy[k];
                
                if(nx<0 || ny<0 || nx>=i || ny>=i) continue;
                if(vis[nx][ny] != 0) continue;
                
                vis[nx][ny]=vis[cur.X][cur.Y]+1;
                q.push({nx, ny});
            }
        }
        
        cout<<vis[edx][edy]<<'\n';
    }
}
