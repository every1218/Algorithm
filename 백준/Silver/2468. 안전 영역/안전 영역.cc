#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[101][101];
int dx[4] ={1, 0, -1, 0};
int dy[4] ={0, 1, 0, -1};

int main() {
    int n;
    cin>>n;
    
    int mx =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>board[i][j];
            mx = max(board[i][j], mx);
        }
    }

    int result =0;
    int k=5;
    for(int k=0; k<=mx; k++){
        int cnt =0;
        int vis[101][101] = {0};
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(board[i][j] >= k && !vis[i][j]){
                    cnt++;
                    vis[i][j] = 1;
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    
                    while(!q.empty()){
                        pair<int, int>cur= q.front(); q.pop();
                        for(int i=0; i<4; i++){
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            
                            if(nx<=0 || nx>n || ny<=0 || ny>n) continue;
                            if(vis[nx][ny] || board[nx][ny]<k) continue;
                            
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        result = max(result, cnt);
    }
    cout<<result;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<vis[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
}