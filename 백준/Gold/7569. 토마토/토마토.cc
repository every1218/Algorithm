#include <bits/stdc++.h>
using namespace std;

int board[100][100][100];
int vis[100][100][100];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};


int main() {
    int n,m,h;
    cin>>m>>n>>h;
    
    queue<tuple<int,int,int>>q;
    
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>board[k][i][j];
                if(board[k][i][j]==0) //안 익은 토마토
                    vis[k][i][j] = -2;
                else if(board[k][i][j]==1){ //익은 토마토
                    vis[k][i][j] = 0;
                    q.push({k,i,j});
                }else{ //벽
                    vis[k][i][j] = -1;
                }
            }
        }
    }
    
    while(!q.empty()){
        int nx, ny, nz;
        tuple<int,int,int> cur = q.front(); q.pop();
        
        for(int k=0; k<6; k++){
            nz = get<0>(cur) + dz[k];
            nx = get<1>(cur) + dx[k];
            ny = get<2>(cur) + dy[k];
            
            
            if(nx<0 || ny<0 ||nz<0 || nx>=n || ny>=m|| nz>=h) continue;
            if(vis[nz][nx][ny] != -2) continue;
            
            vis[nz][nx][ny]=vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            q.push({nz, nx, ny});
        }
    }
    
    int temp=0;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[k][i][j]==0 &&vis[k][i][j]==-2) {cout<<-1<<'\n'; return 0;}
                // cout<<vis[k][i][j]<<' ';
                temp = max(temp, vis[k][i][j]);
            }//cout<<'\n';
        } //cout<<'\n';
    }
    cout<<temp;
}
