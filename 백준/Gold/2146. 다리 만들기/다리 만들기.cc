#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};
bool board[101][101] ={0};
int island[101][101] ={0};

int main() {
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>board[i][j];
        }
    }
    
    int cnt=0;
    queue<pair<int, int>>q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j]==1 && island[i][j]==0){
                q.push({i, j});
                island[i][j]=++cnt;
                
                while(!q.empty()){
                    pair<int ,int>cur =q.front(); q.pop();
                    for(int i=0; i<4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        
                        if(nx<=0 || nx>n || ny<=0 || ny>n) continue;
                        if(board[nx][ny]==0 || island[nx][ny] != 0) continue;
                        island[nx][ny]=cnt;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    
    int ans =1000;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int vis[101][101] ={0};
            if(island[i][j]>0){
                int dist=1000;
                
                q.push({i, j});
                
                while(!q.empty()){
                    pair<int ,int>cur =q.front(); q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        
                        if(nx<=0 || nx>n || ny<=0 || ny>n) continue;
                        if(island[i][j] == island[nx][ny] || vis[nx][ny] != 0) continue;
                        if(island[nx][ny]>0){
                            dist = min(dist, vis[cur.X][cur.Y]);
                        }
                        vis[nx][ny]= vis[cur.X][cur.Y]+1;
                        q.push({nx, ny});
                    }
                }
                ans = min(ans, dist);
            }
        }
    }
    
    cout<<ans;
    
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<vis[i][j]<<' ';
    //     }cout<<'\n';
    // }
}