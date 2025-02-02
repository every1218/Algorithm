#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};
int board[301][301] ={0};

int main() {
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>board[i][j];
        }
    }
    
    int year=0;
    while(1){
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         cout<<board[i][j]<<' ';
        //     }cout<<'\n';
        // }cout<<'\n';
        
        bool vis[301][301] ={0};
        int temp[301][301] ={0};
        int cnt=0;
        int test=0;
        queue<pair<int, int>>q;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(board[i][j]>0 && vis[i][j]==0){
                    q.push({i, j});
                    vis[i][j]=1;
                    cnt++;
                    
                    while(!q.empty()){
                        pair<int ,int>cur =q.front(); q.pop();
                        for(int i=0; i<4; i++){
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            
                            if(nx<=0 || nx>n || ny<=0 || ny>m) continue;
                            if(board[nx][ny]==0 || vis[nx][ny] == 1) continue;
                            vis[nx][ny]=1;
                            q.push({nx, ny});
                        }
                    }
                }
                if(board[i][j]>0){
                    test=1;
                }
            }
        }
        
        if(cnt>1){
            cout<<year<<'\n';
            return 0;
        }
        if(test==0){
            cout<<0<<'\n';
            return 0;
        }
        
        year++;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(board[i][j]>0){
                    for(int k=0; k<4; k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        
                        if(board[nx][ny] == 0){
                            temp[i][j]++;
                        }
                    }
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                board[i][j] -= temp[i][j];
                if(board[i][j]<0){
                    board[i][j]=0;
                }
            }
        }
    }
}