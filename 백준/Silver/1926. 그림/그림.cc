#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int board[501][501];
int vis[501][501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int n,m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    
    queue<pair<int,int>>q;
    
    int cnt=0;
    int mx=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 1 && vis[i][j]==0){
                int temp=1;
                cnt++;
                vis[i][j]=1;
                q.push({i,j});
                
                while(!q.empty()){
                    int nx, ny;
                    pair<int,int> cur = q.front(); q.pop();
                    
                    for(int k=0; k<4; k++){
                        nx = cur.X + dx[k];
                        ny = cur.Y + dy[k];
                        
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny]==1) continue;
                        
                        vis[nx][ny]=1;
                        q.push({nx, ny});
                        temp++;
                    }
                }
                mx=max(mx, temp);
            }
        }
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<vis[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
    cout<<cnt<<'\n';
    cout<<mx<<'\n';
}


