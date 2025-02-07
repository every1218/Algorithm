#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int start[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>start[i][j];
        }
    }
    
    int ans=0;
    
    for(int k=1; k<=100; k++){
        int board[101][101] ={0};
        int vis[101][101] ={0};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(start[i][j]<k) board[i][j]=1;
                else board[i][j]=0;
            }
        }
        
        queue<pair<int,int>>q;
        int temp=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==0 && vis[i][j]==0){
                    temp++;
                    q.push({i,j});
                    vis[i][j]=1; 
                    
                    while(!q.empty()){
                        int nx, ny;
                        pair<int,int> cur = q.front(); q.pop();
                        
                        for(int k=0; k<4; k++){
                            nx = cur.X + dx[k];
                            ny = cur.Y + dy[k];
                            
                            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                            if(board[nx][ny] == 1 || vis[nx][ny] == 1) continue;
                            
                            vis[nx][ny]=1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        ans = max(ans, temp);
    }
    cout<<ans;
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<board[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
}
