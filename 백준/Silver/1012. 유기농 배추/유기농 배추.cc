#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int board[51][51] ={0};
        int vis[51][51] ={0};
        queue<pair<int, int>>q;
        int m,n,k; 
        cin>>m>>n>>k; //m=10 n=8 
        
        int cnt =0;
        for(int i=0; i<k; i++){
            int a, b;
            cin>>a>>b;
            board[b][a] = 1;
        }
    
        for(int z=0; z<n; z++){
            for(int j=0; j<m; j++){
                if(board[z][j] ==1 && vis[z][j]==0){
                    q.push({z,j});
                    cnt++;
                    while(!q.empty()){
                        pair<int, int>cur =q.front(); q.pop();
                        
                        for(int i=0; i<4; i++){
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            if(nx<0 || nx>n || ny<0 || ny>m) continue;
                            if(board[nx][ny]==0 ||vis[nx][ny]==1) continue;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        
        cout<<cnt<<'\n';
    }
}