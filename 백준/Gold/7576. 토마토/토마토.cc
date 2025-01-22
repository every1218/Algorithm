#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int board[1000][1000];
int vis[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int n,m;
    cin>>m>>n;
    
    queue<pair<int,int>>q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]==0) //안 익은 토마토
                vis[i][j] = -2;
            else if(board[i][j]==1){ //익은 토마토
                vis[i][j] = 0;
                q.push({i,j});
            }else{ //벽
                vis[i][j] = -1;
            }
        }
    }
    
    while(!q.empty()){
        int nx, ny;
        pair<int,int> cur = q.front(); q.pop();
        
        for(int k=0; k<4; k++){
            nx = cur.X + dx[k];
            ny = cur.Y + dy[k];
            
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(vis[nx][ny] != -2) continue;
            
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
            q.push({nx, ny});
        }
    }
    
    int temp=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==0 &&vis[i][j]==-2) {cout<<-1<<'\n'; return 0;}
            // cout<<vis[i][j]<<' ';
            temp = max(temp, vis[i][j]);
        }//cout<<'\n';
    }
    cout<<temp;
}
