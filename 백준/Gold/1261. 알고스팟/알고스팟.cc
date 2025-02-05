#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int board[100][100];
int vis[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int n,m;
    cin>>m>>n;
    
    for(int i=0; i<n; i++){
        string str; cin>>str;
        for(int j=0; j<m; j++){
            board[i][j] = str[j]-'0';
        }
    }
    
    fill(&vis[0][0],&vis[0][0]+100*100, 99999);
    
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0]=0;
    
    while(!q.empty()){
        int nx, ny;
        pair<int,int> cur = q.front(); q.pop();
        
        for(int k=0; k<4; k++){
            nx = cur.X + dx[k];
            ny = cur.Y + dy[k];
            
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            // if(vis[nx][ny]<=vis[cur.X][cur.Y])continue;
            
            int temp = vis[cur.X][cur.Y] + board[nx][ny];
            
            if(temp<vis[nx][ny]){
                if(board[nx][ny] == 0){
                    vis[nx][ny]=vis[cur.X][cur.Y];
                    q.push({nx, ny});
                }else{
                    vis[nx][ny]=vis[cur.X][cur.Y]+1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<vis[i][j]<<' ';
    //     }cout<<'\n';
    // }
    cout<<vis[n-1][m-1];
    
}
