#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

char board[1001][1001];
int vis[1001][1001];
int fire[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int n,m;
    cin>>n>>m;
    
    queue<pair<int,int>>q,f;
    
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        for(int j=0; j<m; j++){
            board[i][j] = str[j];
            if(board[i][j] == 'J'){
                q.push({i,j});
                vis[i][j]=1;
                fire[i][j]=9999;
            }else if(board[i][j] == 'F'){
                f.push({i,j});
                fire[i][j]=1;
            }else if(board[i][j] == '.'){
                vis[i][j] = -1;
                fire[i][j] = 9999;
            }
        }
    }
    
    while(!f.empty()){
        int nx, ny;
        pair<int,int> cur = f.front(); f.pop();
        
        for(int k=0; k<4; k++){
            nx = cur.X + dx[k];
            ny = cur.Y + dy[k];
            
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(board[nx][ny] == '#' || fire[nx][ny] != 9999) continue;
            
            fire[nx][ny]=fire[cur.X][cur.Y]+1;
            f.push({nx, ny});
        }
    }
    
    while(!q.empty()){
        int nx, ny;
        pair<int,int> cur = q.front(); q.pop();
        
        for(int k=0; k<4; k++){
            nx = cur.X + dx[k];
            ny = cur.Y + dy[k];
            
            if(nx<0 || ny<0 || nx>=n || ny>=m) {
                cout<<vis[cur.X][cur.Y]<<'\n';
                return 0;
            }
            if(board[nx][ny] == '#' || vis[nx][ny] != -1) continue;
            if(vis[cur.X][cur.Y]+1 >= fire[nx][ny]) continue;
            
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
            q.push({nx, ny});
        }
    }
    
    cout<<"IMPOSSIBLE";
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<fire[i][j]<<' ';
    //     }cout<<'\n';
    // }
    // cout<<'\n';
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<vis[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
}
